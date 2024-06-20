#include <iostream>  //for cout , getline etc.
#include <algorithm> //for sort and find_if function
#include <fstream>   //for ifstream and ofstream class
#include <sstream>   //for stringstream class
#include "Book.h"    //including Book header

using std::endl;

namespace BookSpace
{
    // Default Constructor
    Book::Book() : Catalog("", "") // Base Class Constructor has been called.
    {
        authors = ""; // Member variables take the default value.
        tags = "";
    }

    void Book::sort(const string field) // Sort function by given field
    {

        

        if (field == "title")                                      // field -> title
        {
            std::sort(data.begin(), data.end(),
                      [](const Book *a, const Book *b)
                      { return a->getTitle() < b->getTitle(); }); // sort by small to big
        }

        if (field == "year")                                      // field -> year
        { 
            std::sort(data.begin(), data.end(),
                      [](const Book *a, const Book *b)
                      { return a->getYear() < b->getYear(); }); // sort by small to big
        }
        if (field == "authors")                                      // field -> authors
        { 
            std::sort(data.begin(), data.end(),
                      [](const Book *a, const Book *b)
                      { return a->getAuthors() < b->getAuthors(); }); // sort by small to big
        }
        if (field == "tags")                                       // field -> tags
        { 
            std::sort(data.begin(), data.end(),
                      [](const Book *a, const Book *b)
                      { return a->getTags() < b->getTags(); }); // sort by small to big
        }
    }

    // Read function from file
    void Book::read(const string filename,const string filename2)
    {

        std::ifstream veriAl(filename);      // read data from file
        std::ifstream komutAl(filename2);    // read command from file
        std::ofstream veriYaz("output.txt"); // write to file

        std::string catalogType; // Type (Music , Movie , Book)

        getline(veriAl, catalogType); // read the Type.

        string line; // variable holding a line.

        veriYaz << "Catalog read:" << catalogType << endl; //type is written to file.

        while (getline(veriAl, line)) //line-by-line data reading process begins.
        {
            auto quote = 0;    // variable holding all quotes in a line.
            line = trim(line); // deleting the spaces on both sides of a line. using trim function

            std::stringstream separation(line); // An object has been created from the stringstream class
            // Because using this object we split the whole row into member variables.

            string title, authors, year, tags; // temp variables.
            try
            {
                getline(separation, title, '\"'); // split
                getline(separation, title, '\"'); // split

                getline(separation, authors, '\"'); // split
                getline(separation, authors, '\"'); // split

                getline(separation, year, '\"'); // split
                getline(separation, year, '\"'); // split

                getline(separation, tags, '\"'); // split
                getline(separation, tags, '\"'); // split

                for (auto i = 0; i < line.length(); i++)
                {
                    if (line[i] == '\"') // If there is a quote on that line,
                    {

                        quote += 1; // the quote is incremented by one.
                    }
                }

                // if the number of quotes is equal to twice the number of member variables And all member variables is empty.
                if ((title.empty() || year.empty() || authors.empty() || tags.empty()) && quote != 8)
                {
                    throw Exception("missing field", 2); // at least one field is missing.
                }

                std::vector<Book *>::iterator iter; // Iterator has been created.

                iter = find_if(data.begin(), data.end(), [&title, &year, &authors, &tags](Book *book)
                               { return *book == Book(title, year, authors, tags); }); // Operator== is called and equality is checked.

                // data.end() points to an invalid position at the end of the vector.
                // If iter is equal to data.end() , then the requested object is not found.

                if (iter != data.end())
                {
                    throw Exception("duplicate entry", 1);
                }

                // If there are no exceptions, the object is added to the data.
                this->setData(new Book(title, year, authors, tags));
            }
            catch (const Exception &e)  //if an exception is caught
            {
                if (e.getControl() == 1) //if exception type is 1 i.e. Duplicate Entry
                {
                    veriYaz << "Exception: " << e.getMessage() << endl; //the exception was written to the file.

                    veriYaz << "\"" << title << "\"" //all variables are written to the file.
                            << " \"" << authors << "\""
                            << " \"" << year << "\""
                            << " \"" << tags << "\"" << endl;
                }
                if (e.getControl() == 2) //if exception type is 2 i.e. Missing Field
                {
                    veriYaz << "Exception: " << e.getMessage() << endl; //the exception was written to the file.

                    if (quote == 6) //If the number of quote is 6, 3 variables are written.
                    {
                        veriYaz << "\"" << title << "\""
                                << " \"" << authors << "\""
                                << " \"" << year << "\""
                                << endl;
                    }
                    if (quote == 4) //If the number of quote is 4, 2 variables are written
                    {

                        veriYaz << "\"" << title << "\""
                                << " \"" << authors << "\"" << endl;
                    }
                    if (quote == 2) //If the number of quote is 2, 1 variables are written
                    {

                        veriYaz << "\"" << title << "\"" << endl;
                    }
                }
            }
        }
        
        //The number of objects added to the data is written to the file.
        veriYaz << data.size() << " unique entries" << endl; //

        string komutLine; //variable holding a command line.

        while (getline(komutAl, komutLine))  //line-by-line commands reading process begins.
        {

            try
            {
                string komut, searchWord, field, in; //temp variables.

                // komutLine = trim(komutLine);
                std::stringstream separation(komutLine); // An object has been created from the stringstream class
            // Because using this object we split the whole row into command variables.

                separation >> komut; //Firstly we learn the command what is
            

                if (komut == "search") //if command is search
                {   
                    //Since the word to be searched is in quotation marks and there may be a space in between,
                    // we transferred the quotation marks directly to the searchWord variable.
                    getline(separation, searchWord, '\"'); // split
                    getline(separation, searchWord, '\"'); // split

                    separation >> in >> field;  //getting other commands

                    
                    field = field.substr(1, field.size() - 2); //deleting quotes on both sides of field
                    
                    //if field is not matched , throws an exception
                    if (field != "title" && field != "year" && field != "authors" && field != "tags")
                    {
                        throw Exception("command is wrong", 3);
                    }

                    veriYaz << komutLine << endl; //if command is true then is written to file

                    string FieldValue; //temp Field variable

                    for (auto item : data) //For each loop for searching
                    {

                        if (field == "title") //Whatever field is, it is assigned to the fieldValue variable.
                        {
                            FieldValue = item->getTitle();
                        }
                        if (field == "year") //Whatever field is, it is assigned to the fieldValue variable.
                        {
                            FieldValue = item->getYear();
                        }
                        if (field == "authors") //Whatever field is, it is assigned to the fieldValue variable.
                        {
                            FieldValue = item->getAuthors();
                        }
                        if (field == "tags") //Whatever field is, it is assigned to the fieldValue variable.
                        {
                            FieldValue = item->getTags();
                        }

                        if (FieldValue.find(searchWord) != std::string::npos)
                        {   
                            //find process begins. if return of find function is not equal to npos ,
                            //find process is success. Because if there is not success , find function returns npos.
                            veriYaz << "\"" << item->getTitle() << "\""
                                    << " \"" << item->getAuthors() << "\""
                                    << " \"" << item->getYear() << "\""
                                    << " \"" << item->getTags() << "\"" << endl;
                            
                        }
                    }
                }
                if (komut == "sort")  //if command is sort
                {
                    separation >> field; //getting other commands

                    field = field.substr(1, field.size() - 2); //deleting quotes on both sides of field

                    //if field is not matched , throws an exception
                    if (field != "title" && field != "year" && field != "authors" && field != "tags")
                    {
                        throw Exception("command is wrong", 3);
                    }

                    veriYaz << komutLine << endl; //if command is true then is written to file

                    sort(field); //sort function is called.

                    for (auto item : data)                     //sorted data is writted to file.
                    {
                        veriYaz << "\"" << item->getTitle() << "\""
                                << " \"" << item->getAuthors() << "\""
                                << " \"" << item->getYear() << "\""
                                << " \"" << item->getTags() << "\"" << endl;
                    }

                }
            }


          

            catch (const Exception &e)    //if an exception is caught
            {
                if (e.getControl() == 3)  //if exception type is 3 i.e. Command Wrong
                {
                    veriYaz << "Exception: " << e.getMessage() << endl;
                    veriYaz << komutLine << endl;
                }
            }
        }
    }
    bool Book::operator==(const Book &other) const  //The Operator == is required to use in the find function (while searching).
    {
        
        //if both strings is same  and data is not empty.
         if (this->getTitle()==other.getTitle() && other.getTitle().empty() == false)
        {
            return true;
        }

        //if both strings is same  and data is not empty.
        if (this->getAuthors()==other.getAuthors() && other.getAuthors().empty() == false)
        {
            return true;
        }

        //if both strings is same  and data is not empty.
        if (this->getYear()==other.getYear() && other.getYear().empty() == false)
        {
            return true;
        }

        //if both strings is same  and data is not empty.
        if (this->getTags()==other.getTags() && other.getTags().empty() == false)
        {
            return true;
        }

        //if Find function is not successfull and data is empty.
        else
            return false;
    }

}