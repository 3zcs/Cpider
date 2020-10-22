#include<string>
#ifndef CONSTANTS_H
#define CONSTANTS_H

#define BLUE    "\033[34m"
#define GREEN   "\033[32m"
#define RESET   "\033[0m"

extern const std::string USAGE;
extern const std::string missingLink;
extern const std::string https;
extern const std::string http;
extern const std::string externalLinks;
extern const std::string internalLinks;
extern const std::string doubleNewLine;
extern const std::string plusSign;
extern const std::string txt;
extern const std::string href;
extern const std::string src;
extern const std::string equal;
extern const std::string WHITESPACE;
extern const std::string unavailable;
extern const std::string fileLocation;
extern const std::string unknown;
extern const std::string errorfile;

extern const char doubleQuote;
extern const char singleQuote;
extern const char space;
extern const char angle ;

// template function
// return if vector or string is empty or not
// used in UserInputHandler.cpp line 39
template <class T>
bool isEmpty(T t)
{
	return t.empty() ;
}
#endif
