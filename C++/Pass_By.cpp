//////Pass By value

#include <iostream>
using namespace std;


void value(int x){ //3. The variable's value (1) gets copied into the parameter of this function

    x= 11;  //4. Then that value is reassigned as 11 to x
}

int main(){

int main = 1;  //1. We define a variable with value 1

value(main);  //2. We pass the variable as an argument to this function

cout<<main <<endl; //5. The value of the variable didn't change, but the value of the copy of the variable (which is x) changes to 11.

    return 0;
}


//////Pass By Reference

#include <iostream>
using namespace std;


void reference(int &x){ //3. We create a reference variable "x", that references the "main" variable's memory location (as "main" is passed as the argument)

    x= 11;  //4. Then the value of "main" is changed to 11
}

int main(){

int main = 1;  //1. We define a variable with value 1

reference(main);  //2. We pass the variable as an argument to this function

cout<<main <<endl; //5. The value of the "main" variable is now changed to 11

    return 0;
}


//////Pass By Pointer


#include <iostream>
using namespace std;


void pointer(int *x){

    *x = 11;  //3. changes the value of the variable thats passed into the arguments to 11 by pointing to the memory location of the variable
}

int main(){

int main = 1;  //1. value of the variable was 1 at first

pointer(&main);  //2. now changed to 11 (as the argument passed here is not the variable, but the address of the variable)

cout<<main <<endl;

    return 0;
}