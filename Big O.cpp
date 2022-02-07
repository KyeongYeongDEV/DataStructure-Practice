#include<iostream>
using namespace std;
//O(logn)인 이진 탐색 알거리즘의 비교연산의 횟수 확인한다.


int Bsearch(int ar[], int len,int target){
    int first =0;      
    int last = len-1;   
    int mid;
    int opcount =0; // 비교연산의 횟수를 기록

    while(first <= last){ 
        mid = (first+last) /2; 
        if(target == ar[mid]){
            return mid; 
        }

        else{
            if(target <ar[mid])
                last = mid-1;
            else    
                first = mid +1;
        }
        opcount++;
    }
    cout << "비교연산횟수: "<< opcount <<"\n"; //탐색 실패 시 연산횟수 출력
    return -1;
}

int main(){
    int arr1[500] = {0};
    int arr2[5000]= {0};
    int arr3[50000]={0};
    int idx;

    //배열 arr1을 대상으로, 저장되지 않은 정수 1을 찾으라고 명령
    idx = Bsearch(arr1, sizeof(arr1)/sizeof(int), 1);
    if(idx == -1)
        cout<< "탐색 실패\n\n";
    else    
        cout<< "타깃 저장 인덱스: "<<idx<< "\n";

    //배열 arr2를 대상으로, 지정되지 않은 정수 2를 찾으라고 명령
    idx = Bsearch(arr2, sizeof(arr2)/sizeof(int),2);
    if(idx == -1)
        cout<< "탐색 실패\n\n";
    else    
        cout<< "타깃 저장 인덱스: "<<idx<< "\n";

    //배열 arr3를 대상으로, 지정되지 않은 정수 2를 찾으라고 명령
    idx = Bsearch(arr3, sizeof(arr3)/sizeof(int),3);
    if(idx == -1)
        cout<< "탐색 실패\n\n";
    else    
        cout<< "타깃 저장 인덱스: "<<idx<< "\n";

}