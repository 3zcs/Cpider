#include <string>
#include <map>

#include "UserInputHandler.h"
#include "Helper.h"
#include "Link.h"

int main(int argc, char * argv[])
{
    // get user input
    UserInputHandler handler (argc,argv);

    // first request to get links 
    start(handler.getUrl(), handler.getPath());

    // start thread for each link and repeat until reach the number of depth
    // visited link won't be visited again
    parseLikes(handler.getDepth(), handler.getUrl());

    // handle result by print and save links 
    handleResult(handler.getDomain());

    return 0;
}

