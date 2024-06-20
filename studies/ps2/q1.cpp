#include <iostream>
#include <cstdlib> 
#include <ctime>

using namespace std;


//If the random answer is zero, the shot is successful.
int duello() {
    bool aaron_alive=true;
    bool bob_alive=true;
    bool charlie_alive=true;

    while(true){
        if(aaron_alive){   ///Aaron shoots charlie first because he has the highest probability of success
           
            if(charlie_alive){
                if(rand() % 3==0){  //If Aaron gets random=0  of 3 shots, he hits his opponent.
                    charlie_alive=false;   //If Aaron shoots successfully, Charlie gets shot.
                }
            }else if(bob_alive) {
                if (rand() % 3==0){   //If Aaron gets random=0  of 3 shots, he hits his opponent.
                    bob_alive=false;   //If Aaron shoots successfully, Bob gets shot.
                }
            }else{  ///bob and charlie, if both are dead.
                
                return 1;
            }
        }

        if(bob_alive){    ///Bob shoots charlie first because he has the highest probability of success
           
            if(charlie_alive){
                if(rand() % 2==0){   //If Bob gets random=0 of 2 shots, he hits his opponent.
                    charlie_alive=false;   //If Bob shoots successfully, Charlie gets shot.
                }
            }else if (aaron_alive){
                if(rand() % 2==0){   //If Bob gets random=0 2 shots, he hits his opponent.
                    aaron_alive=false;  //If Bob shoots successfully, Aaron gets shot.
                }
            }else{  ///aaron and charlie, if both are dead.
                
                return 2;
            }
        }

        if(charlie_alive){   ///charlie hits bob first because he's the most successful after him.
            
            if(bob_alive){          ////There is no need for probability for Charlie because she always shoots well.

                bob_alive=false;   //if bob is alive then it's charlie's turn bob is definitely shot.

            }else if (aaron_alive){   //There is no need for probability for Charlie because she always shoots well.
                aaron_alive=false;     //if aaron is alive then it's charlie's turn aaron is definitely shot.

            }else{  ///aaron and bob, if both are dead.
               
                return 3;
            }
        }
    }
}

int main(){
    
    srand(time(nullptr));  //for random function.

   
    int aaron_wins=0;
    int bob_wins=0;
    int charlie_wins=0;

    cout<<"once for testing\n";
    int test=duello();
     if(test==1) {
            cout<<"Aaron won\n";
        } 
        else if(test==2) {
            cout<<"Bob won\n";
        }
        else{
            cout<<"Charlie won\n";
    }
        cout<<"\n\n\nReal Game\n\n";

    for(int i=0; i<10000;i++) {
        int winner=duello();

        if(winner==1) {
            aaron_wins++;
        } 
        else if(winner==2) {
            bob_wins++;
        }
        else{
            charlie_wins++;
        }
    }

    cout<<"Aaron won "<<aaron_wins<<"/10000 duels or "<< static_cast<double>(aaron_wins)/100<<"%\n";  ///I cast it to get a comma percentile.
    cout<<"Bob won "<<bob_wins<<"/10000 duels or "<< static_cast<double>(bob_wins)/100<<"%\n";
    cout<<"Charlie won "<<charlie_wins<<"/10000 duels or "<< static_cast<double>(charlie_wins)/100<<"%\n";

    return 0;
}
