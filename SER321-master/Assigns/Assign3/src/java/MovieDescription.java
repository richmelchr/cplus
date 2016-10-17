import java.io.Serializable;
import java.util.List;
import java.util.ArrayList;
import org.json.*;

public class MovieDescription
{
  private String title;
  private String rated;
  private String released;
  private String runtime;
  private String plot;
  private String filename;
  private ArrayList<String> genre;
  private ArrayList<String> actors;

  public MovieDescription(String title, String rated, String released, String runtime, String plot, String filename, ArrayList<String> genre, ArrayList<String> actors)
  {
    setTitle(title);
    setRated(rated);
    setReleased(released);
    setRuntime(runtime);
    setPlot(plot);
    setFilename(filename);
    setGenre(genre);
    setActors(actors);
  }

  public MovieDescription(JSONObject jsonObj)
  {
    released = jsonObj.getString("Released");
    rated = jsonObj.getString("Rated");
    actors = toArrayList(jsonObj.getJSONArray("Actors"));
    plot = jsonObj.getString("Plot");
    runtime = jsonObj.getString("Runtime");
    genre = toArrayList(jsonObj.getJSONArray("Genre"));
    filename = jsonObj.getString("Filename");
    title = jsonObj.getString("Title");
  }

  public JSONObject toJSONObject()
  {
     JSONObject obj = new JSONObject();
     obj.put("Released", released);
     obj.put("Rated", rated);
     obj.put("Actors", actors);
     obj.put("Plot", plot);
     obj.put("Runtime", runtime);
     obj.put("Genre", genre);
     obj.put("Filename", filename);
     obj.put("Title", title);
     //System.out.println("User toJSONObject returning: "+obj.toString());
     return obj;
  }

  public void setTitle(String title)
  {
    this.title = title;
  }

  public void setRated(String rated)
  {
    this.rated = rated;
  }

  public void setReleased(String released)
  {
    this.released = released;
  }
  public void setRuntime(String runtime)
  {
    this.runtime = runtime;
  }

  public void setPlot(String plot)
  {
    this.plot = plot;
  }

  public void setFilename(String filename)
  {
    this.filename = filename;
  }

  public void setGenre(ArrayList<String> genre)
  {
    this.genre = genre;
  }
  public void setActors(ArrayList<String> actors)
  {
    this.actors = actors;
  }

  public void print()
  {
    System.out.println("\tRated " + rated);
    System.out.println("\tReleased " + released);
    System.out.println("\tRuntime " + runtime);
    System.out.println("\tPlot: " + plot);
    System.out.println("\tFilename " + filename);
    System.out.println("\tGenre: " + genre);
    System.out.println("\tActors: " + actors);
  }

  public String getTitle()
  {
    return title;
  }

  public String getRated()
  {
    return rated;
  }

  public String getReleased()
  {
    return released;
  }

  public String getRuntime()
  {
    return runtime;
  }

  public String getPlot()
  {
    return plot;
  }

  public String getFilename()
  {
    return filename;
  }

  public ArrayList<String> getGenre()
  {
    return genre;
  }

  public ArrayList<String> getActors()
  {
    return actors;
  }

  private ArrayList<String> toArrayList(JSONArray jsonArray)
  {
    ArrayList<String> list = new ArrayList<String>();

    if (jsonArray != null)
    {
      int length = jsonArray.length();

      for (int i = 0; i < length; i++)
      {
        list.add(jsonArray.get(i).toString());
      }
    }

    return list;
  }
}
