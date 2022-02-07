#include<iostream>
using namespace std;
//버블 정렬
//인접한 데이터 두 개를 비교, 교환을 하며 정렬
//제일 큰 수를 젤 뒤에 보내고 
//그 인덱스를 제외하고 반복
//비교횟수  ex) 비교대상 4개
// 3 + 2 + 1 = 6 6번 
//O(n^2)

void bubble(int arr[],int num){
    for(int i =0; i < num-1; i++){
        for(int j =0; j < (num-i)-1; j++){
            if(arr[j] > arr[j+1]){
                int tmp = arr[j+1];
                arr[j+1] = arr[j];
                arr[j] = tmp;
            }
        }
    }
}

int main(){
    int arr[4] = {3,2,4,1};
    bubble(arr,sizeof(arr)/sizeof(int));

    for(int i=0; i < sizeof(arr)/sizeof(int); i++){ // 출력
        cout << arr[i] << " ";
    }
}