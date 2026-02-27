#include <iostream>
#include <string>
#include <fstream>

///////////////////////////////////////// Writing /////////////////////////////////////////////////////////////
using namespace std;
int main()
{

    string nig = "This a string"; // Making a variable named "nig" and putting a string in it

    ofstream out("Sample.txt"); // Opening a file named "Sample.txt with a name "out"

    out << nig; // Writing the string to the txt file

    out.close(); // NEVER FORGET to close the file after you're done.

    //----------------------------------------Reading-----------------------------------------------------------

    string nig2;

    ifstream in("Sample.txt");

    // in >> nig2;      // Will only read one word

    getline(in, nig2); // This will read the full line

    cout << nig2;

    return 0;
}