// Templates in C++ let us create templated functions or classes, meaning they allow its return type to be dynamic for any data type
// The data type is decided at compile time, through either explicit difinition in function call or inferred by the compiler
// When a template function is instantiated, the compiler generates a version of the function for the specific type used in the function call. This process is known as template instantiation and type deduction.

#include <iostream>
using namespace std;

template <typename Reggin>

void function(Reggin value)
{
    cout << "This is a value of type Reggin: " << value <<endl;
}

int main(){

function<int>(8);

}

//////////////////////////////////////// Class ///////////////////////////////////////////////////////

#include <iostream>
using namespace std;

template <typename Reggin>
class Box {
public:
    Reggin value;
    Box(Reggin v) : value(v) {}     // Constructor with initializer list syntax that takes a variable "v" of type Reggin and fills it with "v"

    void show() {
        cout << "This is a Value of type Reggin: " << value << endl;
    }
};

int main() {
    Box<int> intBox(42);
    intBox.show();

    Box<string> strBox("Hello");
    strBox.show();
}

///////////////////////////////////// With Inheritance /////////////////////////////////////////////

#include <iostream>
using namespace std;

// Base class template
template <typename Reggin>
class Base {
public:
    Reggin value;
    Base(Reggin v) : value(v) {}
    void show() {
        cout << "Base value: " << value << endl;
    }
};

// Derived class template inheriting from Base<T>
template <typename Reggin>
class Derived : public Base<Reggin> {
public:
    Derived(Reggin v) : Base<Reggin>(v) {}
    void display() {
        cout << "Derived value: " << this->value << endl;
    }
};

int main() {
    Derived<int> obj(100);
    obj.show();     // from Base        // The show function could only work because the derived class invoked the base class constructor
    obj.display();  // from Derived
    return 0;
}
