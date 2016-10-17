#include "MovieDescription.hpp"
#include <iostream>
#include <stdlib.h>
#include <stdio.h>
#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include "json/json.h"
#include "json/json-forwards.h"

using namespace std;

class MovieDescription;

class MovieLibrary
{
public:
    MovieLibrary(string jsonFileName);
    MovieLibrary();
    bool add(MovieDescription aClip);
    bool remove(string aTitle);
    MovieDescription get(string aTitle);
    vector<string> getNames();
    void printGroup();
    void toJsonFile(string jsonFileName);

private:
    vector<MovieDescription> theLibrary;
};
