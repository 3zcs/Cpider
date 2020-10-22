#include "Helper.h"

std::promise<std::string> prms;
std::future<std::string> ftr = prms.get_future();
std::vector<std::future<void>> futures;

std::mutex mutexCheck, mutexInsert, mtx;
std::condition_variable _cond;
bool ready = false;


void start(std::string url, std::string path)
{
    if (!path.empty())
    {
        if (path.find("http") == 0 || path.find("https") == 0)
        {
            url = path;
        }
        else
        {
            url = url + path;
        }
    }

    // request
    Requester requester(url.c_str());

    // parse
    Parser parser(requester.getBuffer(), url);

    if (!parser.getLinks().empty())
    {
        std::lock_guard<std::mutex> lck(mutexInsert);
        std::vector<Link> tmp;
        tmp = parser.getLinks();

        for (Link link : tmp)
        {
            if (linksMap.count(link.getPath()) == 0)
                linksMap.insert(std::pair<std::string, Link>(link.getPath(), link));
        }
    }
}

void writeToFile(std::promise<std::string> &&prms, ResultHandler* handler, std::string domain)
{
    if(handler->writeToFile(domain)){
        prms.set_value(fileLocation+ domain+txt);
    }else {
        prms.set_value(errorfile);
    }

    //write after finish printing
    std::unique_lock<std::mutex> lck(mtx);
    while (!ready) _cond.wait(lck);

    // print file name
    std::cout << doubleNewLine<<ftr.get() << doubleNewLine<<std::endl;
}

void print(ResultHandler* handler)
{
    std::unique_lock<std::mutex> lck(mtx);
    ready = handler->print();
    _cond.notify_all();
}

void parseLikes(int depth, std::string url)
{
    for (int i = 0; i < depth; i++)
    {
        for (std::map<std::string, Link>::iterator i = linksMap.begin(); i != linksMap.end(); i++)
        {
            std::lock_guard<std::mutex> lck(mutexCheck);
            if ((*i).second.isInternal() && !(*i).second.isVisted())
            {
                (*i).second.setVisited(true);
                futures.emplace_back(std::async(start, url, (*i).second.getPath()));
            }
        }
    }

    // join all thread
    for (auto &e : futures)
    {
        e.wait();
    }
}

void handleResult(std::string domain){
    std::unique_ptr<ResultHandler> Rhandler(new CustomResultHandler(linksMap));
    
    // start thread and pass promise as argument
    std::thread twrite(writeToFile, std::move(prms), Rhandler.get(),domain);
    std::thread tprint(print, Rhandler.get());
    // thread barrier
    twrite.join();
    tprint.join();
}