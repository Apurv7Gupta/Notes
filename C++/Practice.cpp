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