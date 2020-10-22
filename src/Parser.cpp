#include <sstream>
#include<iostream>

#include "Parser.h"
#include "Constants.h"

Parser::Parser(std::string html, std::string domain):_domain(domain)
{
    parse(html);
}

Parser::~Parser() {}

std::vector<Link> Parser::getLinks()
{
    return _links;
}

void Parser::parseProperty(std::string &html, std::string property)
{
    size_t pos = html.find(property);
    html.erase(pos, property.length());

    pos = html.find(equal);
    if (pos != std::string::npos)
    {
        html.erase(pos, 1);
        // after remove property= we trim the content
        html = trim(html);
        if (html[0] == singleQuote)
        {
            html.erase(0, 1);
            pos = html.find(singleQuote);
            if (pos != std::string::npos){
                html.erase(pos, html.length() - pos);
            }else if(html.find(space) != std::string::npos){
                // if the quote not closeed and followed by space
                pos = html.find(space);
                html.erase(pos, html.length() - pos);
            } else if(html.find(angle) != std::string::npos){
                // if the quote not closed and followed by >
                pos = html.find(angle);
                html.erase(pos, html.length() - pos);
            }
        }
        else if (html[0] == doubleQuote)
        {
            html.erase(0, 1);
            pos = html.find(doubleQuote);
            if (pos != std::string::npos){
                html.erase(pos, html.length() - pos);
            }else if(html.find(space) != std::string::npos){
                // if the quote not closeed and followed by space
                pos = html.find(space);
                html.erase(pos, html.length() - pos);
            } else if(html.find(angle) != std::string::npos){
                // if the quote not closed and followed by >
                pos = html.find(angle);
                html.erase(pos, html.length() - pos);
            }

        }

    }
}

void Parser::parseProtocol(std::string &html, std::string protocol){
        auto pos = html.find(protocol);
        html.erase(0, pos);

        size_t posd = html.find(doubleQuote);
        size_t poss = html.find(singleQuote);

        if (posd != std::string::npos && poss != std::string::npos)
        {
            if (posd < poss)
            {
                html = html.substr(0, posd);
            }
            else
            {
                html = html.substr(0, poss);
            }
        }
        else if (posd != std::string::npos)
        {
           html = html.substr(0, posd);
        }
        else if (poss != std::string::npos)
        {
            html = html.substr(0, poss);
        }
}

void Parser::parse(std::string html)
{

    // stringstream class check1
    std::stringstream htmlAsString(html);

    std::string htmlPart;

    // Tokenizing w.r.t. space ' '
    while (getline(htmlAsString, htmlPart, space))
    {

        if (htmlPart.find(href) == 0)
        {
             parseProperty(htmlPart, href);
        }
        else if (htmlPart.find(src) == 0){
             parseProperty(htmlPart, src);
        }
        else if (htmlPart.find(https) != std::string::npos)
        {
            parseProtocol(htmlPart,https);
        }
        else if (htmlPart.find(http) != std::string::npos)
        {
            parseProtocol(htmlPart,http);
        } else
        {
            continue;
        }


        if(!htmlPart.empty()) 
            addLink(htmlPart);

    }
}

std::string Parser::ltrim(const std::string &s)
{
    size_t start = s.find_first_not_of(WHITESPACE);
    return (start == std::string::npos) ? "" : s.substr(start);
}

std::string Parser::rtrim(const std::string &s)
{
    size_t end = s.find_last_not_of(WHITESPACE);
    return (end == std::string::npos) ? "" : s.substr(0, end + 1);
}

std::string Parser::trim(const std::string &s)
{
    return rtrim(ltrim(s));
}

bool Parser::isIn(std::string path)
{
    if(path.find("/")==0){
        return true;
    } else if (path.find(_domain) != std::string::npos)
    {
        return true;
    }else if(path.find(http) == std::string::npos && path.find(https) == std::string::npos )
    {
        return true;
    }

    return false;
}

void Parser::addLink(std::string url){
    _links.push_back(Link(url, isIn(url)));
}
