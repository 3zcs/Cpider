
# Cpider
This project is a command-line tool that extracts all links, directories and files name from a website, as many tools use wordlist to find this information, This tool extracts what is already exist inside the website  

## Dependencies for Running Locally
* cmake >= 3.7
  * All OSes: [click here for installation instructions](https://cmake.org/install/)
* make >= 4.1 (Linux, Mac), 3.81 (Windows)
  * Linux: make is installed by default on most Linux distros
  * Mac: [install Xcode command line tools to get make](https://developer.apple.com/xcode/features/)
  * Windows: [Click here for installation instructions](http://gnuwin32.sourceforge.net/packages/make.htm)
* gcc/g++ >= 5.4
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac: same deal as make - [install Xcode command line tools](https://developer.apple.com/xcode/features/)
  * Windows: recommend using [MinGW](http://www.mingw.org/)
* curl
  * Linux: gcc / g++ is installed by default on most Linux distros
  * Mac, Windows: You can install it for mac and windows from [here](https://developer.apple.com/xcode/features/)


## Build
You can build this tool just by running  these commands

```
 $ sudo apt-get install libcurl4-gnutls-dev
 $ mkdir build
 $ cd build
 $ cmake .. && make
 $ ./cpider -l www.test.com -d 2 -p /test/path -ss
```

## Run
You have some args and option to utilize this tool usage

`-l`: this is required input which is the link of the website without protocol (e.g example.com).

`-p` This is optional input if you want to specify a path (e.g /this/path).

`-d` This is optional input to specify the depth of spidering - I mean, if the tool finds result will go for another iteration -  by default is 1.

`-ss` This is an optional flag if you want the request with HTTPS by default is HTTP.


`-h`: For help.

## Example

```
$ ./cpider -l stackoverflow.com -d 2 -ss -p /questions/11471690/curl-h-no-such-file-or-directory/11471743
```

```
./cpider -l github.com -ss -p /trending
```


## License
Copyright 2020 3zcs

Permission is hereby granted, free of charge, to any person obtaining a copy of this software and associated documentation files (the "Software"), to deal in the Software without restriction, including without limitation the rights to use, copy, modify, merge, publish, distribute, sublicense, and/or sell copies of the Software, and to permit persons to whom the Software is furnished to do so, subject to the following conditions:

The above copyright notice and this permission notice shall be included in all copies or substantial portions of the Software.

THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM, OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE SOFTWARE.