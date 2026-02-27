////Constructor = Special Method that is automatically invoked at time of obj creation
// Constructor should have the same name as the class
// has no return type
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

    void paintCat(string newColor)
    {
        color = newColor;
    }

    Cat() // DEFAULT CONSTRUCTOR (NON PARAMITERIZED CONSTRUCTOR) declaration
    {

        name = "Unknown"; // This is called initialisation

        color = "Unknown";
    }

    // Cat() : name("Unknown"), color("Unknown") {} // Initializer list syntax


    Cat(string n, string c) // PARAMETERIZED CONSTRUCTOR declaration
                            // The Phenomenon of having multiple constructors with same name but different types is known as Constructor Overloading, which is an example of POLYMORPHISM
    {

        name = n;

        color = c;
    }

    // Cat(string n, string c) : name(n), color(c) {} // Initializer list synatx



    Cat(Cat &orgObj){             // COPY CONSTRUCTOR (CUSTOM COPY CONSTRUCTOR) //The original object of Cat is passed here
        this->name = orgObj.name; // The parameters of this constructors is mapped to the original constructor
        this->color = orgObj.color; // A copy constructor allows an object to be copied accurately, which is useful when passing objects by value to functions, returning objects from functions, or explicitly creating a new instance as a copy of another
    }

    // Cat(const Cat &orgObj) : name(orgObj.name), color(orgObj.color) {} // Initializer list syntax, also, using const is best practice
};

int main()
{
    Cat cat1;                          //Printing cat using default values
    cout << "Cat1 (made default constructor)" << endl;
    cat1.print_cat();

    Cat cat2("Gurt", "blue");        //Printing cat using parameter values
    cout << "\nCat 2 ( Parameterized constructor)" << endl;
    cat2.print_cat();

    cout << "\nPainting cat to red \n"; //using paintCat function to modify a parameter value

        cat2.paintCat("red");
        cat2.print_cat(); 

    cout<< "\nUsing default copy constructor to copy cat2 parametrized constructor\n";

        Cat CopyCon(cat2);  //COPY CONSTRUCTOR copying cat2 to use the same filled in values (if we hadn't defined the CUSTOM copy constructor earlier, this would be using the DEFAULT copy constructor instead)
        CopyCon.print_cat();

    return 0;
}