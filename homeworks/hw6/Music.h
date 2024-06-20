#ifndef MUSIC_H
#define MUSIC_H

#include "Catalog.h" //including catalog header files

using namespace CatalogSpace; //using Catalog namespace

namespace MusicSpace //namespace for music class
{
  class Music : public Catalog<Music> //inherited from the catalog class.
  {
  private:
    string artists; //artists for music
    string genre;    //tags for music

  public:
    Music(); //Default Constructor 

    //Constructor
    Music(string _title, string _year, string _artists, string _genre) : artists(_artists), genre(_genre), Catalog(_title, _year){};

    string getArtists() const { return artists; } //Getter for artists
    string getGenre() const { return genre; }   //Getter for genre

    void read(const string filename,const string filename2) override; //Read function is overridden.
    bool operator==(const Music &other) const override; // Sort function by given field
    void sort(const string field)override;  //The Operator == is required to use in the find function (while searching).

    
  };
}

#endif