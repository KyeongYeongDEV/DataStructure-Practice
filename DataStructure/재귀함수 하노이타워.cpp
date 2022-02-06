#include<iostream>
using namespace std;

void hanoi(int num, char from, char by, char to){
    if(num ==1){//이동할 원반의 수가 1개라면
        cout<<"원판1을 "<<from<<"에서" <<to<<"로 이동 \n";
    }
    else{
        hanoi(num-1,from,by,to);
        cout <<"원판"<<num<<"을 "<<from <<"에서 "<<to <<"로 이동\n";
        hanoi(num-1,by,from,to);
    }
}

int main(){
    //막대 a의 원반 3개를 막대b를 경유하여 막대 c로 옮기기
    hanoi(3,'A','B','C');

    return 0;
}