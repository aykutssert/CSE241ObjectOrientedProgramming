
#include <iostream>
using namespace std;

int main()
{

    bool flag; // flag for prime or not prime

    cout << "Asal sayilar: " << endl;

    for (int i = 3; i <= 100; i++)  //between 3 - 100
    {
        flag = true;

        for (int j = 2; j <= i / 2; j++)//In terms of efficiency, it is enough to go up to half of our number.
        {
            if (i % j == 0) 
            {
                flag = false;
                break;
            }
        }

        if (flag) //flag is true then number is prime
            cout << i << "-";
    }
}
