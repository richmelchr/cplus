/**
 * Main class
 *
 *
 * Copyright (c) 2015 Jacob Gersztyn
 * Permission is hereby granted, free of charge, to any person obtaining a copy
 * of this software and associated documentation files (the "Software"), to deal
 * in the Software without restriction, including without limitation the rights
 * to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
 * copies of the Software, and to permit persons to whom the Software is
 * furnished to do so, subject to the following conditions:
 * The above copyright notice and this permission notice shall be included in all
 * copies or substantial portions of the Software.
 * THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
 * IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
 * FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
 * AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
 * LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
 * OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
 * SOFTWARE.
*/


#include "MovieLibrary.hpp"
#include "../../lib/jsoncpp/include/json/json.h"
#include <iostream>

int main()
{

    std::cout << "Loading from 'media.json'..." << std::endl;

    MediaLibrary lib("media.json");

    std::cout << "Loaded" << std::endl;

    std::cout << "\nMusic Titles: " << std::endl;

    std::vector<std::string> titles = lib.getMusicTitles();

    while(!titles.empty())
    {
        std::string str = titles.back();
        titles.pop_back();
        std::cout << " a   " << str << std::endl;
    }

    std::cout << "\nVideo Titles: " << std::endl;

    titles = lib.getVideoTitles();

    std::cout << titles[1];

    while(!titles.empty())
    {
        std::string str = titles.back();
        titles.pop_back();
        std::cout << "    " << str << std::endl;
    }

    std::cout << "Saving to 'media-cpp.json'..." << std::endl;

    lib.toJSONFile("media-cpp.json");

    std::cout << "Saved" << std::endl;

    return 0;

}
