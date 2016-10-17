#include <iostream>
#include <string>
#include "MovieLibrary.hpp"
using namespace std;

void printDescription(MovieDescription movie);

int main()
{
  MovieLibrary myLib;
  int titlesAdded = 0;
  MovieDescription movie0("Minions Banana Song", "PG", "12 Dec 2015", "3 min", "Banana is a song sung by The Minions in the teaser trailer of Despicable Me 2. It is a parody of the Beach Boys' Barbara Ann. A minion got annoyed by another, most likely Stuart, who keeps on playing his party horn while they are singing. So, at the end, he punched Stuart.", "MinionsBananaSong.mp4", "Animation, Cartoon,", "Dave, Gru,");
  MovieDescription movie1("Minions Puppy", "NR", "10 Dec 2013", "4:16 min", "Dave seeing many owners walk their dogs wants a puppy of his own. He finds a mini-UFO who becomes his pal. This short file chronicles Dave helping the mini-UFO return home.", "MinionsPuppy.mp4", "Animation, Family, Cartoon,", "Stuart, Dave,");
  if(myLib.add(movie0))
  {
    titlesAdded++;
  }
  if(myLib.add(movie1))
  {
    titlesAdded++;
  }

  string* titles = myLib.getTitles();

  cout << "After adding " << titlesAdded << " movies to the library, the titles are ";

  for (int i = 0; i < titlesAdded; i++)
  {
    cout << titles[i] << ", ";
  }

  cout << endl;
  
  cout << "The Movie Library Contains:" << endl;

  for (int i = 0; i < titlesAdded; i++)
  {
    printDescription(myLib.get(titles[i]));
  }

  if (myLib.remove(titles[0]))
  {
    titlesAdded--;
    cout << "After removing " << titles[0] << ", remaining titles are ";
  }

  titles = myLib.getTitles();

  for (int i = 0; i < titlesAdded; i++)
  {
    cout << titles[i] << ", ";
  }

  cout << endl;

  return 0;
}

void printDescription(MovieDescription movie)
{
  cout << "Movie titled " << movie.getTitle() << endl;
  cout << "\tRated " << movie.getRated() << endl;
  cout << "\tReleased " << movie.getReleased() << endl;
  cout << "\tRuntime " << movie.getRuntime() << endl;
  cout << "\tPlot: " << movie.getPlot() << endl;
  cout << "\tFilename " << movie.getFilename() << endl;
  cout << "\tGenre: " << movie.getGenre() << endl;
  cout << "\tActors: " << movie.getActors() << endl;
}
