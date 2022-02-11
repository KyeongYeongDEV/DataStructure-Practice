#include<iostream>
using namespace std;

int swap(int *a, int *b){
    int tmp = *a;
    *a = *b;
    *b = tmp;

    return 0;
}

void heap(int arr[],int n, int i){
    int parent = i;
    int Lchild = i * 2 + 1;
    int Rchilde = i * 2 + 2;

    if(Lchild < n && arr[parent] < arr[Lchild]){
        //왼쪽 자식 노드가 존재하면서 부모노드와 값 비교
        parent = Lchild;
    }

    if(Rchilde < n && arr[parent] < arr[Rchilde]){
        //오른쪽 자식 노드가 존재하면서 부모노드와 값 비교
        parent = Rchilde;
    }

    if(i != parent){
        //왼쪽 or 오른쪽 자식 노드 중 부모 노드보다 큰 값이 존재한 경우
        swap(&arr[parent], &arr[i]);
        //초기 부모노드가 제자리를 찾을 떄까지 내려갑니다.
        heap(arr,n,parent);
    }
}

void heapsort(int arr[],int n){
    //최대 힙(max heap)구성
    for(int i = (n/2)-1; i>=0; i--){
        heap(arr,n,i);

        //root에 위치한 최대값을 마지막 노드와 바꿔가며 heap 재구성
        //heap의 크기를 줄여가며 값이 큰 원소를 차례로 가져옵니다.
        for(int i =n-1; i >0; i--){
            swap(&arr[0],&arr[i]);
            heap(arr,i,0);
        }
    }
}

int main(){
    int n=9;
    int arr[9] = {7,6,5,8,3,5,9,1,6};

    heapsort(arr,n);

    //오르차순 출력
    for(int i = 0; i <n; i++){
        cout << arr[i] <<" ";
    }
}