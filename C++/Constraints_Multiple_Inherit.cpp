// Contraints of Multiple Inheritance:

// 1) Diamond Problem (Ambiguity):
// if two base classes inherit from the same ancestor,
// and a derived class inherits both,
// you end up with multiple copies of the ancestor
// virtual inheritance solves this

// Difference b/w multiple and multilevel inheritance

#include <iostream>
using namespace std;

class A{
public:

    void show()
    {
        cout << "Class A" << endl;
    }
};
                                                            //To fix diamond problem (make the inheritance a virtual inheritance, so B and C share the same copy of A, thus eliminating duplication and ambiguity):

class B : public A { };                                             //class B : virtual public A { };
class C : public A { };                                             //class C : virtual public A { };

//D inherits from both B and C

class D : public B, public C { };

int main(){
    D obj;
    //obj.show();                           // Error: Ambigous, compiler cannot decide weather to call B::A or C::A
                                            //after fixing diamond problem, this works
    
    obj.B::show();                          // Correct: Explicitly call through B
    obj.C::show();                          // Correct: Explicitly call through C
return 0;
}

// Other problems than the diamond problem:

    //Ambiguity of members: if two base classes have functions/variables with the same name, the derived class doesn't know which one to use.
    //Increased Complexity: Class hierarchy becomes harder to design, maintain and debug
    //Constructor/Destructor Order Issues
    //Fragile base class problem: If you modify one base class, it can break all derived classes