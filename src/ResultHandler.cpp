#include<iostream>
#include<fstream>

#include "ResultHandler.h"
#include "Constants.h"


ResultHandler::ResultHandler(std::map<std::string,Link> linksMap):_linksMap(linksMap){

}

ResultHandler::~ResultHandler(){}

CustomResultHandler::CustomResultHandler(std::map<std::string,Link> linksMap):
ResultHandler(linksMap){}

CustomResultHandler::~CustomResultHandler(){}

bool CustomResultHandler::print(){
    std::cout <<std::endl;

    std::cout <<doubleNewLine;
    std::cout << GREEN << internalLinks << RESET << std::endl;
    for( std::map<std::string,Link>::iterator i=_linksMap.begin(); i!=_linksMap.end(); i++)
    {
        if((*i).second.isInternal())
            std::cout << BLUE << plusSign << RESET << (*i).second.getPath() << std::endl;
    }

    std::cout <<doubleNewLine;
    std::cout << GREEN << externalLinks<< RESET << std::endl;
    for( std::map<std::string,Link>::iterator i=_linksMap.begin(); i!=_linksMap.end(); i++)
    {
        if(!(*i).second.isInternal())
            std::cout << BLUE << plusSign << RESET << (*i).second.getPath() << std::endl;
    }
    return true;
}

bool CustomResultHandler::writeToFile(std::string domain){
  std::ofstream myfile;
  std::string fileName = domain+txt;

  myfile.open (fileName);
  if(myfile){
    
      myfile <<internalLinks<<std::endl;
    for( std::map<std::string,Link>::iterator i=_linksMap.begin(); i!=_linksMap.end(); i++)
    {
        if((*i).second.isInternal())
            myfile << plusSign << (*i).second.getPath() << std::endl;
    }
  myfile.close();
  return true;
  }
return false;
}
