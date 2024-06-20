#ifndef PFARRAYD_H
#define PFARRAYD_H

#include <string>
using std::string;

class Exception
{
};

class OutOfRange : public Exception
{
public:
    OutOfRange(string thisMessage, int thisIndex);
    string getMessage() const;
    int getIndex() const;

private:
    string message;
    int index;
};

class PFArrayD
{
public:
    PFArrayD();
    // I n i t i a l i z e s  with a capacity  of  50.
    PFArrayD(int capacityValue);
    PFArrayD(const PFArrayD &pfaObject);
    void addElement(double element);
    // Precondition :The array  is  not  full.
    // Postcondition :The element  has  been added .
    bool full() const { return (capacity == used); } // Returns  true  i f  the  array  i s  f u l l ,  f a l s e  otherwise .
    int getCapacity() const { return capacity; }
    int getNumberUsed() const { return used; }
    void emptyArray() { used = 0; } // Empties  the  array .
    double &operator[](int index);  // Read and change  access  to  elements 0 through numberUsed−1.
    PFArrayD &operator=(const PFArrayD &rightSide);
    ~PFArrayD();

private:
    double *a;    // for  an array  of  doubles .
    int capacity; // for  the  s i z e  of  the  array .
    int used;     // for  the number of  array  positions  currently  in  use .
};
#endif