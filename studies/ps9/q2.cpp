#include <iostream>
#include <string>
using namespace std;

namespace
{
   
    void funk(int growing,int constant)
    {
        
        if (growing == constant)
        {
            throw growing;
        }
        else
            funk(growing+1,constant);
    }
}

int main()
{
    int catch_level;
    cout << "Enter the depth: ";
    cin >> catch_level;

    try
    {   
        if(0==catch_level){
            throw 0;
        }
        else funk(0,catch_level);
    }
    catch (int e)
    {
        cout << "Caught exception caught: " << e << std::endl;
    }

    return 0;
}
