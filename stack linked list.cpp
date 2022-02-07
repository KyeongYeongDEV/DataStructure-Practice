#include<iostream>
using namespace std;

typedef struct stack{
    int data;
    struct stack *next;
}stack;

stack *top;

//공백인지 검사해주는 함수
int empty(){
    if(top == NULL){
        cout << "이 스택은 비어있습니다.\n";
        return 1;
    }
    return 0;
}

//push 스택에 삽입
void push(int data){
    stack *newstack = (stack*)malloc(sizeof(stack));
    newstack->data = data;
    newstack->next = top;
    top = newstack;  
}

//pop 스택의 top 삭제
int pop(){
    if(!empty()){
        stack *Stmp = top;
        int Sdata = top->data;
        top = Stmp->next;
        free(Stmp);
        return Sdata;
    }
    return 0;
}

//peek top이 무엇인지 출력
int peek(){
    if(!empty()){
        return top->data;
    }

    return 0;
}

//스택 전부를 출력
void Allstack(){
    if(!empty()){
        stack *tmp = top;

        while(tmp){
            cout << tmp->data <<"   ";
            tmp = tmp->next;
        }
        cout << "\n";
    }
}

int main(){
    Allstack();//공백이라 오류 발생
    push(1);
    push(2);
    push(3);
    Allstack();
    pop();
    pop();
    Allstack();
    push(100);
    Allstack();
}