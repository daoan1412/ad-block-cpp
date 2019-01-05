/* Copyright (c) 2015 Brian R. Bondy. Distributed under the MPL2 license.
 * This Source Code Form is subject to the terms of the Mozilla Public
 * License, v. 2.0. If a copy of the MPL was not distributed with this
 * file, You can obtain one at http://mozilla.org/MPL/2.0/. */

#include <algorithm>
#include <cerrno>
#include <iostream>
#include <fstream>
#include <vector>
#include <sstream>
#include <string>
#include "./ad_block_client.h"
//#include "nan.h"

using std::cout;
using std::endl;
using std::string;

string getFileContents(const char *filename) {
    std::ifstream in(filename, std::ios::in);
    if (in) {
        std::ostringstream contents;
        contents << in.rdbuf();
        in.close();
        return(contents.str());
    }
    throw(errno);
}



void writeFile(const char *filename, const char *buffer, int length) {
    std::ofstream outFile(filename, std::ios::out | std::ios::binary);
    if (outFile) {
        outFile.write(buffer, length);
        outFile.close();
        return;
    }
    throw(errno);
}

int checkForClient(const std::vector<std::string> &urlsToCheck) {
    const char *currentPageDomain = "theguardian.com";


    AdBlockClient client2;
    // Deserialize uses the buffer directly for subsequent matches, do not free
    // until all matches are done.
    std::ifstream is ("./ABPFilterClientData.dat", std::ifstream::binary);

    if (is) {
        // get length of file:
        is.seekg (0, is.end);
        int length = is.tellg();
        is.seekg (0, is.beg);
        char * buffer = new char [length];
        // read data as a block:
        is.read (buffer,length);

        if (is)
            std::cout << "all characters read successfully.";
        else
            std::cout << "error: only " << is.gcount() << " could be read";
        is.close();

        AdBlockClient client2;
        client2.deserialize(buffer);
        std::for_each(urlsToCheck.begin(), urlsToCheck.end(),
                      [&client2, currentPageDomain](std::string const &urlToCheck) {
                          if (client2.matches(urlToCheck.c_str(),
                                             FOGenericHide, currentPageDomain)) {
                              cout << urlToCheck << ": You should block this URL!" << endl;
                          } else {
                              cout << urlToCheck << ": You should NOT block this URL!" << endl;
                          }
                      });
        delete[] buffer;
    }

    return 0;
}


int main(int argc, char**argv) {

        std::vector<std::string> checkVector;
        checkVector.push_back(
                "https://www.nytimes.com/");
        checkVector.push_back(
                "http://tpc.googlesyndication.com/safeframe/1-0-2/html/container.html");
        checkVector.push_back(
                "http://www.googletagservices.com/tag/js/gpt_mobile.js");
        checkVector.push_back("http://www.brianbondy.com");
        checkForClient(checkVector);

    return 0;
}
