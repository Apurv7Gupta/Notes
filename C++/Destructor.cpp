
// A destructor is a special member function (method) of a class that is automatically called when an object goes out of scope or is explicitly deleted
// mostly, cpp itself deletes the left over memory from constructors after the code is finished (default destructor)
// a Destructor can be defined to free up the dynamically allocated memory
//it cannot take arguments or return values
//Each class can have only one destructor

// Advantages of Destructor is preventing Memory Leak

#include <iostream>
using std::cout, std::cin, std::endl, std::string;

class Cat
{

public:
    string name;
    string color;
    void print_cat() // function to print cat

    {
        cout << "Name: "
             << name << endl;
        cout << "Color: "
             << color << endl;
    }

    Cat() // DEFAULT CONSTRUCTOR (NON PARAMITERIZED CONSTRUCTOR) declaration
    {

        name = "Unknown"; // This is called initialisation

        color = "Unknown";
    }

    // DESTRUCTOR
    ~Cat()
    {
        cout << "I deleted Cat constructor";
    }
};

int main()
{
    Cat cat1; // Printing cat using default values
    cout << "Cat1" << endl;
    cat1.print_cat();
    return 0;
}