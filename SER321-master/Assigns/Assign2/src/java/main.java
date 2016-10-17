import java.util.*;

public class main
{
  public static void main(String args[])
  {
    MovieLibrary myLib = new MovieLibrary();

    boolean test0 = myLib.add(new MovieDescription("Minions Banana Song", "PG", "12 Dec 2015", "3 min", "Banana is a song sung by The Minions in the teaser trailer of Despicable Me 2. It is a parody of the Beach Boys' Barbara Ann. A minion got annoyed by another, most likely Stuart, who keeps on playing his party horn while they are singing. So, at the end, he punched Stuart.", "MinionsBananaSong.mp4", "Animation, Cartoon,", "Dave, Gru,"));
    boolean test1 = myLib.add(new MovieDescription("Minions Puppy", "NR", "10 Dec 2013", "4:16 min", "Dave seeing many owners walk their dogs wants a puppy of his own. He finds a mini-UFO who becomes his pal. This short file chronicles Dave helping the mini-UFO return home.", "MinionsPuppy.mp4", "Animation, Family, Cartoon,", "Stuart, Dave,"));

    System.out.println("Added: Movie " + myLib.getTitles()[1]);
    printDescription(myLib.get(myLib.getTitles()[1]));

    String[] titles = myLib.getTitles();

    System.out.println("Use library to fetch : Movie " + titles[0]);

    printDescription(myLib.get(titles[0]));

    System.out.print("After adding two movies, the library contains the titles:\n\t");

    for (int i = 0; i < titles.length; i++)
    {
      if (i+1 == titles.length)
      {
        System.out.println(titles[i]);
      }
      else
      {
        System.out.print(titles[i] + ", ");
      }
    }

    if (myLib.remove(titles[0]))
    {
      System.out.println("Movie titles after removing " + titles[0] + " the titles are:");
    }

    titles = myLib.getTitles();

    for (int i = 0; i < titles.length; i++)
    {
      System.out.print("\t" + titles[i]);
    }

    System.out.println();
  }

  public static void printDescription(MovieDescription movie)
  {
    System.out.println("\tRated " + movie.getRated());
    System.out.println("\tReleased " + movie.getReleased());
    System.out.println("\tRuntime " + movie.getRuntime());
    System.out.println("\tPlot: " + movie.getPlot());
    System.out.println("\tFilename " + movie.getFilename());
    System.out.println("\tGenre: " + movie.getGenre());
    System.out.println("\tActors: " + movie.getActors());
  }
}
