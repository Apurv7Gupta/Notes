//Dynamic objects are created using new keyword and stored in heap instead of the stack

#include <iostream>
using std::cout, std::cin, std::string, std::endl;

class Addition                  //Normal class delaration
{
private:
    int a, b;

public:
    void setData(int a, int b)
    {
        this->a = a;
        this->b = b;
    }
    int addNo()
    {
        int sum;
        sum = this->a + this->b;
        return sum;
    }
};
int main()
{
    Addition *ptr;        // Pointer to class
    ptr = new Addition;   // This is Dynmaic Object creation
    ptr->setData(20, 30); // and usage
    int s = ptr->addNo();

    // Addition obj1;              // This is normal object creation
    // obj1.setData(20, 30);       // and usage
    // int s=obj1.addNo();

    cout << "addition is: " << s;
    delete ptr;                   // Deleting Dynamic Object
    return 0;
}


//////////////////////////////////////////// Simpler example:
#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { cout << "Animal sound\n"; }
};

class Dog : public Animal {
public:
    void speak() override { cout << "Woof!\n"; }
};

int main() {
    Animal* a = new Dog();          // Dynamic object creation
    a->speak();                    // and usage
    delete a;                      // Deleting Dynamic Object 
}


/////////////////////////////////////////////////////////////// Note:

/*

Addition* ptr;   // Star next to class name
Addition *ptr;   // Star next to variable name
Addition * ptr;  // Spaces around

All have same working

        */