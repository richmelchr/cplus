#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class MovieDescription {
private:
    string title;
    string rated;
    string released;
    string runtime;
    string plot;
    string filename;
    string genre;
    string actors;

public:
    MovieDescription();
    MovieDescription(string setTitle, string setRated, string setReleased, string setRuntime,
                     string setPlot, string setFilename, string setGenre, string setActors);
    ~MovieDescription();

    void setTitle(string setTitle);
    void setRated(string setRated);
    void setReleased(string setReleased);
    void setRuntime(string setRuntime);
    void setPlot(string setPlot);
    void setFilename(string setFilename);
    void setGenre(string setGenre);
    void setActors(string setActors);

    string getTitle()const;
    string getRated()const;
    string getReleased()const;
    string getRuntime()const;
    string getPlot()const;
    string getFilename()const;
    string getGenre()const;
    string getActors()const;

    string toString();
};
