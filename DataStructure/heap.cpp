#include<iostream>
using namespace std;
#define MAX_NUM 200//힙의 최대개수 지정

//힙의 구현은 배열로 한다(시간복잡도에서 제일 효율적이다)
//최대 힙 = 루트노드가 젤 크다
//최소 힙 = 루트노드가 젤 작다

typedef struct heap{
    int arr[MAX_NUM];
    int size;
}heap;

void swap(int *a, int *b){
    int temp = *a;
    *a = *b;
    *b = temp;
}

void initheap(heap *hp){
    hp->size = 0;
}

void insert(heap *hp, int data){ //삽입은 아래에서 위로 올아오는 느낌
    int here = ++hp->size; //마지막 인덱스를 하나 추가해준다.

    while(here != 1 && data < hp->arr[here/2]){
        //새로들어온 값과 부모노드를 비교해 자신의 데이터의 우선순위가 높다면(값이 작다면)
        //자신보다 우선순위가 높은(값이 더 작은) 노드를 만날 때까지 비교하여
        hp->arr[here] = hp->arr[here/2];//부모노드와 바꾸어준다.
    }
    //새로운 값의 위치를 찾았으면
    hp->arr[here] = data; // 그위치에 값 삽입
}

int remove_data(heap *hp){//삭제는 위체서 아래로 내려가는 느낌
    //루트 노드를 삭제하고 제일 마지막에 있던 노드를 그 위치에 데려온다
    //아래로 내려가면서 그 노드의 위치를 찾아 스왑한다.
    if(hp->size ==0) return -1;

    int ret = hp->arr[1];//루트노드를 반환해주기 위해 저장

    int parent =1;
    int child;

    while(1){
        child = parent*2;
        if(child +1 <= hp->size && hp->arr[child] > hp->arr[child+1]){
            //현재 힙의 최대사이즈를 넘지 않고
            //현재 자식노드이 값이 다음 노드보다 크다면
            //즉, 우선순위가 낮다면
            child++;
        }
        if(child > hp->size || hp->arr[child] > hp->arr[parent]) { break;}
        //현재 힙이 최대사이즈를 넘겼거나
        //자식노드가 부모노드보다 크다면 
        //반복문 탈출

        swap(&hp->arr[parent], &hp->arr[child]); // 찾은 위치에 값을 스왑한다.
        parent = child;
    }
    return ret;
}

int main(){
    heap hp;
    initheap(&hp);

    insert(&hp,3);
    insert(&hp,5);
    insert(&hp,1);
    insert(&hp,2);
    insert(&hp,8);

    cout<< "remove  " <<remove_data(&hp)<<"\n";
    cout<< "remove  " <<remove_data(&hp)<<"\n";

    insert(&hp, 9);
    insert(&hp, 3);
}