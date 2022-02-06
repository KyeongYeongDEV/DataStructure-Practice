#include<iostream>
using namespace std;
//새로운 노드를 젤 뒤에 붙이기

typedef struct Node{
    int data;
    Node *next, *prev;
}Node;

Node *append(Node *head, int data){//새로운 노드를 리스트 젤 뒤에 생성
    Node *newnode = (Node*)malloc(sizeof(Node));
    newnode->data = data;

    if(head == NULL){//헤드가 없을 때
        head = newnode;
    }
    else{//해드가 있을 때
        Node *horse = head;

        while(horse != NULL){
            horse = horse->next;
        }
        newnode->prev = horse;
        horse->next = newnode;
    }

    return newnode;
}

Node *betweennode(Node *head, int index, int data){
    //index 번째에 새로운 노드를 추가
    Node *newnode = (Node*)malloc(sizeof(Node));
    Node *horse = head;
    int cnt=0;
    
    while(cnt != index){
        
        cnt++;
    }
    newnode->data = data;
    newnode->next= horse;
    newnode->prev = horse->prev;
    horse->prev = newnode;
    horse->prev->next = newnode;

    return newnode;
}

int nodesize(Node *head){
    Node *horse = head;
    int cnt =0;

    while(horse != NULL){
        horse = horse->next;
        cnt++;
    }

    return cnt;
}

Node *removewherever(Node *head, int index){
    //index 위치에 있는 노드를 삭제
    Node *newnode = (Node*)malloc(sizeof(Node));
    Node *horse = head;
    int cnt=0;
    
    while(cnt != index){
        horse = horse->next;
        cnt++;
    }

    horse->prev->next = horse->next;
    horse->next->prev = horse->prev;

    free(horse);
    return NULL; 
}

Node *printnode(Node *head){//노드 출력
    Node *horse = head;

    while(horse != NULL){
        cout<< horse->data<< "  ";
    }

    return NULL;
}

int main(){

    Node *head = (Node*)malloc(sizeof(Node));
    Node *tail = (Node*)malloc(sizeof(Node));
     head = NULL;
    tail = NULL;

    cout<<"0~4를 가진 노드 생성---------------------"<<endl;
    for(int i=0; i <5; i++){
        append(head,i);
    }
    printnode(head);
    
    cout<< "2번째 위치에 0을 가진 노드 생성------------------"<<endl;
    betweennode(head,2,0);
    printnode(head);
    cout<< "노드 사이즈------------------------"<<endl;
    nodesize(head);
    printnode(head);
    cout<< "3번째 위치에 있는 노드 삭제-------------"<<endl;
    removewherever(head, 3);
    printnode(head);

    return 0;
}