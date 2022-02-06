#include<iostream>
using namespace std;
//*이진탐색의 조건*
//배열에 저장된 수는 정렬돼 있어야 한다.

//내가 짜보기

int search(int *arr, int num){
    int size = 5;
    int tmp;

    
        tmp = size/2;
        if(num== arr[tmp]){
            return tmp;
        }
        else if(num > arr[tmp]){//찾는 수보다 작을 경우
            tmp = (tmp+1 + num-1) /2;
            if(num == arr[tmp]){
                return tmp;
            }
            else{
                return tmp+1;
            }
        }
        else if(num < arr[tmp]){//큰 경우
            tmp = (tmp-1)/2;
            if(num == arr[tmp]){
                return tmp;
            }
            else if(num > arr[tmp]){
                return tmp+1;
            }
            else{return tmp-1;}
        }
    return 0;
}

int main(){
    int arr[5] = {1,3,5,7,9};
    int num;
    cin >> num; 

    cout << "타겟 저장 인덱스 : "<<search(arr,num);


}