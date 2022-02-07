#include<iostream>
using namespace std;
//여러 가지 순회 방법과 추가적인 함수들 공부

typedef struct TreeNode{
    struct  TreeNode *left;    
    struct TreeNode *right;
    int data;
}TreeNode;

TreeNode *root =NULL;

void init_tree(){root = NULL;}

int empty_tree(){return root == NULL;}//root를 가리키는 주소값이 있다면 0 없다면 1

TreeNode *get_root(){return root;}//루트노드를 가리키는 주소값을 반환한다. treenode를 가리키는 포인터

TreeNode *create_tree(int val, TreeNode *left, TreeNode *right){//트리생성
    TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = val;
    n->left = left;
    n->right = right;
    return n;
}
//-----------여러 가지 순회들-----------------------------------

void preorder(TreeNode *n){//전위 순회 - 루트가 제일 앞에 오는 순회
    if( n != NULL){//루트를 가르키는 것이다.
        cout<< "[" << n->data << "]"; //value 값 출력
        preorder(n->left); //왼쪽자식
        preorder(n->right); //오른쪽 자식
    } //재귀를 이용해 왼쪽부터 다 불러오고 그 다음 오른쪽을 불러온다.
}

void inorder(TreeNode *n){//중위 순회 - 투르가 중간에 오는 순회
    cout <<"가\n";
    if(n != NULL){
        inorder(n->left);
        cout << "b";
        cout << "["<<n->data << "]";
        cout<<"c";
        inorder(n->right);
    }
}

void postorder(TreeNode *n){//후위순회 - 루트가 마지막에 오는 순회
    if(n != NULL){
        postorder(n->left);
        postorder(n->right);
        cout << "[" << n->data <<"]";
    }
}

//순회 같은 경우는 상황에 맞게 사용하는 것이 용이하다.

//----------추가 함수들-------------------------
int count_node(TreeNode *n){//노드의 개수를 구해준다.
    if(n == NULL){return 0;}//루트가 가리키는 게 NULL이면 투르노드도 없으니 0을 리턴한다.

    return 1+count_node(n->left) + count_node(n->right);
    //그렇지 않으면 루트는 있는 것이고 자식들의 수를 세어 반환한다.

}

int count_leaf(TreeNode *n){//단말노드(자식이 없는 노드) = 리프노드 개수 카운팅
    if(n == NULL) return 0;//루트 노드가 비었으면
    
    if(n->left == NULL && n->right == NULL) return 1; //로트노드의 왼쪽과 오른쪽 자식이 없으면 단말노드

    else return count_leaf(n->left) + count_leaf(n->right);
    //자식이 있으면 그 자식의 자식이 있는지 확인한다.
}

int height(TreeNode *n){
    int hleft,hright;
    if(n == NULL) return 0;
        hleft = height(n->left);//왼쪽 자식들로 만든 높이를 반환
        hright = height(n->right);//오른쪽 자식들로 만든 높이를 반환
        return (hleft>hright)? hleft+1 : hright+1 ;
        //그 후 둘 중 큰 걸 고른 뒤 참이면 왼쪽 거짓이면 오른쪽 반환;
}

int main(){
    TreeNode *b,*c, *d, *e, *f, *g, *h;
    init_tree();
    g= create_tree(7,NULL,NULL);
    h= create_tree(8,NULL,NULL);
    e= create_tree(5,g,h);
    f= create_tree(6,NULL,NULL);
    d= create_tree(4,NULL,NULL);
    b= create_tree(2,d,NULL);
    c= create_tree(3,b,c);
    root = create_tree(1,b,c);

    //***자식을 만들고 부모를 만들어야 한다.
    //사람이랑 반대 개념
}