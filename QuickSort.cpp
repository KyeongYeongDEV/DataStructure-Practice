#include<iostream>
using namespace std;

void swap(int arr[], int idx1, int idx2){
    int tmp = arr[idx1];
    arr[idx1] = arr[idx2];
    arr[idx2] = tmp;
}

int partition(int arr[],int left, int right){
    int pivot = arr[left]; // 피벗의 위치는 가장 왼쪽
    int low = left+1;
    int high = right;

    while(low <= high){//교차되지 않을 떄까지 반복
        while(pivot >= arr[low] && low <= right){//피벗보다 큰 값을 찾는 과정
            low++; //low를 오른쪽으로 이동
        }
        while(pivot <= arr[high] && high >= (left+1)){//피벗보다 작은 값을 찾는 과정
            high--;//high를 왼쪽으로 이동
        }

        if(low <= high){//교차되지 않은 상태라면 swap를 실행
            swap(arr,low,high);
        }
    }
    swap(arr,left,high);//피벗과 high가 가리키는 대상 교환
    return high;//옮겨진 피벗의 위치정보 반환
    
}

void Quicksort(int arr[], int left, int right){//재쉬함수를 이용한다.
    if(left <= right){
        int pivot = partition(arr,left,right);//둘로 나누어서
        Quicksort(arr,left,pivot-1);          //왼쪽 영역을 정렬
        Quicksort(arr,pivot+1,right);         //오른쪽 영역을 정렬
    }
}

int main(){
    int arr[7] = {3,2,4,1,7,6,5};
    //arr[3] = {3,3,3}; 

    int len = sizeof(arr)/sizeof(int);
    int i;

    Quicksort(arr,0,sizeof(arr)/sizeof(int)-1);

    for(i =0; i <len; i++){
        cout << arr[i] << " ";
    }
}