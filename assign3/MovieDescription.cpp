#include "MovieDescription.hpp"

MovieDescription::MovieDescription() {}
MovieDescription::MovieDescription(string setTitle, string setRated, string setReleased, string setRuntime,
                                   string setPlot, string setFilename, string setGenre, string setActors) {
    title = setTitle;
    rated = setRated;
    released = setReleased;
    runtime = setRuntime;
    plot = setPlot;
    filename = setFilename;
    genre = setGenre;
    actors = setActors;
}
MovieDescription::~MovieDescription() {}

void MovieDescription::setTitle(string setTitle) {title = setTitle;}
void MovieDescription::setRated(string setRated) {rated = setRated;}
void MovieDescription::setReleased(string setReleased) {released = setReleased;}
void MovieDescription::setRuntime(string setRuntime) {runtime = setRuntime;}
void MovieDescription::setPlot(string setPlot) {plot = setPlot;}
void MovieDescription::setFilename(string setFilename) {filename = setFilename;}
void MovieDescription::setGenre(string setGenre) {genre = setGenre;}
void MovieDescription::setActors(string setActors) {actors = setActors;}

string MovieDescription::getTitle()const {return title;}
string MovieDescription::getRated()const {return rated;}
string MovieDescription::getReleased()const {return released;}
string MovieDescription::getRuntime()const {return runtime;}
string MovieDescription::getPlot()const {return plot;}
string MovieDescription::getFilename()const {return filename;}
string MovieDescription::getGenre()const {return genre;}
string MovieDescription::getActors()const {return actors;}

string MovieDescription::toString() {
    string str;

    str.append(this->getTitle());
    str.append("\n    Rated: "+this->getRated());
    str.append("\n    Released: "+this->getReleased());
    str.append("\n    Runtime: "+this->getRuntime());
    str.append("\n    Plot: "+this->getPlot());
    str.append("\n    Filename: "+this->getFilename());
    str.append("\n    Genre: "+this->getGenre());
    str.append("\n    Actors: "+this->getActors());

    return str;
}
