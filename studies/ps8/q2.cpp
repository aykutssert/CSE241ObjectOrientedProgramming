#include <iostream>
#include <string>
using namespace std;

template<class T, class U>
class Pair {
private:
    T first;
    U second;
public:

    Pair(T _first, U _second) {

        this->first = _first;
        this->second = _second;
    }

    T getFirst() const {
        return first;
    }

    void setFirst(T _first) {
        this->first = _first;
    }

    U getSecond() const {
        return second;
    }
};

int main() {


    Pair<char,char> p('A', 'B');

    cout << "First is " << p.getFirst() << endl;

    p.setFirst('Z');

    cout << "First changed to " << p.getFirst() << endl;

    cout << "The pair is P1: " << p.getFirst() << "," << p.getSecond() << endl;


    Pair<int,string> p2(34, "Bill");

    Pair<string,int> p3("Bill", 34);

    cout << "The pair is P2: " << p2.getFirst() << "," << p2.getSecond() << endl;

    cout << "The pair is P3: " << p3.getFirst() << "," << p3.getSecond() << endl;


    return 0;
}
