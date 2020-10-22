#include <getopt.h>
#include<iostream>
#include <sstream> 

#include "Constants.h"
#include "UserInputHandler.h"
#include "Constants.h"

UserInputHandler::UserInputHandler(int argc,  char* const * argv){
int opt;
if(argc < 2)
    printUsage();

  while ((opt = getopt(argc, argv, ":l:d:p:s:h")) != -1) 
  {
      
     switch (opt) 
     {
      case 'l':
        domain = optarg;
        break;
      case 'd':
        depth = std::stoi(optarg); 
        break;
     case 'p':
        path = optarg;
        break;
      case 's':
        isHttps = true;
        break;
      case '?':
        std::cout<<unknown<<optopt<<std::endl;
        break;
      case 'h':
            printUsage();
        break;
     }
  }
  if(isEmpty(domain)){
    printUsage(missingLink);
  }else
  {
      addProtocol();
  }
}

UserInputHandler::~UserInputHandler(){}

void UserInputHandler::printUsage(){
    std::cout<<USAGE;
    exit(0);
}

void UserInputHandler::printUsage(std::string message){
    std::cout<<message<<std::endl;
    std::cout<<USAGE;
    exit(1);
}

void UserInputHandler::addProtocol(){
    if(isHttps){
        url = https + domain;
    } else
    {
        url = http + domain;
    }
}


std::string UserInputHandler::getUrl(){
    return url;
}

std::string UserInputHandler::getPath(){
    return path;
}

std::string UserInputHandler::getDomain(){
    return domain;
}

int UserInputHandler::getDepth(){
    return depth;
}

