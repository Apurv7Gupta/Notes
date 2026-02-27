#include <iostream>
#include <iomanip>
using namespace std;

// User Defined Manipulator
ostream &tab(ostream &X)
{
        X<<"\t";  // Code for manipulator, here it activates a tab when called
        return X;
}

int main()
{

    cout << setw(10) << "SetW sets the width of the output" << endl;
    cout << setprecision(2) << "SetPrecision sets the decimal precision: " << 2.55555;

    //Old method:

    // cout << setiosflags(ios::hex);

    // New method:
    cout << std::hex;
    cout << endl
         << "SetIoFlags sets flags for the output, Hexadecimal of 84 is: " << 84;

// Calling User Defined Manipulator

std::cout << endl << "Calling User Defined Manipulator: "<< "1" << tab << "2" << tab << "3" << std::endl;

    return 0;
}