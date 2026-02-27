// It is when the function that gets called is decided at runtime,  not at compile time.
// It happens when: You call a virtual function through a base class pointer or reference.
// This is also known as "Dynamic Binding"


#include <iostream>
using namespace std;

class Animal {
public:
    virtual void speak() { // virtual → enables dynamic binding
        cout << "Animal sound" << endl;
    }
};

class Dog : public Animal {
public:
    void speak() override {
        cout << "Woof!" << endl;
    }
};

int main() {
    Animal* a = new Dog();
    a->speak(); // ✅ outputs "Woof!", decided at runtime
}



// Without virtual, this would be **static binding** — Animal::speak() would run even if the object is actually a Dog.

// - Without virtual: “I don’t care who you really are, I’m calling the base version.”
    
// - With virtual: “Let me check who you actually are before calling the method.”