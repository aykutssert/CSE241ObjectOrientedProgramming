#include <iostream>
using namespace std;
#include "stack.h"
#include "stack.cpp"

int main()
{
    try{
        Stack<int> s;
        s.pop();
    }
    catch(PopEmptyStackException& e){
        cout<<"Empty Stack!\n";
    }
    try{
        Stack<char> s2;
        s2.push('a');
        s2.push('b');
        Stack<char> s3(s2);
       
        cout<<s2.pop()<<"-"<<s2.pop()<<endl;
        cout<<s3.pop()<<"-"<<s3.pop()<<endl;
        cout<<s2.pop();
    }
    catch(PopEmptyStackException& e){
        cout<<"Empty Stack!\n";
    }

}