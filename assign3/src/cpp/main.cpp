#include "MovieLibrary.hpp"
#include <fstream>
#include <iostream>
#include <string>

using namespace std;

void printDescription(MovieDescription movie);

int main() {
    MovieLibrary myLib("d:code/cplus/assign3/movies.json");

    cout << endl << "Done initializing from movies.json" << endl;
    myLib.printGroup();

//    MovieDescription maybe = myLib.get("Serenity");

//    string something = maybe.getRated();

//    cout << something << endl;


    myLib.toJsonFile("d:code/cplus/assign3/moviesCPP.json");
    cout << "Done writing to moviesCPP.json" << endl;

    return 0;
}
