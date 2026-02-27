#include <iostream>
using std::cout, std::cin, std::endl, std::string;

int ArrayName[5] = {1, 2, 3, 4, 5}; // Normal Array Definition

void printArray() // Function to print the indivisual members of the array
{
    for (int i = 0; i < 5; i++)
    {
        cout << ArrayName[i] << " ";
    }
}
///////////////////////////////////////////////// Array of Objects ////////////////////////////////////////////////////////////////////////////////
class Testing
{
    int num;

public:
    void setValue()
    {
        cout << "Enter your number: " << endl;
        cin >> num;
    }

    void getValue()
    {
        cout << "Value of num is: " << num << endl;
        cin >> num;
    }
};

int main()
{

    Testing ObjArr[5];
    
    for (int i = 0; i < 5; i++)
    {
        ObjArr[i].setValue();
    }

for (int i = 0; i < 5; i++)
    {
        ObjArr[i].getValue();
    }
system("pause");
return 0;
}

// An array of objects is used when we want to represent a group of objects of the same class under one common name, and access them using an index
// They are stored in contigious memory
// This demonstrates how you can create and manage multiple instances of a class with an array, and perform operations on each object in sequence.



/////////////////////////////////////// Another example
#include <iostream>
using namespace std;

class MyClass {
public:
    int num;

    void setValue(int n) {
        num = n;
    }

    void display() {
        cout << "Value is: " << num << endl;
    }
};

int main() {
    MyClass arr[3];  // Array of 3 objects

    // Set values for each object in the array
    for (int i = 0; i < 3; i++) {
        arr[i].setValue(i * 10);
    }

    // Display values of each object
    for (int i = 0; i < 3; i++) {
        arr[i].display();
    }

    return 0;
}
