#include <iostream>
#include <string>
#include "stack.h"
using namespace std;



template <class T>
Stack<T>::Stack(){
top=nullptr;
}

template <class T>
void Stack<T>::push(T stackFrame)
{
    top = new Node<T>(stackFrame, top);
}

template <class T>
T Stack<T>::pop(){
    if(isEmpty()){
        throw PopEmptyStackException();
    }
    else{
        Node<T> *temp = top;
        T tempData=temp->getData();
        top=top->getLink();
        delete temp;
        return tempData;
    }
}

template <class T>
bool Stack<T>::isEmpty() const
{
    return (top == nullptr);
}

template <class T>
Stack<T>::Stack(const Stack<T> &aStack)
{
    if (aStack.isEmpty())
    {
        top = nullptr;
    }
    else
    {
        Node<T> *temp = aStack.top; 
        Node<T> *end; 
        end = new Node<T>(temp->getData(), nullptr);
        top = end;
       
        temp = temp->getLink();
        while (temp != nullptr)
        {
            end->setLink(new Node<T>(temp->getData(), nullptr));
            end = end->getLink();
            temp = temp->getLink();
        }
    }
}

template <class T>
Stack<T> &Stack<T>::operator=(const Stack<T> &rightSide)
{
    if (top == rightSide.top) // if two stacks are the same
        return *this;
    else
    { 
        // deallocate 
        Node<T> *temp;
        while (top != nullptr)
        {
            temp = top;
            top = top->getLink();
            delete temp;
        }
        // new stack
        if (rightSide.top == nullptr)
        {
            top = nullptr;
            return *this;
        }
        else
        { 
            // copy first node
            top = new Node<T>(rightSide.top->getData(), nullptr);
            Node<T> *lastPtr = top;
            // copy rest of stack
            Node<T> *origPtr = rightSide.top->getLink();
            while (origPtr != nullptr)
            {
                lastPtr->setLink(new Node<T>(origPtr->getData(), nullptr));
                lastPtr = lastPtr->getLink();
                origPtr = origPtr->getLink();
            }
            return *this;
        }
    }
}

template <class T>
Stack<T>::~Stack()
{
    Node<T> *temp;
    while (top != nullptr)
    {
        temp = top;
        top = top->getLink();
        delete temp;
    }
}
