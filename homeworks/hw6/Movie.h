#ifndef MOVIE_H
#define MOVIE_H


#include "Catalog.h" //including catalog header files

using namespace CatalogSpace; //using Catalog namespace

namespace MovieSpace  //namespace for movie class
{
  class Movie : public Catalog<Movie>  //inherited from the catalog class.
  {
  private:
    
    string directors;  //directors for movie
    string genre;     //tags for movie
    string starring;  // starring for movie
  public:
    Movie(); //Default Constructor

    //Constructor
    Movie(string _title, string _year, string _directors, string _genre, string _starring) : directors(_directors), genre(_genre), starring(_starring) , Catalog(_title , _year){};

    
    string getDirectors() const { return directors; } //Getter for directors
    string getGenre() const { return genre; } //Getter for genre
    string getStarring() const { return starring; } //Getter for starring

    void read(const string filename,const string filename2) override; //Read function is overridden.
    bool operator==(const Movie &other) const override; //The Operator == is required to use in the find function (while searching).
    void sort(const string field) override; // Sort function by given field
    
    
  };

}

#endif