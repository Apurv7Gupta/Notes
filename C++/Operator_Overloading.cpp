// Operator Overloading allows you to redefine the behavior of built-in operators (like +, -, *, ++, etc.) so they can work with user-defined types such as classes or structs.

// It is a form of compile-time polymorphism.

// If we create two or more functions having same name but different in parameters
// Operator which contain only one operand is called unary operator overloading
// Operators that cant be overloaded: . (dot operator) , :: (scope resolution op) , ?: (ternary op)

//// UNARY with class function:
#include <iostream>
using namespace std;

class demo
{

    int a, b;

public:
    demo(int x, int y)
    {
        a = x;
        b = y;
    }

    void show()
    {
        cout << "A: " << a << " " << "B: " << b << endl;
    }

    void operator-()
    {
        a = -a;
        b = -b;
    }
};

int main()
{

    demo obj(-10, 20);
    obj.show();
    -obj;
    obj.show();

    return 0;
}

// UNARY with friend function:

#include <iostream>
using namespace std;

class demo
{

    int a, b;

public:
    demo(int x, int y)
    {
        a = x;
        b = y;
    }

    void show()
    {
        cout << "A: " << a << " " << "B: " << b << endl;
    }

    friend void operator-(demo &obj);

    void operator-(demo &obj)
    {
        obj.a = -obj.a;
        obj.b = -obj.b;
    }
};

int main()
{

    demo obj(-10, 20), obj2(100, -300);
    obj.show();
    -obj;
    obj.show();

    return 0;
}