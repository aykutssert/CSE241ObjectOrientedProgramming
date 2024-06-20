#include "Catalog.h"
#include "Book.h"
#include "Music.h"
#include "Movie.h"
#include "Music.cpp"
#include "Movie.cpp"
#include "Book.cpp"
#include "Catalog.cpp"

using namespace CatalogSpace;
using namespace MovieSpace;
using namespace MusicSpace;
using namespace BookSpace;



int main()
{

    std::ifstream veriAl("data.txt"); // Firstly , Type is read from the data.txt file.

    string type;
    veriAl >> type;

    if (type == "movie")        //if type is movie
    {
        //Movie movie; //movie object is created.

        //movie.read("data.txt", "commands.txt");  // data is read from the data.txt file and command is read from the commands.txt file and process begins.

        Catalog<Movie>* movie;
        movie = new Movie();
        movie->read("data.txt","commands.txt");
    }
    else if (type == "music")   //if type is music
    {

        //Music music;  //music object is created.

        //music.read("data.txt", "commands.txt"); //data is read from the data.txt file and command is read from the commands.txt file and process begins.

        Catalog<Music>* music;
        music = new Music();
        music->read("data.txt","commands.txt");
    }
    else if (type == "book")  //if type is book
    {
        //Book book;  //book object is created.

        //book.read("data.txt", "commands.txt"); // data is read from the data.txt file and command is read from the commands.txt file and process begins.

        Catalog<Book>* book;
        book = new Book();
        book->read("data.txt","commands.txt");
    }

    return 0;
}