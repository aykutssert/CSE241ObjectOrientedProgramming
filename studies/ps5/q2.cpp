#include <iostream>
#include <string>

using namespace std;

class Student
{

public:
    Student() // Default Constructor
    {
        name = "";
        numClasses = 0;
    }

    void InputDataa() // Input
    {

        cout << "Enter Name:";
        getline(cin, name);
        cout << "Enter numClasses:";
        cin >> numClasses;
        cin.ignore(); // tam anlamadım araştır!

        classList = new string[numClasses]; // allocate memory

        for (int i = 0; i < numClasses; ++i)
        {
            string className;
            cout << "Enter Class Name:";
            getline(cin, className);

            classList[i] = className;
        }
    }
    void OutputDataa() const // Output
    {
        cout << "Name: " << name << endl;
        cout << "Classes:" << endl;
        for (int i = 0; i < numClasses; ++i)
        {
            cout << "- " << classList[i] << endl;
        }
    }

    const Student &operator=(const Student &other) // Assign overloading
    {
        if (this != &other) // no action needed if addresses are the same
        {
            name = other.name;

            numClasses = other.numClasses;

            delete[] classList;
            classList = new string[numClasses];
            for (int i = 0; i < numClasses; ++i)
            {
                classList[i] = other.classList[i];
            }
            return *this;
        }
        else
            return *this;
    }
    void ResetClasses() //Reset
    {
        numClasses = 0;
        if (classList != nullptr)
        {
            delete[] classList;
            classList = nullptr;
        }
    }
    ~Student() //Destructor
    {
        delete[] classList;
    }

private:
    string name;
    int numClasses;
    string *classList;
};

int main()
{

    Student s1, s2;

    s1.InputDataa();

    cout << "Student 1's data:\n";
    s1.OutputDataa();
    cout << endl;


    s2 = s1;
    cout << "Student 2's data after assignment from student 1:" << endl;
    s2.OutputDataa(); // Should output same data as for student 1


    s1.ResetClasses();
    cout << "Student 1's data after reset:" << endl;
    s1.OutputDataa(); // Should have no classes

    
    cout << "Student 2's data, should still have original classes:" << endl;
    s2.OutputDataa(); // Should still have original classescout << endl;

    return 0;
}