#include <iostream>
using std::cout, std::cin, std::endl;

void func()
{
    cout << "Without Parameters\n";
}

void func(int a)
{
    cout << "With Parameters";
}

int main()
{
    func();
    func(10);

    return 0;
}

//Function overloading = more than one functions with same name but different parameters
//Also called compile time polymorphism because we can conclude which function will compile first just by looking at its definition