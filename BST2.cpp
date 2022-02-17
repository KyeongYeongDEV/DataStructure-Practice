#include<iostream>
using namespace std;
//원하는 노드를 삭제하는 부분이 어렵다

typedef struct Node{
    int data;

    Node *left = nullptr;
    Node *right = nullptr;
}Node;

//---바이더리 노드 동적할당----
Node *getbinaryNode(void){
    Node *newnode = (Node*)malloc(sizeof(Node));

    //새로운 노드 초기화
    newnode->data = 0;
    newnode->left = NULL;
    newnode->right = NULL;
    
    return newnode;
}

//---노드 설정---
void setnode(Node *node, int data, Node *left_child, Node *right_child){
    node->data = data;
    node->left = left_child;
    node->right = right_child;
}


//---새노드 저장---
Node *addnode(Node *node,int data){ 
    int count =0;

    if(node == NULL){//빈 노드를 찾았다면 그 자리에 대입한다.
        node = getbinaryNode();
        setnode(node, data,NULL,NULL);
        cout << "Node 생성완료 " << node->data <<"counter : "<<count++<<"\n";
    }
    else if(data == node->data){
        cout << "종복된 값은 입력이 안 됩니다.\n";
    }
    else if(data < node->data){
        node->left = addnode(node->left,data); //재귀함수를 이용하여 왼쪽 노드로 이동을 한다.
    }
    else{
        node->right = addnode(node->right,data); //재귀함수를 이용하여 오른쪽 노드로 이동을 한다.
    }

    return node;
}

//---키값으로 검색---
Node *searchtree(Node *ptr,int key){
    if(ptr == NULL){ 
        //최하위 노드까지 내려갔는데 못 찾았으면 값이 없는 것이다.
        cout <<"[실패] 키값이 "<<key<<"인 노드는 없습니다. \n";
    }
    else if(key == ptr->data){
        //값을 찾았다면 반환
        cout << "[성공] 키값이 "<< key <<"인 노드를 반환합니다.\n";
    }
    else if(key < ptr->data){
        //왼쪽으로 이동
        searchtree(ptr->left,key);
    }
    else{
        //오른쪽으로 이동
        searchtree(ptr->right, key);
    }
}

//---노드 출력---
void showtree(const Node *node){
    if(node != NULL){//노드가 비어있지 않다면
        showtree(node->left); //좌로 끝까지 갔다 오고
        cout << node->data;
        showtree(node->right); // 우로 끝까지 간다
    }
}

//---모든 노드의 메모리 해제---
void deletetree(Node *node){
    if(node != NULL){
        deletetree(node->left);//왼쪽 서브 트리로 먼저 갔다가 
        deletetree(node->right);// 오른쪽 서브 트리로 갔다가 
        //중앙 루트노드로 온다
        //왜냐하면 루트노드르 먼저 해제하면 오른쪽 노드들은 헤제가 되지 않는다
        free(node);
    }
}

//---하위 노드중 가장 작은 값을 찾아준다.
Node *minvaluenode(Node * node){
    Node *cur = node;

    while(cur && cur->left != NULL){
        cur = cur->left;
    }
    return cur;
}

Node *deleteNode(Node *root, int key){//--포인터 함수를 이용
    //root가 null일 경우, 투리가 비어있을 경우
    if(root == NULL){
        return root;
    }
    
    //key가 노드의 키값보다 작거나 큰 경우 [하위트리에 이동]
    if(key < root->data){
        root->left = deleteNode(root->left, key);
    }
    else if(key < root->data){
        root->right = deleteNode(root->right,key);
    }
    //키가 노드의 키값과 같은 경우 [삭제]
    //******중요*********
    else{
        //노드의 자녀가 한 개일 경우(왼쪽 아니면 오른쪽)
        if(root->left == NULL){
            Node * tmp = root->right;
            free(root);
            return tmp;
        }

        else if(root->right ==NULL){
            Node *tmp = root->right;
            free(root);
            return tmp;
        }
        //*****매우 중요*******
        //노드의 자녀가 ***두 개일 정우(왼쪽 오른쪽 둘 다)***
        //오른족 서브트리에서 가장 작은 수를 선택한다.

        Node *tmp = minvaluenode(root->right);

        root->data = tmp->data;
        root->right = deleteNode(root->right, tmp->data);
    }
    return root;
}