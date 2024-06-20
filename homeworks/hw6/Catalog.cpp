#include "Catalog.h"
#include <algorithm>
namespace CatalogSpace
{

    template <class T>
    string Catalog<T>::trim(const std::string &str) //delete spaces on both sides of a string.
    {
        std::string result = str; //Temp variable

        //The part up to where there is no space is deleted.
        result.erase(result.begin(), std::find_if(result.begin(), result.end(), [](unsigned char ch)
                                                  { return !std::isspace(ch); })); 

        //The part up to where there is no space is deleted.
        result.erase(std::find_if(result.rbegin(), result.rend(), [](unsigned char ch){ return !std::isspace(ch); }).base(),result.end());

        return result;
    }

    
    template <class T>
    Catalog<T>::~Catalog() //Destructor
    {

        // Release all items in data vector
        for (T *item : data)
        {
            delete item;
        }
        // clear data vector
        data.clear();
    }

}