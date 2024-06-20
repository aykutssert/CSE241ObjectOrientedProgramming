#include <iostream>
#include <cstring>
#include <cstdlib>
#include <ctime>
using namespace std;

void generateNumber(const int &length, char dizi[]) /////Generating a random unique number when the user enters -r.
{

    dizi[0] = rand() % +9 + 1 + 48; /// The first element of the array is randomly generated nonzero.
    int digit = 0;                  /// variable that holds a randomly drawn number
    int flag = 0;                   /// variable used for control in cases where the same digit is produced
    int count = 0;                  /// the variable I use when comparing the generated figure with the elements of the array


    for (int i = 1; i < length; i++) // Since we produce the first element outside of the loop, numbers starting from i=1 are produced as long as the length.
    {

        digit = rand() % +10; // A digit is generated at the beginning of each loop.
        flag = 0;             // is reset at the beginning of each cycle.
        while (flag == 0)
        {

            count = 0; // is reset at the beginning of each cycle.

            // loop where the generated digit is checked by the elements of the array
            for (int j = 0; j < i; j++) /// the loop should loop up to i because for example the length of the array is 6 but only 3 is full. No unnecessary looping.
            {
                if (digit == dizi[j] - 48) /// If the generated digit is the same as an element of the array, the loop is exited. is reproduced.
                {
                    digit = rand() % +10;
                    flag = 0;
                    break;
                }
                count++; // count is incremented by one if the generated digit is different from the element of the array
            }
            if (count == i) ////If the generated element is different from all the elements of the array, that number is transferred to the array and the loop starts again for the new element.
            {
                flag = 1; // to exit the while loop
            }


        }

        dizi[i] = digit + 48; // Since our array is char, we added 48 according to ascii code

    }

    dizi[length] = '\0'; // To terminate the char array.
}

void isUnique(char num[], const int &secretOfLength) /// For checking the number entered with -u and checking the number entered by the user
{

    const int uSerOflength = strlen(num); // Here we found the length of the number entered by the user, because user can enter a number with a different length than the secretnumber.
    int count = 0;                        // variable used for control

    if (num[0] == 45) /// For example, when the user enters -123, the invalid number E0 is returned instead of the E2 error. Because the number is negative. But '-' if something external is input, an E2 error is thrown.
    {
        for (int i = 1; i < uSerOflength; i++) // To check if the number is negative, only the leading element becomes - and if the others are digits this error is given.
        {
            if (num[i] >= 48 && num[i] <= 57) /// Checking for digits according to ascii code
                count++;
        }
        if (count == uSerOflength - 1)
        {
            cerr << "E0\n";
            exit(1);
        }
    }



    count = 0; // We reset the count variable to use it again.

    for (int i = 0; i < uSerOflength; i++) /// If there is a character in the array, an E2 error is given.
    {

        if (num[i] >= 48 && num[i] <= 57) ////Checking for digits according to ascii code
            count++;
    }
    if (count != uSerOflength)
    {
        cerr << "E2\n";
        exit(1);
    }



    if (uSerOflength != secretOfLength) // if numbers length does not match
    {
        cerr << "E1\n";
        exit(1);
    }



    if (num[0] == 48) // if the length matches but there is a leading zero.
    {
        cerr << "E0\n";
        exit(1);
    }



    for (int i = 0; i < uSerOflength; i++) // nested loop we use to compare the elements of the array with their own elements
    {
        for (int j = i + 1; j < uSerOflength; j++) // for the unnecessary loop it starts at j=i+1.
        {
            if (num[i] == num[j]) // if everything is ok but the numbers are repeating.
            {
                cerr << "E0\n";
                exit(1);
            }
        }
    }



}

void game(char secretNumber[], const int &length)
{


    int Cexact = 0;          // for correct numbers
    int Cmisplaced = 0;      // the location is not correct but for the digits in the array
    int iter = 0;            // The variable that holds the number of attempts. If it exceeds 100, it's game over.
    char userNumber[length]; // The char array created to receive input from the user.


    do                       // Check for each user login.
    {

        Cexact = 0;
        Cmisplaced = 0;
        iter++;

        if (iter > 100) // If the iteration variable is 100, the game is over.
        {
            cout << "FAILED\n";
            exit(1);
        }


        cin >> userNumber;
        isUnique(userNumber, length); /// Checking whether the number received from the user is unique.


        for (int i = 0; i < length; i++) // Controlling the number of secrets with user input.
        {

            if (secretNumber[i] == userNumber[i]) // Cexact increments by one if location is true the correct number of times.
                Cexact++;

            for (int j = 0; j < length; j++)
            {
                if (i != j)
                {
                    if (secretNumber[i] == userNumber[j]) // If the number is found, there is no need to print the Cexact and Cmissplaced values.
                        Cmisplaced++;
                }
            }
        }


        if (Cexact != length) // If the number is found, there is no need to print the Cexact and Cmissplaced values.
            cout << Cexact << " " << Cmisplaced << endl;


    } while (Cexact != length); /// If Cexact has not reached the length of the secret number, the game is not over.
    

    cout << "FOUND " << iter << endl;
}

int main(int argc, char **argv)//int argc The number of elements entered into the terminal.char argv is the array where the elements entered into the terminal are kept as index.
{

    srand(time(NULL)); // The expression is used to generate different random numbers each time by specifying a different initial value each time it is run.

    if (argc != 3) // If 3 elements are not entered in the terminal, there will be a missing element.
    {
        cerr << "E0\n";
        exit(0);
    }

    else
    {

        if (strcmp(argv[1], "-r") == 0 && strlen(argv[2]) == 1) // if -r and 1 element entered
        {

            const int SecretOflength = atoi(argv[2]); // variable that holds the length of the number entered into the terminal

            if (SecretOflength > 0 && SecretOflength <= 9) // if the entered element is between 0 and 10
            {

                char secretNumber[SecretOflength]; // variable that holds the random number to be generated

                generateNumber(SecretOflength, secretNumber); // random number generation

                game(secretNumber, SecretOflength); // playing the game
            }

            else
            {
                cerr << "E0\n";
                exit(0);
            }
        }

        else if (strcmp(argv[1], "-u") == 0) // if -u entered in terminal
        {
            const  int SecretOflength = strlen(argv[2]); // variable that holds the length of the number entered into the terminal

            if (SecretOflength > 9) // Since our number will be 9 digits max, if it exceeds 9, it will give an error.
            {
                cerr << "E0\n";
                exit(1);
            }

            isUnique(argv[2], SecretOflength); // Checking whether the number entered manually in the terminal is unique or not

            char secretNumber[SecretOflength]; // The variable that keeps the secret number

            strcpy(secretNumber, argv[2]); // If the number is unique after the checks, it is copied to the char array with the strcpy function.

            game(secretNumber, SecretOflength); ////playing the game
        }

        else
        {
            cerr << "E0\n";
            exit(0);
        }
    }
}
