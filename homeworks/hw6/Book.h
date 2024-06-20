#ifndef BOOK_H
#define BOOK_H  

#include "Catalog.h"  //including catalog header files

using namespace CatalogSpace; //using Catalog namespace

namespace BookSpace{    //namespace for book class

class Book : public Catalog<Book>   //inherited from the catalog class.
{
private:
 
    string authors; //authors for books
    string tags;    //tags for books
public:
    Book(); //Default Constructor

    //Constructor
    Book(string  _title ,string _year, string _authors , string _tags) :  authors(_authors) , tags(_tags) , Catalog(_title, _year){}; 
    
    string getAuthors()const{return authors;} //Getter for authors
    string getTags()const{return tags;}   //Getter for tags
    void read(const string filename,const string filename2) override; //Read function is overridden.
    bool operator==(const Book &other) const override ; //The Operator == is required to use in the find function (while searching).
    void sort(const string field) override;// Sort function by given field 
    
};

}


#endif