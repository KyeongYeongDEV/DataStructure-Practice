#include<iostream>
using namespace std;

//2022.02.03
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

node *search_refunction(node *root, int key){//재귀를 이용한 순환 탐색 함수
    if(root == NULL){return NULL;}

    if(root->key == key){return root;}//key가 자기 자신인 경우 찾았으므로 리턴
    else if(root->key <key){return search_refunction(root->right,key);} //현재 키 < 찾으려는 키면 오른쪽 트리로(큰 차수로)
    else{return search_refunction(root->left,key);}//아니면 왼쪽 트리로
}

//-------------#2022.02.04 추가---------------

node *search(node *root, int key){//반복문을 이용한 탐색 
        if(key == root->key){return root; }

        else if(key < root->key){
            root  = root->left;
        }

        else{
            root = root->right;
        }
    
    return root; //탐색에 실패했을 경우  NULL  반환
}

node * min_value_node(node *root){
    node *current = root;

    while(current->left != NULL){
        current = current->left;
    }
    return current;
}

node *delete_node(node *root,int key){//key 노드 삭제 후 루트 반환
    if(root == NULL){return root;}
    if(key <root->key){
        root->left = delete_node(root->left,key);
    }
    else if(key > root->key){
        root->right = delete_node(root->right,key);
    }

    else{ //키가 루트와 같으면 이 노드를 삭제함
        if(root->left == NULL){
            node *temp = root->right;
            free(root);
            return temp;
        }

        else if(root->right == NULL){
            node *temp = root->left;
            free(root);
            return temp;
        }

        node *temp = min_value_node(root->right);
        root->key = temp->key;  //직후 키 복사
        root->right = delete_node(root->right,temp->key);//직후 노드 삭제
    }
    return root;
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
    cout<<"----------------------------\n";
    delete_node(root,40);
    inorder(root);
    }
    /*
 0번 순회 했습니다.
20
30
40
50
60
70
80
----------------------------
20
30
50
60
70
80
*/