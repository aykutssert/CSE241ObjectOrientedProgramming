#include <iostream>

using namespace std;

class MyInteger
{
public:
    MyInteger() { value = 0; } // Default Constructor
    MyInteger(int _value)      // Set Constructor
    {

        value = _value;
    }

    inline int get() const // getter
    {
        return value;
    }

    void set(int value) // setter
    {
        value = value;
    }

    int operator[](int index) const
    {
        if (index < 0)
        {
            return -1;
        }

        /*
        int basamak = 0;
        int temp = value;
        while (temp > 0)
         {
             temp = temp / 10;
             basamak++;
         }
         if (index >= basamak)
         {
             return -1;
        }*/

        int temp2 = value;
        int i = 0; // for error control
        int digit; // variable that holds the desired place value

        while (i <= index) // If i and index are equal, it means that the first digit of the number is requested.
        {
            digit = temp2 % 10; // find the last digit value

            temp2 = temp2 / 10; // get rid of last digit by dividing number by 10

            if (temp2 == 0 && i < index) // if the number is zero and the index is greater than i, the place value is exceeded
            {
                return -1;
            }
            i++;
        }
        return digit;
    }

private:
    int value; // My integer value
};

int main()
{
    // Some test numbers
    MyInteger num(942);
    MyInteger num2;
    cout << num[0] << " " << num[1] << " " << num[2] << endl;

    cout << num[3] << endl;
    cout << num[-1] << endl;

    return 0;
}
