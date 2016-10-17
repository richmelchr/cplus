#include "MovieDescription.hpp"
#include <string>
#include <vector>
using namespace std;

class MovieDescription;

class MovieLibrary
{
public:
  bool add(MovieDescription aClip);
  bool remove(string aTitle);
  MovieDescription get(string aTitle);
  string* getTitles();

private:
  vector<MovieDescription> theLibrary;
};
