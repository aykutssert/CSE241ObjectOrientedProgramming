#include <iostream>
#include <string>
using namespace std;

class DynamicStringArray
{

private:
    string *dynamicArray; //dynamic array.

    int size; //number of array

public:

    DynamicStringArray() //  Default
    {
        dynamicArray = nullptr;
        size = 0;
    }

    
    DynamicStringArray(const DynamicStringArray &cpy)// Copy constructor
    {
        size = cpy.getSize();

        dynamicArray = new string[size];

        for (int i = 0; i < size; i++)
        {
            //dynamicArray[i] = cpy.dynamicArray[i];
            dynamicArray[i] = cpy.getEntry(i);
        }

    }

   
    DynamicStringArray &operator=(const DynamicStringArray &other)  // Assignment operator
    {
        if (this != &other) //If the addresses are the same, there is no need.
        {
            delete[] dynamicArray;

            size = other.getSize();

            dynamicArray = new string[size];

            for (int i = 0; i < size; i++)
            {
                dynamicArray[i] = other.getEntry(i);
            }
        }
        return *this;
    }

    
    int getSize() const //Getter for size
    {
        return size;
    }

    
    void addEntry(const string &s)// Add 
    {
        string *temp = new string[size + 1];

        for (int i = 0; i < size; i++)
        {
            temp[i] = dynamicArray[i];
        }

        temp[size] = s;

        delete[] dynamicArray;

        dynamicArray = temp;

        size++;
    }

    bool deleteEntry(const string &s) // Delete 
    {
        int hangisi = size + 1;
        for (int i = 0; i < size; i++)
        {
            if (dynamicArray[i] == s)
            {
                hangisi = i;
                break;
            }
        }


        if (hangisi == size + 1)
        {
            return false;
        }


        string *temp2 = new string[size - 1];
        for (int i = 0; i < hangisi; i++)
        {
            temp2[i] = dynamicArray[i];
        }


        for (int i = hangisi + 1; i < size; i++)
        {
            temp2[i - 1] = dynamicArray[i];
        }


        delete[] dynamicArray;

        dynamicArray = temp2;

        size--;

        return true;
    }

    string getEntry(int index) const // Get entry
    {
        if (index < 0 || index >= size)
        {
            return nullptr;
        }

        return dynamicArray[index];
    }

    ~DynamicStringArray() // Destructor
    {

        delete[] dynamicArray;
    }
};

int main()
{
     // List of names
    DynamicStringArray names;
    names.addEntry("Frank");
    names.addEntry("Wiggum");
    names.addEntry("Nahasapeemapetilon");
    names.addEntry("Quimby");
    names.addEntry("Flanders"); 


    // Output list
    cout << "List of names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl; 



    // Add and remove some names
    names.addEntry("Spuckler");
    cout << "After adding a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;


    names.deleteEntry("Nahasapeemapetilon");
    cout << "After removing a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;


    names.deleteEntry("Skinner");
    cout << "After removing a name that isn't on the list:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;



    names.addEntry("Muntz");
    cout << "After adding another name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl; 


    // Remove all of the names by repeatedly deleting the last one
    while (names.getSize() > 0)
    {
        names.deleteEntry(names.getEntry(names.getSize() - 1));
    }

    cout << "After removing all of the names:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;


    names.addEntry("Burns");
    cout << "After adding a name:" << endl;
    for (int i = 0; i < names.getSize(); i++)
        cout << names.getEntry(i) << endl;
    cout << endl;


    cout << "Testing copy constructor" << endl;
    DynamicStringArray names2(names); 
    
    // Remove Burns from names
    names.deleteEntry("Burns");
    cout << "Copied names:" << endl;
    for (int i = 0; i < names2.getSize(); i++)
        cout << names2.getEntry(i) << endl;
    cout << endl;


    cout << "Testing assignment" << endl;
    DynamicStringArray names3 = names2; // Remove Burns from names2
    names2.deleteEntry("Burns");

    cout << "Copied names:" << endl;
    for (int i = 0; i < names3.getSize(); i++)
        cout << names3.getEntry(i) << endl;
    cout << endl;


    cout << "Enter a character to exit." << endl;
    char wait;
    cin >> wait;
    return 0;
}