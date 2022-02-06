#include<iostream>
using namespace std;

int Bsearch(int ar[], int len,int target){
    int first =0;       //탐색 대상의 시작 인덱스 값
    int last = len-1;   // 탐색 대상의 마지막 인데스 값
    int mid;

    while(first <= last){ //처음과 끝이 같은 경우에도 돌아가야 한다.
        mid = (first+last) /2; //탐색 대상의 중앙을 찾는다
        if(target == ar[mid]){
            return mid; //탐색완료
        }

        else{//타겟이 아니라면 탐색 대상을 반으로 줄인다.
            if(target <ar[mid])
                last = mid-1;
            else    
                first = mid +1;
        }
    }
    return -1;
}

int main(){
    int arr[] = {1,3,5,7,9};
    int idx;

    idx = Bsearch(arr, sizeof(arr)/sizeof(int), 7);
    if(idx ==- 1){
        cout <<"탐색 실패 "<<"\n";
    }
    else{
        cout << "타깃 저장 인덱스 : " <<idx <<"\n";
    }

    idx = Bsearch(arr, sizeof(arr)/sizeof(int), 4);
    if(idx == -1)
        cout << "탐색 실패"<< "\n";
    else    
        cout<< "타깃 저장 인덱스: " << idx << "\n";
    
    return 0;
}