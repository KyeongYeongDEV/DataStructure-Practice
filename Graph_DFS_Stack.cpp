#include<iostream>
#include<vector>
#include<stack>
using namespace std;

int N,M,S;
vector<int> adjList[1001];
bool isVidited[1001] = {0};
stack<int> st;

void dfs(int v){
    st.push(v);

    while(!st.empty()){
        int cur = st.top(); // 루트 노드 삽입
        st.pop();

        if(isVidited[cur]) {continue;}//방문을 한 정점이면 컨티뉴

        isVidited[cur] = true; //방문을 한 노드 표시
        cout << cur << ' ';

        //숫자가 작은 노드 먼저 방문하기 위해 reverse
        for(int i = adjList[cur].size(); i >=0; i--){
            int next = adjList[cur][i];
            st.push(next);
        }
    }
}

int main() { 
    scanf("%d %d %d", &N, &M, &S); // 노드 수: N, 간선 수: M, 시작 노드: S 
for (int i=0; i<M; i++) { 
    int s, e;
    scanf("%d %d", &s, &e); 
    adjList[s].push_back(e); 
    adjList[e].push_back(s); 
} // sort
for (int i=0; i<1001; i++) { 
    sort(adjList[i].begin(), adjList[i].end());
    } 
    dfs(S);
     return 0; 
}

