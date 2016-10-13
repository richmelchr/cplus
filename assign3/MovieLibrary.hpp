#include "MovieDescription.hpp"
#include <iostream>
#include <stdlib.h>
#include <string>
#include <vector>
#include <fstream>
#include <stdio.h>
#include <map>
#include "lib/jsoncpp/include/json/json.h"
#include "lib/jsoncpp/include/json/reader.h"
#include "lib/jsoncpp/include/json/writer.h"

using namespace std;

class MovieLibrary {
private:

    vector<MovieDescription> movies;

public:

    MovieLibrary(string jsonFileName);
    MovieLibrary();
    bool add(MovieDescription aClip);
    bool remove(string aTitle);
    MovieDescription get(string aTitle);
    std::vector<string> getTitles(); // returns a vector of strings: the movie titles in the library
};
