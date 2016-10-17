/**
 * Media Description header
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

#include <iostream>
#include "../../lib/jsoncpp/include/json/json.h"

class MediaDescription
{
private:
    std::string title, author, album, genre, filename;
    int mediaType;
public:
    MediaDescription();
    MediaDescription(std::string title);
    MediaDescription(int pmediaType, std::string ptitle, std::string pauthor, std::string palbum, std::string pgenre, std::string pfilename);
    MediaDescription(Json::Value jsonObject);
    std::string getTitle();
    std::string getAuthor();
    std::string getAlbum();
    std::string getGenre();
    std::string getFilename();
    int getMediaType();
    void setAuthor(std::string p_author);
    void setAlbum(std::string p_album);
    void setGenre(std::string p_genre);
    void setFilename(std::string p_filename);
    void setMediaType(int p_mediaType);
    bool isMusic();
    std::string toString();
    Json::Value toJSONObject();

};
