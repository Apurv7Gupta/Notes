#include <iostream>
using std::cout, std::cin, std::endl;

void func(int a, int b, int c = 1) // The parameter "c" has already been given a value, so even if don't pass an argument for "c", we won't get an error, so "c" is a default argument
{
    cout << a << endl
         << b << endl
         << c << endl;
}

int main()
{
    int x = 2;
    int y = 3;
    func(x, y);
}