#ifndef CATALOG_H
#define CATALOG_H
#include <string>
#include <vector>

using std::string;
using std::vector;

namespace CatalogSpace // namespace for catalog class and exception class
{

    template <class T> // Template Catalog Class
    class Catalog
    {
    private:
        string title; // common variable title
        string year;  // common variable year

    protected:
        vector<T *> data;

    public:
        Catalog(string _title, string _year) : title(_title), year(_year) {}  // Constructor
        virtual void read(const string filename, const string filename2) = 0; // Read function
        virtual bool operator==(const T &other) const = 0;                    // Sort function by given field
        virtual void sort(const string field) = 0;                            // The Operator == is required to use in the find function (while searching).
        

        virtual void setData(T *item) { data.push_back(item); } // setter for data
        virtual string getTitle() const { return title; }       // getter for title
        virtual string getYear() const { return year; }         // getter for year
        string trim(const std::string &str);                    // delete spaces on both sides of a string.
        virtual ~Catalog();                                     // Destructor
    };

    // for exceptions
    class Exception
    {
    private:
        string message; // Exception Message
        int control;    // which exception will be thrown? for control

    public:
        Exception();
        Exception(string _message, int _control) : message(_message), control(_control) {} // Exception Constructor
        string getMessage() const { return message; }                                      // getter for message
        int getControl() const { return control; }                                         // getter for control
        void setControl(const int _control) { control = _control; }                        // setter for control
        void setMessage(const string _message) { message = _message; }                     // setter for message
    };

}
#endif