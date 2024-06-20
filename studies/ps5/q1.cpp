#include <iostream>
#include <cmath>
using namespace std;
class Polynomial
{
public:
    Polynomial() //Default Constructor
    {
        coeff = nullptr;
        degree = 0;
    }
    Polynomial(const double *arr, int other_degree) //Parameterized Constructor
    {
        degree = other_degree;
        coeff = new double[degree + 1];

        for (int i = 0; i < degree; i++)
        {
            coeff[i] = arr[i];
        }
    }
    Polynomial(const Polynomial &other) //copy constructor
    {
        degree = other.degree;
        coeff = new double[degree + 1];
        for (int i = 0; i <= degree; i++)
        {
            coeff[i] = other.coeff[i];
        }
    }

    const Polynomial &operator=(const Polynomial &other) //operator=
    {
        if (this != &other)
        {
            delete[] coeff;
            degree = other.degree;
            coeff = new double[degree + 1];

            for (int i = 0; i < degree; i++)
            {
                coeff[i] = other.coeff[i];
            }
        }
        return *this;
    }

    //This version of operator[] is used when an indexed//expression is used as an l-value.
    double &operator[](int index)
    {

        if (index < 0 || index > degree)
        {
            cout << "Error\n";
            exit(1);
        }
        return coeff[index];
    }

    //This version of operator[] is used when an indexed//expression is used as an r-value.
    const double &operator[](int index) const
    {

        if (index < 0 || index > degree)
        {
            cout << "Error\n";
            exit(1);
        }
        return coeff[index];
    }
    friend double evaluate(const Polynomial &current, double x) //function to evaluate polynomial as a value of type double
    {

        double result = 0;
        for (int i = 0; i < current.degree; i++)
        {
            result += current.coeff[i] * std::pow(x, i);
        }
        return result;
    }

    friend Polynomial operator+(const Polynomial &other, const Polynomial &other2) //operator+
    {
        int deg = other2.degree >= other.degree ? other2.degree : other.degree;
        double *arr = new double[deg + 1];
        for (int i = 0; i <= deg; i++)
        {
            arr[i] = (i <= other.degree ? other.coeff[i] : 0) + (i <= other2.degree ? other2.coeff[i] : 0);
        }
        Polynomial result(arr, deg);
        delete[] arr;
        return result;
    }

    friend Polynomial operator-(const Polynomial &other, const Polynomial &other2) //operator-
    {
        int deg = other2.degree >= other.degree ? other2.degree : other.degree;
        double *arr = new double[deg + 1];
        for (int i = 0; i <= deg; i++)
        {
            arr[i] = (i <= other.degree ? other.coeff[i] : 0) - (i <= other2.degree ? other2.coeff[i] : 0);
        }
        Polynomial result(arr, deg);
        delete[] arr;
        return result;
    }
    friend Polynomial operator*(const Polynomial &other, const Polynomial &other2) //operator*
    {
        int deg = other.degree + other2.degree-1;
        double *arr = new double[deg + 1];
        for (int i = 0; i <= deg; i++)
        {
            arr[i] = 0;
            for (int j = 0; j <= i; j++)
            {
                arr[i] += (j <= other.degree ? other.coeff[j] : 0) * (i - j <= other2.degree ? other2.coeff[i - j] : 0);
            }
        }
        Polynomial result(arr, deg);
        delete[] arr;
        return result;
    }

    ~Polynomial() //destructor
    {

        delete[] coeff;
    }

    int mySize()const{ //Getter Size
        return degree;
    }

private:
    double *coeff;
    int degree;
};

int main()
{
    Polynomial empty;
    double one[] = {5};
    Polynomial One(one, 1);
    double quad[] = {2, 1, 2};
    double cubic[] = {1, 2, 1, 1};
    Polynomial q(quad, 3);
    Polynomial c(cubic, 4);
    Polynomial p = q; // Test Copy Construtor
    Polynomial r;

    r = q; // Test operator=
    r = c;

    cout << "Polynomial q" << endl;
    for (int i = 0; i < 3; i++)
    {
        cout << "term with degree " << i << " has coefficient " << q[i] << endl;
    }

    cout << "Polynomial c " << endl;
    {
        for (int i = 0; i < 4; i++)
            cout << "term with degree " << i << " has coefficient " << c[i] << endl;
    }

    cout << "value of q(2) is " << evaluate(q, 2) << endl;
    cout << "value of p(2) is " << evaluate(p, 2) << endl;
    cout << "value of r(2) is " << evaluate(r, 2) << endl;
    cout << "value of c(2) is " << evaluate(c, 2) << endl;

    r = q + c;
    cout << "value of (q + c)(2) is " << evaluate(r, 2) << endl;
    r = q - c;
    cout << "value of (q - c)(2) is " << evaluate(r, 2) << endl;

    r = q * c;
    cout << "size of q*c is " << r.mySize() << endl;

    cout << "Polynomial r (= q*c) " << endl;

    for (int i = 0; i < r.mySize(); i++)
        cout << "term with degree " << i << " has coefficient " << r[i] << endl;
    cout << "value of (q * c)(2) is " << evaluate(r, 2) << endl;

    return 0;
}