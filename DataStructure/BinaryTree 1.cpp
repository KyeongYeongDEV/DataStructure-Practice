#include<iostream>
using namespace std;
//트리를 위한 기본적인 함수들

typedef struct TreeNode{
    struct  TreeNode *left;    
    struct TreeNode *right;
    int data;
}TreeNode;

TreeNode *root =NULL;

void init_tree(){root = NULL;}

int empty_tree(){return root == NULL;}//root를 가리키는 주소값이 있다면 0 없다면 1

TreeNode *get_root(){return root;}//루트노드를 가리키는 주소값을 반환한다. treenode를 가리키는 포인터

TreeNode *create_tree(int val, TreeNode *left, TreeNode *right){
    TreeNode *n = (TreeNode*)malloc(sizeof(TreeNode));
    n->data = val;
    n->left = left;
    n->right = right;
    return n;
}
int main(){

}
//     n1
//   /   \
//  n2   n3  
// 이런 코드