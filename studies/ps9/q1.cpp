#include <iostream>
#include <string>

using std::cin;
using std::cout;
using std::endl;

#include "pfarrayd.h"
#include "pfarrayd.cpp"

void testPFArrayD()
{

    int cap;
    cout << "Enter capacity of this superarray: ";

    cin >> cap;
    PFArrayD temp(cap);

    cout << "Enter up to " << cap << " non-negative numbers.\n";
    cout << "Place a negative number at the end.\n";
    double next;
    cin >> next;

    while (next >= 0 && !temp.full())
    {
        try
        {
            temp.addElement(next);
        }
         catch (OutOfRange& e)
        {
            cout << endl
                 << e.getMessage() << "  " << e.getIndex() << endl;
                 exit(1);
        }
        catch (Exception& e)
        {
            cout <<"exception"<<endl;
            throw e;
        }
       
      
        cin >> next;
    }
    cout << "You entered the following " << temp.getNumberUsed() << " numbers:\n";
    int index;
    int count = temp.getNumberUsed();
    for (index = 0; index < count; index++)
    {
        try
        {
            cout << temp[index] << " ";
            cout << endl;
            cout << "(plus a sentinel value.)\n";
        }
        catch (OutOfRange &e)
        {
            cout << endl
                 << e.getMessage() << "  " << e.getIndex() << endl;
        }
    }

    try
    {
        cout << temp[-1]; // Will throw OutOfRange exception
    }
    catch (OutOfRange &e)
    {
        cout << endl
             << e.getMessage() << "  " << e.getIndex() << endl;
    }
    try
    {
        temp.addElement(99999); // Will throw OutOfRange exception
    }
    catch (OutOfRange &e)
    {
        cout << endl
             << e.getMessage() << "  " << e.getIndex() << endl;
        exit(1);
    }
}

int main()
{
    cout << "This program tests the class PFArrayD.\n";
    char ans;
    do
    {
        testPFArrayD();
        cout << "Test again ?(y/n)";
        cin >> ans;
    } while ((ans == 'y') || (ans == 'Y'));

    return 0;
}