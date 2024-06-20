#include <iostream>
#include <string>
#include "user.h"

using namespace std; // for cout,cin,endl.
namespace Authenticate
{

    namespace
    { // unnamed spaces and  a defined string and isvalid function

        string username;
        bool isValid()
        {
            return (username.length() == 8); // it must be 8.
        }
    }

    void inputUserName()
    {
        do
        {
            cout << "Enter your username (8 letters only): " << endl;
            cin >> username;
        } while (!isValid());
    }

    string getUserName()
    {
        return username;
    }
}