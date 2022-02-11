#include<iostream>
using namespace std;
//병합 정렬
//1단계 분할
//2단계 정렬
//3단계 결합

void MergeTwoArea(int arr[], int left, int mid, int right){
    int fidx = left;
    int ridx = mid +1;
    int i;

    int *sortarr = (int*)malloc(sizeof(int)*(right+1));
    int sidx = left;

    while(fidx <= mid && ridx <= right){//****매우중요****
    //병합할 두 영역의 데이터들을 비교하여
    // 정렬 순서대로 sortarr에 하나씩 옮겨 담는다
        if(arr[fidx] <= arr[ridx]){
            sortarr[sidx] = arr[fidx++];
        }
        else{
            sortarr[sidx] = arr[ridx++];
        }
        sidx++;
    }

    if(fidx > mid){//배열의 앞부분이 모두 sortarr에 옮겨졌다면
        //배열의 뒷부분에 남은 데이터들을 sortarr에 그대로 옮긴다.
        for(i = ridx; i <= right; i++,sidx++){
            sortarr[sidx] = arr[i];
        }
    }
    else{//배열의 뒷부분이 모두 sortarr에 옮겨졌다면
        //배열의 앞부분에 남은 데이터들을 sortarr에 그대로 옮긴다.
        for(i = fidx; i <= mid; i++,sidx++){
            sortarr[sidx] = arr[i];
        }
    }

    for(i = left; i <= right; i++){
        arr[i] = sortarr[i];
    }

    free(sortarr);
}

void mergesort(int arr[], int left,int right){
    int mid;
    
    if(left < right){
        //중간 지점을 계산한다.
        mid = (left+right)/2;

        //둘로 나누어 각각을 정렬한다.
        mergesort(arr,left,mid);
        mergesort(arr,mid+1,right);

        //정렬된 두 배열을 병합한다.
        MergeTwoArea(arr,left,mid,right);
    }
}

int main(){
    int arr[7] = {3,2,4,1,7,6,5};
    int i;

    //배열 arr의 전체 영역 정렬
    mergesort(arr,0,sizeof(arr)/sizeof(int)-1);

    for(i=0; i<7;i++){
        cout <<arr[i] <<" ";
    }

}