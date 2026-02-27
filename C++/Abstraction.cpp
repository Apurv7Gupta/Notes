//Abstraction means displaying only essential information and ignoring the other details or implementation.

//We can implement it using Access Specifiers

//An abstract class is only made for inheritance, it has no object, it only tells how the inherited class should be (it only exists to be a blueprint for other classes)

//If a function uses "virtual" keyword, it becomes a pure virtual function, it must be initialized to zero then its called a pure virtual function, If a class has a pure virtual function, then it has become an abstract class 

#include <iostream>
using std::cout, std::cin, std::endl, std::string;

class Shape // abstract class
{
    // pure virtual function

    virtual void draw() = 0;
};

class Circle : public Shape
{
public:
    void draw() { cout << "Drawing a circle\n"; }
};


int main()
{

    // Shape S1;  //If we try to create an object of the abstract class, it will throw an error saying "Shape is an abstract class"
    Circle c1;
    c1.draw();
    return 0;
}