#include "MovieDescription.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>

using namespace std;

class MovieLibrary {
private:
    vector<MovieDescription> movies;

public:
    MovieLibrary();

    bool add(MovieDescription aClip);
    bool remove(string aTitle);
    MovieDescription get(string aTitle);
    std::vector<string> getTitles(); // returns a vector of strings: the movie titles in the library
};
