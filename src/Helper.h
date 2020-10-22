#ifndef HELPER_H
#define HELPER_H
#include<string>
#include<map>
#include<future>
#include<vector>
#include<thread>
#include<memory>

#include "Link.h"
#include "Requester.h"
#include "Parser.h"
#include "ResultHandler.h"
#include "Constants.h"

// start request and parse the response
void start(std::string url, std::string path);

// get links and start each link with its thread
void parseLikes(int depth, std::string );

// when all thread finish it start two thread
// one for print and one for write to file
void handleResult(std::string );

// print all link
void print(ResultHandler* handler);

// write all link to file
void writeToFile(std::promise<std::string> &&prms, ResultHandler* handler, std::string domain);
static std::map<std::string, Link> linksMap;

#endif
