#include "MovieDescription.hpp"
#include <string>
#include <iostream>
using namespace std;

MovieDescription::MovieDescription(string newTitle, string newRated, string newReleased, string newRuntime, string newPlot, string newFilename, string newGenre, string newActors)
{
  setTitle(newTitle);
  setRated(newRated);
  setReleased(newReleased);
  setRuntime(newRuntime);
  setPlot(newPlot);
  setFilename(newFilename);
  setGenre(newGenre);
  setActors(newActors);
}

void MovieDescription::setTitle(string newTitle)
{
  title = newTitle;
}

void MovieDescription::setRated(string newRated)
{
  rated = newRated;
}

void MovieDescription::setReleased(string newReleased)
{
  released = newReleased;
}

void MovieDescription::setRuntime(string newRuntime)
{
  runtime = newRuntime;
}

void MovieDescription::setPlot(string newPlot)
{
  plot = newPlot;
}

void MovieDescription::setFilename(string newFilename)
{
  filename = newFilename;
}

void MovieDescription::setGenre(string newGenre)
{
  genre = newGenre;
}

void MovieDescription::setActors(string newActors)
{
  actors = newActors;
}

string MovieDescription::getTitle()
{
  return title;
}

string MovieDescription::getRated()
{
  return rated;
}

string MovieDescription::getReleased()
{
  return released;
}

string MovieDescription::getRuntime()
{
  return runtime;
}

string MovieDescription::getPlot()
{
  return plot;
}

string MovieDescription::getFilename()
{
  return filename;
}

string MovieDescription::getGenre()
{
  return genre;
}

string MovieDescription::getActors()
{
  return actors;
}
