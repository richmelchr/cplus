#include "MovieLibrary.hpp"
#include <string>
#include <vector>
using namespace std;

class MovieDescription;

bool MovieLibrary::add(MovieDescription aClip)
{
  theLibrary.push_back(aClip);

  if (theLibrary.back().getTitle() == aClip.getTitle())
  {
    return true;
  }

  return false;
}

bool MovieLibrary::remove(string aTitle)
{
  for (int i = 0; i < theLibrary.size(); i++)
  {
    if (theLibrary.at(i).getTitle() == aTitle)
    {
      theLibrary.erase(theLibrary.begin() + i);
      return true;
    }
  }

  return false;
}

MovieDescription MovieLibrary::get(string aTitle)
{
  for (int i = 0; i < theLibrary.size(); i++)
  {
    if (aTitle == theLibrary.at(i).getTitle())
    {
      return theLibrary.at(i);
    }
  }
}

string* MovieLibrary::getTitles()
{
  string* titles = new string[theLibrary.size()];

  for (int i = 0; i < theLibrary.size(); i++)
  {
    titles[i] = theLibrary.at(i).getTitle();
  }

  return titles;
}
