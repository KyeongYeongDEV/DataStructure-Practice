#include<iostream>
using namespace std;

//삽입정렬
//개선된 선택 정렬
//각 항목마다 배열 전체를 
//뒤에서 앞으로 비교하여 자신의 자리를 찾아감
//들어갈 자리를 찾았으면 비교대상을 한 칸씩 뒤로 민다.
//찾으 위치에 삽입
//O(n^2)

void insert(int arr[], int num){
    for(int i =1; i <num; i++){
        int insdata = arr[i]; //정렬 대상을 변수에 저장

        for(int j = i-1; j>= 0; j--){
            if(arr[j] > insdata){//비교대상을 찾았으면 뒤로 민다.
                arr[j+1] = arr[j];
            }
            else{//다 밀었으면
                arr[j+1] = insdata; //찾은 위치에 삽입 및
                break; // 탈출
            }
        }     
    }


int main(){
    int arr[5] = {5,3,2,4,1};

    insert(arr,5);

    for(int i=0; i <5; i++){
        cout <<arr[i] <<" ";
    }
}