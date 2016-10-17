#include <string>
#include <iostream>
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
  string genre;
  string actors;

public:
  MovieDescription(string newTitle, string newRated, string newReleased, string newRuntime, string newPlot, string newFilename, string newGenre, string newActors);

  void setTitle(string newTitle);
  void setRated(string newRated);
  void setReleased(string newReleased);
  void setRuntime(string newRuntime);
  void setPlot(string newPlot);
  void setFilename(string newFilename);
  void setGenre(string newGenre);
  void setActors(string newActors);

  string getTitle();
  string getRated();
  string getReleased();
  string getRuntime();
  string getPlot();
  string getFilename();
  string getGenre();
  string getActors();
};
