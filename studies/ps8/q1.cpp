#include <iostream>
#include <vector>
#include <string>
using namespace std;

template<class T>
class Set {
public:
    void add(const T& item) {
        if (!alreadylisted(item)) {
            items_.push_back(item);
        }
    }

    int getSize() const {
        return items_.size();
    }

    T* getArray() const {
        T* array = new T[items_.size()];
        for (int i = 0; i < items_.size(); i++) {
            array[i] = items_[i];
        }
        return array;
    }

private:

    bool alreadylisted(const T& item) const {
        for (const auto& c : items_) {
            if (c == item) {
                return true;
            }
        }
        return false;
    }

    vector<T> items_;
};

int main(){

    Set<int> s1;
    Set<string> s2;


    int* intArray = nullptr;
    string* stringArray = nullptr;

    int i;

    // Add some sample integers to the set
    s1.add(10);
    s1.add(20);
    s1.add(15);
    s1.add(20);
    s1.add(25);
    s1.add(10);

    intArray = s1.getArray();

    cout << "Set_one_has " << s1.getSize() << " items_Here_they_are: " << endl;
    for (i = 0; i < s1.getSize(); i++) {
        cout << intArray[i] << endl;
    }
    delete[] intArray;

    // Add some sample strings to the set
    s2.add("butter");
    s2.add("hamburgers");
    s2.add("pizza");
    s2.add("hotdogs");
    s2.add("pizza");
    s2.add("lahmacun");
    s2.add("butter");

    stringArray = s2.getArray();
    cout << "Set_two_has " << s2.getSize() << " items_Here_they_are: " << endl;
    for (i = 0; i < s2.getSize(); i++) {
        cout << stringArray[i] << endl;
    }

    if( stringArray !=NULL)
    delete[] stringArray;

    return 0;
}
