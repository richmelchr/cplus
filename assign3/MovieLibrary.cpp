#include "MovieLibrary.hpp"

MovieLibrary::MovieLibrary() {}

MovieLibrary::MovieLibrary(string jsonFileName) {
    ifstream jsonFile(jsonFileName.c_str());

    Json::Reader reader;
    Json::Value movies;









}





bool MovieLibrary::add(MovieDescription aClip) {
    movies.push_back(aClip);
    return true;
}

std::vector<string> MovieLibrary::getTitles() {
    vector<string> something;

    for (unsigned int i = 0; i < movies.size(); ++i) {
        something.push_back(movies[i].getTitle());
    }
    return something;
}

bool MovieLibrary::remove(string aTitle) {
    for (unsigned int i = 0; i < movies.size(); ++i) {
        string title = movies[i].getTitle();
        if (title == aTitle) {
            movies.erase(movies.begin()+i);
            return true;
        }
    }
    return false;
}

MovieDescription MovieLibrary::get(string aTitle) {
    for (unsigned int i = 0; i < movies.size(); ++i) {
        string title = movies[i].getTitle();
        if (title == aTitle) {
            return movies[i];
        }
    }
    MovieDescription Blank;
    return Blank;
}

