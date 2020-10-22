#include "Requester.h"

Requester::Requester(const char* url): _url(url){
    Request();
}

Requester::~Requester(){}

std::string Requester::getBuffer(){
    return buffer;
}

 size_t Requester::WriteCallback(char *contents, size_t size, size_t nmemb, void *userp)
{
    ((std::string*)userp)->append((char*)contents, size * nmemb);
    return size * nmemb;
}

void Requester::Request(){
    if(_url){
        curl_global_init(CURL_GLOBAL_ALL);
        CURL* easyhandle(curl_easy_init());
        curl_easy_setopt(easyhandle, CURLOPT_URL, _url);
        curl_easy_setopt(easyhandle, CURLOPT_VERBOSE, 1L);
        curl_easy_setopt(easyhandle, CURLOPT_WRITEFUNCTION, WriteCallback);
        curl_easy_setopt(easyhandle, CURLOPT_WRITEDATA, &buffer);
        curl_easy_perform(easyhandle);
    }
};


const char* Requester::getUrl(){
    return _url;
}
