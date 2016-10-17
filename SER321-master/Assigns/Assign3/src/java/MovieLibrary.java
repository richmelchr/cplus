import java.util.List;
import java.util.ArrayList;
import org.json.JSONString;
import org.json.JSONObject;
import org.json.JSONTokener;
import java.io.FileInputStream;
import java.io.PrintWriter;
import java.io.File;
import java.util.Enumeration;
import java.io.Serializable;

public class MovieLibrary
{
  private List<MovieDescription> theLibrary = new ArrayList<MovieDescription>();

  public MovieLibrary()
  {

  }

  public MovieLibrary(String jsonFileName)
  {
    try
    {
      FileInputStream in = new FileInputStream(jsonFileName);
      JSONObject obj = new JSONObject(new JSONTokener(in));
      String [] titles = JSONObject.getNames(obj);
      System.out.print("Titles are: ");

      for(int j = 0; j < titles.length; j++)
      {
        System.out.print(titles[j]+", ");
      }

      System.out.println();

      List<MovieDescription> movies = new ArrayList<MovieDescription>();

      for (int i = 0; i < titles.length; i++)
      {
        if(!titles[i].equals("name"))
        {
          MovieDescription movie = new MovieDescription((JSONObject)obj.getJSONObject(titles[i]));
          theLibrary.add(movie);
        }
      }
      in.close();
    }
    catch (Exception ex)
    {
      System.out.println("Exception importing from json: " + ex.getMessage());
    }
  }

  public void toJsonFile(String jsonFileName)
  {
    try
    {
      PrintWriter out = new PrintWriter(jsonFileName);
      out.println(toJSONString());
      out.close();
      System.out.println("Done exporting movies in json to moviesJava.json");
    }
    catch (Exception e)
    {
      System.out.println("exception: " + e.getMessage());
      e.printStackTrace();
    }
  }

  public String toJSONString()
  {
     String output;
     JSONObject obj = new JSONObject();
     for (int i = 0; i < theLibrary.size(); i++)
     {
        MovieDescription md = theLibrary.get(i);
        obj.put(md.getTitle(),md.toJSONObject());
     }
     output = obj.toString();
     //System.out.println("group tojsonstring returning string: "+ret);
     return output;
  }

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

  public void printGroup()
  {
    for (int i = 0; i < theLibrary.size(); i++)
    {
      theLibrary.get(i).print();
    }
  }
}
