import java.util.List;
import java.util.ArrayList;

public class MovieLibrary
{
  private List<MovieDescription> theLibrary = new ArrayList<MovieDescription>();

  public boolean add(MovieDescription aClip)
  {
    return theLibrary.add(aClip);
  }

  public boolean remove(String aTitle)
  {
    return theLibrary.remove(get(aTitle));
  }

  public MovieDescription get(String aTitle)
  {
    for (int i = 0; i < theLibrary.size(); i++)
    {
      if (theLibrary.get(i).getTitle() == aTitle)
      {
        return theLibrary.get(i);
      }
    }

    return null;
  }

  public String[] getTitles()
  {
    String[] titles = new String[theLibrary.size()];

    for (int i = 0; i < theLibrary.size(); i++)
    {
      titles[i] = theLibrary.get(i).getTitle();
    }

    return titles;
  }
}
