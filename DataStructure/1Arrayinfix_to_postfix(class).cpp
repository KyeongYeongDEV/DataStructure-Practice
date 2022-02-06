#include<iostream>
using namespace std;

typedef int element;
const int MAX_NUM =100;

class Stack{
    public:
        element data[MAX_NUM];
        int top; //마지막 원소를 가리키는 인덱스

        Stack(){
            top = -1; //초기화
        }
        
        bool is_empty(){ //스택이 공백인지 검사
            //if(top == -1) return true;
            //else return false;
            return (top == -1);
        }

        bool is_full(){ //스택 배열이 가득찼는지 검사
            //if(top == MAX_NUM-1) return true;
            //else return flase;
            return (top == MAX_NUM-1);
        }
        
        void push(element value){//스택에 대입
            if(is_full()){
                cout<<"STACK OVERFLOW!! "<<endl;
                exit(-1);
            }
            else{
                //top++;
                //data[top] = value;
                data[++top] = value;
            }
        }

        element pop(){ //젤 위의 스택 삭제
            if(is_empty()){
                cout << "STACK UNDERFLOW!!"<<endl;
                eixt(-1);
            }
            else{
                //element x = data[top];
                //top--;
                //return(x);
                return (data[top--]);
            }
        }

        element peek(){
            if(is_empty()){
                 cout << "STACK UNDERFLOW!!"<<endl;
                eixt(-1);
            }
            else{
                return data[top];
            }
        }

        void PrintStack(){
            cout << "000 스택 상태 000"<endl;
            for(int i = top; i >=0; i--){
                cout << data[i]<<endl;
            }
        }
};

void infix_to_postfix(char *infix, char *postfix){
    Stack PStack;
    int j =0;

    for(int i=0; i< strlen(infix); i++){
        char ch = infix[i];
        if(ch == '('){continue;}
        else if(ch == "+" || ch =="-" || ch =="*" || ch == "/"){//연산자일 경우
            PStack.push(ch);
        }
        else if(ch == ')'){
            //char op = PStack.pop();
            //postfix[j++] = op;
            //j++;
            postfix[j++] = PStack.pop();
        }
        else{//일반 문자 내지 피연산자
            postfix[j++] = ch;
        }
    }
    while(!PStack.is_empty()){
        postfix[j++] = PStack.pop();
    }
    postfix[j] = '\0';
}

int main(){
    char infix[100];
    char postfix[100];

    cout << "중위식을 입력하세요: ";
    //cin >>infix;
    getline(infix,100);

    infix_to_postfix(infix,postfix);
    cout<< "변환된 후위 표기식은 : "<<postfix <<endl;
}

//https://ppomelo.tistory.com/46
//⬆️ 참고 사이트
