#include<iostream>
using namespace std;

int factorial(int n){
    if(n==0)
        return 1;
    else    
        return n * factorial(n-1);
}

int main(){
    cout << "1! = " << factorial(1) << "\n";
    cout << "2! = " << factorial(2) << "\n";
    cout << "3! = " << factorial(3) << "\n";
    cout << "9! = " << factorial(9) << "\n";
    return 0;
}