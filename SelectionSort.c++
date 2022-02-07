#include<iostream>
using namespace std;

//선택정렬
//배열에서 제일 작은 수를 찾아 
//배열의 젤 앞 부분과 교환해주며 정렬하는 방식
//정확히는 빈 자리를 활용하는 과정에서 비롯된 교환
//O(n^2)

void selection(int arr[],int num){
    for(int i =0; i < num-1; i++){
        int maxidx = i;

        for(int j =i+1; j <num; j++){//최소 탐색
            if(arr[j] < arr[maxidx]){
                maxidx = j; //가장 큰 값을 가진 배열의 인덱스를 저장한다.
            }

            int temp = arr[i];
            arr[i] = arr[maxidx];
            arr[maxidx] = temp;
        }
    }
}

int main(){
    int arr[4] = { 3,4,2,1};

    selection(arr,4);

    for(int i =0; i < 4; i++){
        cout << arr[i] <<" ";
    }
}