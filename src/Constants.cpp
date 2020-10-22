#include "Constants.h"

const std::string USAGE = "USAGE: ./cpider --l link.com --d 3 --s [ --h] \
\n\tREQUIRED: \
\n\t\t  -l  <arg>\tLink without protocol (e.g google.com).\
\n\
\n\t OPTIONAL:\
\n\t\t -p  <arg> \tTo specify a path (e.g /this/path).\
\n\t\t -d  <arg> \tDepth of spidering \
\n\t\t -ss       \tflag to use https, by defual it's http\
\n\t\t -h        \tPrint this help.\n";


const std::string missingLink = "-l is missing";
const std::string https = "https://";
const std::string http = "http://";
const std::string internalLinks = "\t\t----------- INTERNEL LINKS -----------";
const std::string externalLinks = "\t\t----------- EXTERNAK LINKS -----------";
const std::string doubleNewLine = "\n\n";
const std::string plusSign = "[+] ";
const std::string txt = ".txt";
const std::string unknown = "Unknown option: %c\n";
const std::string href = "href";
const std::string src = "src";
const std::string WHITESPACE = " \n\r\t\f\v";
const std::string equal = "=";
const std::string unavailable = "Result unavailable";
const std::string fileLocation = "Your data has been saved in this file: ";
const std::string errorfile = "Error happened while writing data to file";
const char singleQuote = '\'';
const char doubleQuote = '\"';
const char angle = '>';
const char space = ' ';
