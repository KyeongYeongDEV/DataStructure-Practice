#include<iostream>
using namespace std;

typedef struct node{
    int key;
    struct node *left, *right;
}node;

int cnt =0;

node *newnode(int item){
    node *temp = (node*)malloc(sizeof(node));
    temp->key = item;
    temp->left = temp->right = NULL; //왼쪽,오른쪽 자식 NULL
    return temp;
}

node *insert(node *node, int key){//삽입 연산
    if(node == NULL){return newnode(key);}

    if(key < node->key) 
        node->left = insert(node->left,key);//찾는 키 < 노드 키면 왼쪽

    else if(key > node->key) 
        node->right = insert(node->right,key); // 반대면 오른쪽
    
    return node;//노드 포인터 반환  
}

node *search(node *root, int key){
    if(root == NULL){return NULL;}

    if(root->key == key){return root;}//key가 자기 자신인 경우 찾았으므로 리턴
    else if(root->key <key){return search(root->right,key);} //현재 키 < 찾으려는 키면 오른쪽 트리로(큰 차수로)
    else{return search(root->left,key);}//아니면 왼쪽 트리로
}

void inorder(node *root){//중위 순회로 출력
    if(root != NULL){
        inorder(root->left);
        cout << root->key<<"\n";
        inorder(root->right);
    }
}

int main(){
    /*
            50
        /       \
        30      70
        /\      /\
    20     40  60   80    */
    node *root =NULL;

    root = insert(root,50);
    insert(root,30);
    insert(root,20);
    insert(root,40);
    insert(root,70);
    insert(root,60);
    insert(root,80);

    cnt = 0;
    search(root,80);
    cout<<cnt<<"번 순회 했습니다.\n";

    inorder(root);
    }