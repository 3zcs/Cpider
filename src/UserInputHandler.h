#include<string>

class UserInputHandler{
    public:
    UserInputHandler(int , char* const * );
    ~UserInputHandler();

    // print command-line options 
    void printUsage();
    // with error
    void printUsage(std::string);
    
    std::string getUrl();
    std::string getPath();
    std::string getDomain();
    int getDepth();

    private:
    std::string url;
    std::string path = "";
    std::string domain;
    int depth = 1;
    bool isHttps = false;

    // add Protocol to the link
    void addProtocol();
};