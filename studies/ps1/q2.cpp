#include <iostream>
#include <stdlib.h>
#include <time.h>
using namespace std;

int humanTurn(int humanTotalScore)
{

    char input;        // Roll or Hold
    int turnTotal = 0; // the number to be added to the total score

    do
    {
        int roll = rand() % 6 + 1;  //Create random numbers
        cout << "YOu rolled a " << roll << "." << endl;
        if (roll == 1)
        {
            cout << "You lose your turn." << endl;
            cout << "Human's total score is " << humanTotalScore << "." << endl;
            return 0;
        }
        turnTotal += roll;
        cout << "Your turn total is " << turnTotal << "." << endl;
        cout << "Enter 'r' to roll again or 'h' to hold." << endl;
        cin >> input;

    } while (input == 'r' || input == 'R');

    humanTotalScore += turnTotal;
    cout << "Human's total score is " << humanTotalScore << "." << endl;
    return turnTotal;
}
int computerTurn(int computerTotalScore)
{
    
    int turnTotal = 0; 

    do
    {
        int roll = rand() % 6 + 1;
        cout << "The computer rolled a " << roll << "." << endl;
        if (roll == 1)
        {
            cout << "The computer loses its turn." << endl;
            cout << "Computer's total score is " << computerTotalScore << "." << endl;
            return 0;
        }
        turnTotal += roll;
        cout << "The computer's turn total is " << turnTotal << "." << endl;
    } while (turnTotal < 20);

    computerTotalScore += turnTotal;
    cout << "Computer's total score is " << computerTotalScore << "." << endl;
    return turnTotal;
}

int main()
{
    srand(time(nullptr));
    int humanTotalScore = 0;
    int computerTotalScore = 0;

    while (humanTotalScore < 100 && computerTotalScore < 100)
    {
        cout << "----------Human's turn---------" << endl;
        int humanTurnTotal = humanTurn(humanTotalScore);
        humanTotalScore += humanTurnTotal;

        if (humanTotalScore >= 100)
        {
            break; //to prevent the computer from playing if the human's score exceeds 100
        }
        cout << "-------------------------------\n"
             << endl;
        cout << "------------Computer's turn.---" << endl;
        int computerTurnTotal = computerTurn(computerTotalScore);
        computerTotalScore += computerTurnTotal;
        cout << "-------------------------------\n"
             << endl;
    }

    if (humanTotalScore >= 100)
    {
        cout << "Human win!" <<endl;
    }
    else
    {
        cout << "The Computer wins!" <<endl;
    }

    return 0;
}