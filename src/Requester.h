#include <curl/curl.h>
#include <memory>
#include <bits/stdc++.h>
class Requester {
    public:
        Requester(const char *);
        ~Requester();

        // get response 
        std::string getBuffer();
        const char* getUrl();

        // perform the request 
        void Request();

    private:
        const char* _url;
        std::string buffer;

        // allocate space to and write the responce 
        static size_t WriteCallback(char *contents, size_t size, size_t nmemb, void *userp);
};