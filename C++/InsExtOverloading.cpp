#include <iostream>
using namespace std;

class Sample
{
    int integer1;
    int integer2;

public:
    friend ostream &operator<<(ostream &out, Sample &obj);  // operator classes
    friend istream &operator>>(istream &in, Sample &obj);
};

istream &operator>>(istream &in, Sample &obj)          // This is a function of type "istream"
{

    cout << "Enter integer 1: ";          // Asks user to enter the value for integer 1
    in >> obj.integer1;                  //  Puts the value in the object of the Sample class, "obj" through the istream object, "in"

    cout << "Enter integer 2: ";
    in >> obj.integer2;

    return in;
}

ostream &operator<<(ostream &out, Sample &obj)
{

    out << "integer is 1: \n"; // Sends a label ("integer is 1:") to the output stream ("out"), then sends the value of obj.integer1 to the stream.
    out << obj.integer1;

    out << "integer is 2: \n";
    out << obj.integer2;

    return out;
}

int main()
{

    Sample s1;

    cin >> s1; // Calls your overloaded input operator      // This triggers your custom operator>> function
    cout << s1; // Calls your overloaded output operator   // This triggers your custom operator<< function.

    system("pause");

    return 0;
}