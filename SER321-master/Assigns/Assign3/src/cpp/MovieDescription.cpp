/**
 * Media Description class
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


#include "MovieDescription.hpp"
#include <iostream>

MediaDescription::MediaDescription()
        :title(""),author(""),album(""),genre(""),filename(""),mediaType(0)
{

};

MediaDescription::MediaDescription(int p_mediaType, std::string p_title, std::string p_author, std::string p_album, std::string p_genre, std::string p_filename)
        :title(p_title), author(p_author), album(p_album), genre(p_genre), filename(p_filename), mediaType(p_mediaType)
{

};

MediaDescription::MediaDescription(Json::Value jsobj)
{
  this->title = jsobj["title"].asString();
  this->author = jsobj["author"].asString();
  this->album = jsobj["album"].asString();
  this->genre = jsobj["genre"].asString();
  this->filename = jsobj["filename"].asString();
  this->mediaType = jsobj["mediaType"].asInt();

}

std::string MediaDescription::getTitle() { return this->title; }
std::string MediaDescription::getAlbum() { return this->album; }
std::string MediaDescription::getAuthor() { return this->author; }
std::string MediaDescription::getGenre() { return this->genre; }
std::string MediaDescription::getFilename() { return this->filename; }
int MediaDescription::getMediaType() { return this->mediaType; }

void MediaDescription::setAuthor(std::string p_author) { this->author = p_author; }
void MediaDescription::setAlbum(std::string p_album) { this->album = p_album; }
void MediaDescription::setGenre(std::string p_genre) { this->genre = p_genre; }
void MediaDescription::setFilename(std::string p_filename) { this->filename = p_filename; }
void MediaDescription::setMediaType(int p_mediaType) { this->mediaType = p_mediaType; }

std::string MediaDescription::toString()
{
  std::string str;

  str.append("Type: ");
  str.append(((this->getMediaType() == 0) ? "Music" : "Video" ));
  str.append("\nTitle: "+this->getTitle());
  str.append("\nAuthor: "+this->getAuthor());
  str.append("\nAlbum: "+this->getAlbum());
  str.append("\nGenre: "+this->getGenre());
  str.append("\nFilename: "+this->getFilename());

  return str;
}

Json::Value MediaDescription::toJSONObject()
{
  Json::Value jsobj;

  jsobj["title"] = this->getTitle();
  jsobj["author"] = this->getAuthor();
  jsobj["album"] = this->getAlbum();
  jsobj["genre"] = this->getGenre();
  jsobj["filename"] = this->getFilename();
  jsobj["mediaType"] = this->getMediaType();

  return jsobj;

}
