//// Function

#include <iostream>
using std::cout, std::cin;

class Class2;           //declaring class 2 here, so that FriFunc can take Class2 as its friend (This is known as Forward Declaration)

class Class1
{
private:
    int money = 10;
    friend void FriFunc(Class2, Class1); // friend function (friend of Class1 and Class2) in private
};

class Class2
{
private:
    int money = 20;
    friend void FriFunc(Class2, Class1); // friend function (friend of Class1 and Class2) in private
};

void FriFunc(Class2 r1, Class1 r2)              /* Function that can access the private members of Class1 and Class2 using references "r1" and  
                                                "r2", as it was their friend function */
{
    cout << "The sum of Class1 & Class2's money = " << r1.money + r2.money;
};

int main()
{
    Class1 obj1;
    Class2 obj2;
    FriFunc(obj2, obj1);
    return 0;
}

//// Class

#include <iostream>
using std::cout, std::cin, std::endl;

class A
{
    int a = 10, b = 20;

public:
    void show() { cout << a << " " << b << endl; }
    friend class B; // This is a friend class named "B" that can access the private members a and b in
                    // class A
};

class B
{
public:
    void add(A r) // We put a reference "r" of class A in the parameters of this function
    {
        int add = r.a + r.b; // Using the reference, we can access and use the private members
        cout << "Sum of A and B : " << add;
    };
};

int main()
{
    A obj;
    obj.show();

    B obj2;
    obj2.add(obj);
}
