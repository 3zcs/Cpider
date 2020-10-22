#include<string>
#include<vector>
#include "Link.h"

class Parser{
    public:
        Parser(std::string, std::string);
        ~Parser();
        std::vector<Link> getLinks();
    private:
        std::vector<Link> _links;
        std::string _domain;
        void parse(std::string);

        // is Internal or External
        bool isIn(std::string);

        // helper functions to trim string
        std::string ltrim(const std::string& s);
        std::string rtrim(const std::string& s);
        std::string trim(const std::string& s);

        // parse Property (e.g href, src..)
        void parseProperty(std::string&, std::string);

        // parse Protocol (e.g http, https..)
        void parseProtocol(std::string& , std::string );
        void addLink(std::string);
};
