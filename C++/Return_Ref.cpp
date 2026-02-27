// A reference is an alias for an existing variable.
// Allowing you to access or modify the original variable using the reference name.
// This code demonstrates a Funciton returning reference
//A function returning a reference is a function whose return type is a reference (indicated by & after the return type), which means the function returns an alias to an existing variable rather than a copy
//This allows the caller to access or modify the original variable directly through the returned reference, enabling efficient operations without copying and supporting assignment to the function call.

#include <iostream>
using std::cout, std::cin, std::endl;

int &func(int &a)  //3. We define a referencing function ("a" becomes an alias for whatever value is passed as the argument)
{
    cout << a <<endl; //4. Output: 10 (as the value of x was assigned as 10)
    return a; //5. Returning "a" to the function
}

int main()
{
    int x = 10; //1. We define a variable with value 10
    func(x) = 25; //2. We pass x as the argument for func function //6. We now assign a value of 25 to the referencing variable "a" (which is just an alias for x, so x = 25) ( "a" was returned at the end of the function, which is why we are able to modify it here)
    cout << x; // Output: 25
}