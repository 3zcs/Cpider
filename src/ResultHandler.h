#include<map>
#include<string>
#include "Link.h"

class ResultHandler
{
protected:
    std::map<std::string,Link> _linksMap;
public:
    ResultHandler(std::map<std::string,Link>);
    ~ResultHandler();
    virtual bool print() = 0;
    virtual bool writeToFile(std::string)= 0;
};

class CustomResultHandler: public ResultHandler
{
private:

public:
    CustomResultHandler(std::map<std::string,Link>);
    ~CustomResultHandler();
    // override virtual function and print the result
    bool print();

    // override virtual function and write the result to file
    // with name of the website 
    bool writeToFile(std::string);
};


