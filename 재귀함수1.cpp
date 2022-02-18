#include<iostream>
using namespace std;

void recursive(int num){
    if(num<= 0 )//재귀 탈출 조건
        return; //재귀 탈추
    cout << "recursive call! " <<num<<"\n";
    recursive(num-1);
    
}

int main(){
    recursive(3);
    return 0;
}