import java.util.*;

public class main
{
  public static void main(String args[])
  {
    System.out.println("Importing group from movies.json");
    MovieLibrary myLib = new MovieLibrary("movies.json");
    myLib.printGroup();

    myLib.toJsonFile("moviesJava.json");
  }
}
