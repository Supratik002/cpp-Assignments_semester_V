#include <iostream>
#include <vector>
#include <list>
using namespace std;
class base {
    int x;
    vector<double> v;
public:
    base(int y, vector<double> z) : x(y), v(z) {}
    
    void print() {
        cout << "x: " << x << " v: ";
        for (double d : v) {
            cout << d << " ";
        }
        cout << endl;
    }
};

class derived : public base {
    list<bool> l;
public:
    derived(int y, vector<double> z) : base(y, z) {}
    derived(int y, vector<double> z, list<bool> el) : base(y, z), l(el) {}

    void print() {
        base::print(); 
        cout << "l: ";
        for (bool b : l) {
            cout << b << " ";
        }
        cout << endl;
    }
};

int main() {
    derived d {10, {1.5, 2.5, 3.5}, {true, false}};
    d.print();
}

	
