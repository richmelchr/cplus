#include <string>
#include <iostream>
#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"

using namespace std;

class MovieDescription
{
private:
    string title;
    string rated;
    string released;
    string runtime;
    string plot;
    string filename;
    vector<string> genre;
    vector<string> actors;

public:
    MovieDescription(string newTitle, string newRated, string newReleased, string newRuntime, string newPlot, string newFilename, vector<string> newGenre, vector<string> newActors);

    void setTitle(string newTitle);
    void setRated(string newRated);
    void setReleased(string newReleased);
    void setRuntime(string newRuntime);
    void setPlot(string newPlot);
    void setFilename(string newFilename);
    void setGenre(vector<string> newGenre);
    void setActors(vector<string> newActors);
    void print();

    string getTitle();
    string getRated();
    string getReleased();
    string getRuntime();
    string getPlot();
    string getFilename();
    vector<string> getGenre();
    vector<string> getActors();
};
