#include<iostream>
using namespace std;

#define MAX_VTXS 256 //최대 정점 개수

//인접행열을 이용한 Graph 구현

class ADjMatgraph{
    private:
        int size;   //정점의 개수
        char vertices[MAX_VTXS];    //정점의 이름
        int adjMat[MAX_VTXS][MAX_VTXS]; //인접 행렬
    
    public: 
        ADjMatgraph(){
            reset();
        }
        ~ADjMatgraph(){}

        char getVertex(int i){
            return vertices[i];
        }

        int getEdge(int i, int j){
            return adjMat[i][j];
        }

        void setEdge(int i,int j, int val){
            adjMat[i][j] = val;
        }

        //그래프 초기화
        void reset(){
            for(int i =0; i<MAX_VTXS; i++){
                for(int j=0; j <MAX_VTXS;j++){
                    setEdge(i,j,0); //모두 0으로 초기화하기
                }
            }
        }

        //정점 삽입
        void insertVertex(char name){
            if(isFull()){
                cout<< "Graph vertex full error" << endl;
                return ;
            }

            vertices[size++] = name;
        }

        //간선 삽입 (무방향 그래프)
        void insertEdge(int u, int v){
            setEdge(u,v,1); //가중치 그래프에서는 1이 아닌 가중치 삽입
            setEdge(v,u,1); //방향 그래프에서는 삭제(<u,v>만 존재)
        }

        //그래프 정보 출력
        void display(){
            cout << "vertex size : " <<size <<endl;
            cout<<"    ";

            for(int i =0; i <size; i++){
                cout<< getVertex(i) << " ";
            }   
            cout <<endl;

            for(int i=0; i <size; i++){
                cout << getVertex(i)<<" : ";
                for(int j =0; j <size; j++){
                    cout << getEdge(i,j) << " ";
                }
                cout <<endl;
            }
        }

        bool isEmpty(){
            return size =0;
        }

        bool isFull(){
            return size > MAX_VTXS;
        }
};

int main(){
    ADjMatgraph graph;

    //정점 삽입 (A,B,C,D)
    graph.insertVertex('A');
    graph.insertVertex('B');
    graph.insertVertex('C');
    graph.insertVertex('D');

    //간선 삽입
    graph.insertEdge(0,1); //A -> B
    graph.insertEdge(0,2); //A -> C
    graph.insertEdge(0,3); // A -> D
    graph.insertEdge(2,3); //C-> D

    graph.display();
}