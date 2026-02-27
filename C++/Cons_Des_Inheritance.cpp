// in Inheritance, the order of calling of constructors is:  [ parent ---> child ]
//and execution order, [ child ---> parent ]

//destructor order: [ child ---> parent ] 

#include <iostream>
using namespace std;

class A
{
    int a;

public:
    A(int k)                                    // Constructor "A"
    {
        a = k;
    }
};

class B: public A{
    int b;
    public:
    B(int x, int y) : A(5) { }                  // Constructor of B (B is calling the constructor of A here, if you dont pass arguments, then the 
                                                //default constructor for A will be called)
};

void main(){
    B obj(2, 3);                               //
}