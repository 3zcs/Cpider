#include<string>
#include<cstring>
#include<stdlib.h>
#include <string.h>
#ifndef LINK_H
#define LINK_H

class Link {
    public:
    Link(std::string, bool); // constructor
    ~Link();                // destructor
    Link(Link const&);     // copy constructor
    Link(Link&&) noexcept;         // move constructor
    Link& operator=(Link const &);  // assignment operator
    Link& operator=(Link&&) noexcept;    //  move assignment operator
    void swap(Link &lhs, Link &rhs) noexcept;
    // setters & getters
    void setPath(std::string);
    std::string getPath()const;
    void setInternal(bool);
    bool isInternal()const;
    void setVisited(bool);
    bool isVisted()const;

    private:
        char * _path;
        bool _internal;
        bool _visited = false;
        
};

#endif
