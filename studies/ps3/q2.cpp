#include <iostream>
#include <vector>

using namespace std;

int main() {
    int n;
    std::cout << "Enter the vector size: "; 
    cin >> n;   //vector size

    if(n==1){                 ///if n ise 1.
        std::cout<<"Winner is "<<n<<endl;
    }
    else if(n<=0){             //if n is zero or negative.
        std::cout<<"Not enough suitors\n";
    }
    else{

    vector<int> v(n);  //vector fill process
    for (int i = 0; i < n; i++) {
        v[i] = i + 1;
    }

    int count = 0;           //variable i keep to go 3 steps at a time   

    int where = 0;              //the variable I keep to show where I'm staying.
                               //And I'm going to get this variable back to the beginning of the vector with the mod operation.


    for (int i = 0;i < n;i++) { //First, the loop returns the size.

        count = 0;

        for (int j = where;j < n+i;j++){
            
            count++;  

            if (count == 3) {    //When count is 3, the transaction takes place.

                j = j % v.size();   //so that the j value does not exceed the array size ////********this is the most important.

                where = j;           //to find where I've been                       

                 if (v.size() != 1) { ///I print until 1 element remains in the array
                     for (int i = 0;i < v.size();i++) {
                         std::cout << v[i];
                     }
                 }

                if (v.size() != 1){   //I delete until 1 element remains in the array
                    std::cout << " eliminated " << v[j];
                    v.erase(v.begin() + j);
                    break;
                }

            }
           

    }
        std::cout << endl;

    }

    std::cout << "the luckiest one is #" << v[0] << endl;   //print the winner.
    }
    return 0;
}