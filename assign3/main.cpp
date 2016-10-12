#include <iostream>
#include <string>
#include <vector>
#include <stdlib.h>

#include "MovieLibrary.hpp"

using namespace std;

int main() {
    MovieLibrary myLib;
    myLib.add(MovieDescription("The Dark Knight", "PG-13", "2008", "152", "Batman Stuff",
                               "The_Dark_Knight.mp4", "Action, Superhero", "Christian Bale"));

    myLib.add(MovieDescription("GoldenEye", "PG-13", "1995", "130", "James Bond Stuff",
                               "GoldenEye.mp4", "Action", "Pierce Brosnan"));

    vector<string> titles = myLib.getTitles();

    cout << "After adding two movies to the library, the titles are ";
    for (unsigned int i = 0; i < titles.size(); ++i) {
        cout << titles[i] << ", ";
    }

    cout << endl << "The Movie Library Contains:";

    string temp;
    for (unsigned int j = 0; j < titles.size(); ++j) {
        MovieDescription aMovie = myLib.get(titles[j]);
        cout << "\nMovie titled " << aMovie.toString();
    }
    temp.clear();

    cout << "\nAfter removing " << titles[0] << ", remaining titles are ";
    myLib.remove(titles[0]);
    titles = myLib.getTitles();

    for (unsigned int i = 0; i < titles.size(); ++i) {
        cout << titles[i] << ", ";
    }
    titles.clear();

    return 0;
}