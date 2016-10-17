#include "MovieLibrary.hpp"

using namespace std;

class MovieDescription;

MovieLibrary::MovieLibrary() {}

MovieLibrary::MovieLibrary(string jsonFileName) {
    ifstream jsonFile(jsonFileName.c_str());

    Json::Reader reader;
    Json::Value movies;

    ifstream json(jsonFileName.c_str(), ifstream::binary);

    bool parseSuccess = reader.parse(json, movies, false);

    if (parseSuccess) {
        Json::Value::Members mbr = movies.getMemberNames();

        for (vector<string>::const_iterator i = mbr.begin(); i != mbr.end(); i++) {
            Json::Value jsonMovie = movies[*i];
            string mvStr = "movie";

            if (mvStr.compare(*i) == 0) {
                string placeholder = jsonMovie.asString();
            } else {
                string released = jsonMovie["Released"].asString();
                string rated = jsonMovie["Rated"].asString();

                vector<string> actors;
                const Json::Value actor = jsonMovie["Actors"];

                for (int j = 0; j < actor.size(); ++j) {
                    actors.push_back(actor[j].asString());
                }

                string plot = jsonMovie["Plot"].asString();
                string runtime = jsonMovie["Runtime"].asString();

                vector<string> genre;
                Json::Value genres = jsonMovie["Genre"];

                for (int j = 0; j < genres.size(); j++) {
                    genre.push_back(genres[j].asString());
                }

                string filename = jsonMovie["Filename"].asString();
                string title = jsonMovie["Title"].asString();

                MovieDescription movie(title, rated, released, runtime, plot, filename, genre, actors);
                add(movie);
            }
        }
    }
}

bool MovieLibrary::add(MovieDescription aClip) {
    theLibrary.push_back(aClip);

    if (theLibrary.back().getTitle() == aClip.getTitle()) {
        return true;
    }

    return false;
}

bool MovieLibrary::remove(string aTitle) {
    for (int i = 0; i < theLibrary.size(); i++) {
        if (theLibrary.at(i).getTitle() == aTitle) {
            theLibrary.erase(theLibrary.begin() + i);
            return true;
        }
    }

    return false;
}

MovieDescription MovieLibrary::get(string aTitle) {
    for (int i = 0; i < theLibrary.size(); i++) {
        if (aTitle == theLibrary.at(i).getTitle()) {
            return theLibrary.at(i);
        }
    }
}

vector<string> MovieLibrary::getNames() {
    vector<string> myVec;

    for (int i = 0; i < theLibrary.size(); i++) {
        myVec.push_back(theLibrary.at(i).getTitle());
    }
    return myVec;
}

void MovieLibrary::printGroup() {
    for (int i = 0; i < theLibrary.size(); i++) {
        theLibrary.at(i).print();
    }
}

void MovieLibrary::toJsonFile(string jsonFileName) {
    Json::Value jsonLib;

    for (int i = 0; i < theLibrary.size(); i++) {
        Json::Value jsonMovie;
        MovieDescription movie = theLibrary.at(i);
        jsonMovie["Released"] = movie.getReleased();
        jsonMovie["Rated"] = movie.getRated();

        Json::Value actors;
        vector<string> actor = movie.getActors();

        for (int j = 0; j < actor.size(); j++) {
            actors.append(actor.at(j));
        }
        jsonMovie["Actors"] = actors;

        jsonMovie["Plot"] = movie.getPlot();
        jsonMovie["Runtime"] = movie.getRuntime();

        Json::Value genre;
        vector<string> genres = movie.getGenre();

        for (int j = 0; j < genres.size(); j++) {
            genre.append(genres.at(j));
        }
        jsonMovie["Genre"] = genre;

        jsonMovie["Filename"] = movie.getFilename();
        jsonMovie["Title"] = movie.getTitle();
        jsonLib[movie.getTitle()] = jsonMovie;
    }
    Json::StyledStreamWriter ssw("  ");
    std::ofstream jsonOutFile(jsonFileName.c_str(), std::ofstream::binary);
    ssw.write(jsonOutFile, jsonLib);
}