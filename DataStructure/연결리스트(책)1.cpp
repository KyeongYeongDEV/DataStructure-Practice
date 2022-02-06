#include<iostream>
using namespace std;

//head 노드를 기준으로 다음 노드에 값이 저장이 된다.

struct node{
    int data;
    struct node *next;
};

int main(){
    struct node *head = (struct node)malloc(sizeof(struct node));

    struct node *node1 = (struct node)malloc(sizeof(struct node));
    head -> next = node1;
    node1->data = 10;

    struct node *node2 = (struct node)malloc(sizeof(struct node));
    node1->next = node2;
    node2->data = 20;

    node2->next = NULL;

    struct node *curr = head->next;

    while(curr != NULL){
        cout << curr->data<<endl;
        curr = curr->next;   
    }
    free(node1);
    free(node2);
    free(head);
}