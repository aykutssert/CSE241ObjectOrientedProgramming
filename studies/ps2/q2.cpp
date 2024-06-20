#include <iostream>
#include <cstring>

using namespace std;


void ters(char arr[],const int& n) {

    int temp;
    for(int i=0; i<n/2;i++){
        temp=arr[i];
        arr[i]=arr[n-i-1];
        arr[n-i-1]=temp;
    }

}

void ekleme(char a[],char b[],char result[]) {
    int carry = 0;
    for (int i=0;i<20;i++) {
        int sum=carry;
        if (a[i]!='\0') {            //If the elements of the array we are trying to access are null characters, we do not take those parts.
            sum+=(a[i]-'0');
        }
        if (b[i]!='\0') {            //If the elements of the array we are trying to access are null characters, we do not take those parts.
            sum+=(b[i]-'0');
        }
        if (sum>9) {
            carry=1;
            sum-=10;    ///For example, the sum is 12, the carry becomes 1, the sum becomes 2.
        } else {
            carry =0;    ////If sum does not exceed 9, carry does not occur.
        }
        result[i]=sum+'0';
    }
    if (carry==1) {
        cout<<"Integer overflow. Because totaled more than 20 digits."<<endl;
    }
}

int main() {
    char a[20];
    char b[20];
    char res[20];
    char c;

    do {

        cout<< "enter the first number.Max 20 digits: ";  ////directly into the char array.
        cin>>a;
        while(strlen(a)>20){
            cout<<"enter the first number again please(Max digit:20):";
            cin>>a;
        }
        cout<< "enter the second number.Max 20 digits: ";     ////directly into the char array.
        cin>>b;
        while(strlen(b)>20){
            cout<<"enter the second number again please(Max digit:20):";
            cin>>a;
        }

        ters(a, strlen(a));  //Reverse for firstnumber
        ters(b, strlen(b));     //Reverse for secondnumber

        cout<<"Reverse first number: "<<a<<endl;
        cout<<"Reverse second number: "<<b<<endl;

        ekleme(a, b, res);  ///add reversed two numbers

        ters(res, strlen(res));   ///reversing the summed number

        cout<<"the sum is: "<<res<<endl;

        cout<<"do you want to continue? (y-Y/n-N)";
        cin>>c;
    } while(c=='y' || c=='Y');

    return 0;
}
