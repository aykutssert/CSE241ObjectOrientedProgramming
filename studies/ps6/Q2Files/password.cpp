#include <iostream>
#include <string>
#include "password.h"
using namespace std; // for cout,cin,endl.

namespace Authenticate
{

    namespace
    { // unnamed spaces and  a defined string and isvalid function

        string password;

        bool isValid()
        {

            if (password.length() < 8) //at least 8 character
            {
                return false;
            }

            bool isThereNon_letter = false;
            for (char c : password) 
            {
                if (!isalpha(c)) //Checks whether c is an alphabetic letter.
                {
                    isThereNon_letter = true;
                    break;
                }
            }
            return isThereNon_letter;
        }
    }

    void inputPassword()
    {

        do
        {
            cout << "Enter your password (at least 8 characters and at least one non-letter): " << endl;
            cin >> password;
        } while (!isValid());
    }

    string getPassword() 
    {
        return password;
    }
}