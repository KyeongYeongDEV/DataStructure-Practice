#include<iostream>
using namespace std;
#define MAX_STACK_SIZE 100

int err =0; //에러가 발생했는지 체크하는 변수(0:에러 없음, 1: 에러 발생)

typedef char element;

typedef struct{
    element data[MAX_STACK_SIZE];
    int top;
}Stacktype;

//스택 함수 초기화
void init_stack(Stacktype *s){
    s->top = -1;
}

//공백 상태 검출 함수
int is_empty(Stacktype *s){
    return (s->top == -1);
}

//포화상태 검출 함수
int is_full(Stacktype *s){
    return (s->top == MAX_STACK_SIZE-1);
}

//삽입 함수 
void push(Stacktype *s, element item){
    if(is_full(s)){
        cout << "*** STACK IS FULL ***"<<endl;
        return;
    }
    else
        s->data[++(s->top)] = item;
}

//삭제 함수
element pop(Stacktype *s){
    if(is_empty(s)){
        cout<< "*** STACK IS EMPTY ***"<<endl;
        exit(1);
    }
    else
        return s->data[(s->top)--];
}

element peek(Stacktype *s){
    if(is_empty(&s)){
        cout<< "*** STACK IS EMPTY ***"<<endl;
        exit(1);
    }
    else return s->data[s->top];
}
//======== 스택 코드 끝 ============

//후위 표기 수식 계산 함수
int eval(char exp[]){
    int op1,op2,value;
    int len = strlen(exp);
    char ch;
    Stacktype s;

    init_stack(&s);
    for(int i = 0; i <len; i++){
        ch == exp[i];
        if(ch != '+' && ch != '-' && ch != '*' && ch != '/'){//입력이 피연산자라면
            value = ch - '0'; //문자를 정수형으로 바꾸어 저장한다.
            push(&s,value);
        }
        else{ //연산자이면 피연산자를 스택에서 제거
            op2 = pop(&s);
            op1 = pop(&s);
            switch(ch){//연산을 수행하고 스택에 저장
                case '+': push(&s,op1+op2); break;
                case '-': push(&s,op1-op2); break;
                case '*': push(&s,op1*op2); break;
                case '/': push(&s,op1/op2); break;
            }
        }
    }
    return pop(&s);
}

//연산자의 우선순위를 반환한다.
int prec(char op){
    switch(op){
        case '(': case ')': return 0;
        case '+': case '-': return 1;
        case '*': case '/': return 2;
    }
    return -1;
}

//수식 변환 함수
element * infix_to_postfix(element exp[]){
    int idx =0; // post_arr의 index
    char ch,op;
    Stacktype s;
    element* postfix_arr = (element*)malloc(MAX_STACK_SIZE);

    if(postfix_arr == NULL){
        cout << "메모리 할당 에러\n";
        exit(1);
    }

    init_stack(&s); //스택 초기화

    //중위 표기식으로 표현된 식을 순회
    for(int i =0; i <len; i++){
        ch = exp[i]; //값을 뽑는다.
        
        if('0' <= ch && ch <= '9'){//일반 숫자라면 그대로 postfix_arr에 추가
            postfix_arr[idx++] = ch;
        }

        //연산자라면
        else if(ch == '+' || ch == '-' || ch == '*' || ch == '/'){
            //스택의 top 값이 현재 연산자보다 우선순위가 높다면
            while(!is_empty(&s) &&(prec(ch) <= prec(peek(&s))){
                //해당 값들은 모두 추가해준다.
                postifx_arr[idx++] = peek(&s);
                pop(&s);
            }
            //자기자신을 스택에 측한다.
            push(&s,ch);
        }

        else if(ch == '('){// '(' 는 무조건 스택에 추가한다.
            push(&s,ch);
        }

        else if(ch == ')'){// ')'가 나오면 '('가 나올 때까지 스택에서 pop하여 추가해준다.
            op = pop(&s);
            while(op != '('){
                postifx_arr[idx++] = op;
                op = pop(&s);   
            }
        }

        while(!is_empty(&s)){//아직 스택에 남아있는 값들을 모두 추가해준다.
            op = peek(&s);
            pop(&s);
            postifx_arr[idx++] = op;
        }

        postifx_arr[idx] = '0';//문자열 끝을 지정해준다.
        return postifx_arr;
    }
}

int main(){
    element expression[MAX_STACK_SIZE];
    char word[100];

    cout <<"중위 표기식 입력 :"<<endl;
    cin >> expression;

    cout <<"중위 표기식을 후위표기식으로 변환"<<endl;
    element *result = infix_to_postfix(expression);
    cout << result<<endl;
    cout << eval(result);
}

//https://www.crocus.co.kr/1703