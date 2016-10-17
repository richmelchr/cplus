/**
 * Media Library class
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
#include <fstream>


MediaLibrary::MediaLibrary()
{

}

MediaLibrary::MediaLibrary(std::string jsonFilename)
{
    Json::Reader jsin;
    std::ifstream fin(jsonFilename.c_str());
    Json::Value obj;

    jsin.parse(fin, obj, false);

    std::vector<std::string> titles = obj.getMemberNames();

    while(!titles.empty())
    {
        std::string title = titles.back();
        mediaFiles[title] = obj[title];
        titles.pop_back();
    }

}

MediaDescription MediaLibrary::get(std::string aTitle)
{
    return mediaFiles[aTitle];
}

bool MediaLibrary::add(MediaDescription aClip)
{
    MediaDescription found = get(aClip.getTitle());

    if(found.getTitle() == "")
    {
        mediaFiles[aClip.getTitle()] = aClip;
        return true;
    }

    return false;
}

bool MediaLibrary::remove(std::string aTitle)
{
    MediaDescription found = get(aTitle);

    if(found.getTitle() != "")
    {
        mediaFiles.erase(aTitle);
        return true;
    }

    return false;

}

std::vector<std::string> MediaLibrary::getTitles()
{
    std::vector<std::string> vec;
    for (std::map<std::string, MediaDescription>::iterator iter = mediaFiles.begin(); iter !=  mediaFiles.end(); iter++)
    {
        vec.push_back(iter->first);
    }

    return vec;
}


std::vector<std::string> MediaLibrary::getMusicTitles()
{
    std::vector<std::string> vec;
    for (std::map<std::string, MediaDescription>::iterator iter = mediaFiles.begin(); iter !=  mediaFiles.end(); iter++)
    {
        if( iter->second.getMediaType() == 0 )
            vec.push_back(iter->first);
    }

    return vec;
}


std::vector<std::string> MediaLibrary::getVideoTitles()
{
    std::vector<std::string> vec;
    for (std::map<std::string, MediaDescription>::iterator iter = mediaFiles.begin(); iter !=  mediaFiles.end(); iter++)
    {
        if( iter->second.getMediaType() == 1 )
            vec.push_back(iter->first);
    }

    return vec;
}

void MediaLibrary::toJSONFile(std::string jsonFile)
{
    Json::FastWriter jsout;
    std::ofstream fout(jsonFile.c_str());

    Json::Value obj;

    for(std::map<std::string, MediaDescription>::iterator iter = mediaFiles.begin(); iter != mediaFiles.end(); iter++)
    {
        obj[iter->first] = iter->second.toJSONObject();
    }

    fout << jsout.write(obj);

    fout.close();
}
