#include "MovieDescription.hpp"

using namespace std;

MovieDescription::MovieDescription(string newTitle, string newRated, string newReleased, string newRuntime,
                                   string newPlot, string newFilename, vector<string> newGenre,
                                   vector<string> newActors) {
    setTitle(newTitle);
    setRated(newRated);
    setReleased(newReleased);
    setRuntime(newRuntime);
    setPlot(newPlot);
    setFilename(newFilename);
    setGenre(newGenre);
    setActors(newActors);
}

void MovieDescription::setTitle(string newTitle) {
    title = newTitle;
}

void MovieDescription::setRated(string newRated) {
    rated = newRated;
}

void MovieDescription::setReleased(string newReleased) {
    released = newReleased;
}

void MovieDescription::setRuntime(string newRuntime) {
    runtime = newRuntime;
}

void MovieDescription::setPlot(string newPlot) {
    plot = newPlot;
}

void MovieDescription::setFilename(string newFilename) {
    filename = newFilename;
}

void MovieDescription::setGenre(vector<string> newGenre) {
    genre = newGenre;
}

void MovieDescription::setActors(vector<string> newActors) {
    actors = newActors;
}

void MovieDescription::print() {
    cout << "Movie titled " << title << endl;
    cout << "\tRated " << rated << endl;
    cout << "\tReleased " << released << endl;
    cout << "\tRuntime " << runtime << endl;
    cout << "\tPlot: " << plot << endl;
    cout << "\tFilename " << filename << endl;

    cout << "\tGenre: ";
    for (int i = 0; i < genre.size(); i++) {
        cout << genre.at(i) << '\t';
    }
    cout << endl;

    cout << "\tActors: ";
    for (int i = 0; i < actors.size(); i++) {
        cout << actors.at(i) << '\t';
    }
    cout << endl;
}

string MovieDescription::getTitle() {
    return title;
}

string MovieDescription::getRated() {
    return rated;
}

string MovieDescription::getReleased() {
    return released;
}

string MovieDescription::getRuntime() {
    return runtime;
}

string MovieDescription::getPlot() {
    return plot;
}

string MovieDescription::getFilename() {
    return filename;
}

vector<string> MovieDescription::getGenre() {
    return genre;
}

vector<string> MovieDescription::getActors() {
    return actors;
}
