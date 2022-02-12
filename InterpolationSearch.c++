#include<iostream>
using namespace std;
//보간 탐색
int Isearch(int ar[],int first, int last, int target){
    int mid;

    if(ar[first] > target ||  ar[last] <target) return -1; // -1의 반환은 탐색의 실패를 의미

    //이진 탐색과의 차이점을 반영한 문장
    mid = ((double)(target-ar[first]) / (ar[last]-ar[first]) * (last - first)) + first;
    //mid = (first + last)/2;  

    if(ar[mid] == target) return mid; //탐색된 타겟의 인덱스 값 반환

    else if(target < ar[mid]) return Isearch(ar,first, mid-1, target);
    else return Isearch(ar,mid+1,last,target);
}

int main(){
    int arr[] = {1,3,5,7,9};
    int idx;

    idx = Isearch(arr,0,sizeof(arr)/sizeof(int)-1,7);

    if(idx == -1){
        cout << "탐색 실패\n ";
    }
    else {
        cout << "타겟 저장 인덱스: "<< idx <<"\n";
    }
}