#include <iostream>

using namespace std;

class Vector2D
{

private:
    int x, y; //width and height for two dimensional vector

public:
    Vector2D() // Default Constructor
    {
        x = 0;
        y = 0;
    };
    Vector2D(const int _x, const int _y) // Set Constructor
    {
        x = _x;
        y = _y;
    }
    inline int GetX() const // getter for X
    {
        return x;
    }
    void SetX(int x) // Setter for X
    {
        x = x;
    }
    inline int GetY() const // getter for Y
    {
        return y;
    }
    void SetY(int y) // Setter for Y
    {
        y = y;
    }

    // it returns the dot product of two dimensional vectors.
    int operator*(const Vector2D &other) const
    {
        return x * other.x + y * other.y;
    }
};

int main()
{
    Vector2D v1(5, 7), v2(1, 10), v3(10, 5), v4(2, 4);

    cout << "(" << v1.GetX() << "," << v1.GetY() << ") * (" << v2.GetX() << "," << v2.GetY() << ") = " << v1 * v2 << endl;
    cout << "(" << v2.GetX() << "," << v2.GetY() << ") * (" << v3.GetX() << "," << v3.GetY() << ") = " << v2 * v3 << endl;
    cout << "(" << v3.GetX() << "," << v3.GetY() << ") * (" << v4.GetX() << "," << v4.GetY() << ") = " << v3 * v4 << endl;

    return 0;
}
