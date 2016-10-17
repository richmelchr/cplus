public class MovieDescription
{
  private String title;
  private String rated;
  private String released;
  private String runtime;
  private String plot;
  private String filename;
  private String genre;
  private String actors;

  public MovieDescription(String title, String rated, String released, String runtime, String plot, String filename, String genre, String actors)
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

  public void setGenre(String genre)
  {
    this.genre = genre;
  }
  public void setActors(String actors)
  {
    this.actors = actors;
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

  public String getGenre()
  {
    return genre;
  }

  public String getActors()
  {
    return actors;
  }
}
