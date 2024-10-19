#include <stdio.h>
#include <queue>
#include <string>
#include <iostream>

using namespace std;

template<typename TnodeInfo, typename TedgeInfo>
class Graph {
public:
    int N;
    char **A;
    TnodeInfo *nodeInfo;
    TedgeInfo **edgeInfo;

    Graph(int numNodes) {
        int i, j;

        N = numNodes;

        A = new char*[N];
        for (i = 0; i < N; i++)
            A[i] = new char[N];

        for (i = 0; i < N; i++)
            for (j = 0; j < N; j++)
                A[i][j] = 0;

        nodeInfo = new TnodeInfo[N];

        edgeInfo = new TedgeInfo*[N];
        for (i = 0; i < N; i++)
            edgeInfo[i] = new TedgeInfo[N];
    }

    void setNodeInfo(int i, TnodeInfo info) {
        nodeInfo[i] = info;
    }

    TnodeInfo getNodeInfo(int i) {
        return nodeInfo[i];
    }

    void addEdge(int i, int j) {
        A[i][j] = A[j][i] = 1;
    }
    void removeEdge(int i, int j) {
        A[i][j] = A[j][i] = 0;
    }

    void setEdgeInfo(int i, int j, TedgeInfo info) {
        edgeInfo[i][j] = edgeInfo[j][i] = info; }

    TedgeInfo getEdgeInfo(int i, int j) {
        return edgeInfo[i][j]; }

    ~Graph() {
        int i;
        for (i = 0; i < N; i++) {
            delete A[i];
            delete edgeInfo[i];
        }
        delete A;
        delete edgeInfo;
        delete nodeInfo;
    }
};

Graph<int, int> g(4);
char* visited;

void dfs(int x) {
    int y;
    printf("%d\n", x);
    visited[x] = 1;

    for (y = 0; y < g.N; y++)
        if (g.A[x][y] && !visited[y])
            dfs(y);
}

void bfs(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++)
            if (g.A[x][y] && !visited[y]) {
                visited[y] = 1;
                Q.push(y);
            }
    }
}

void bipartie(int S) {
    std::queue<int> Q;
    int x, y;

    Q.push(S);
    visited[S] = 1;

    while (!Q.empty()) {
        x = Q.front();
        Q.pop();
        printf("%d\n", x);
        for (y = 0; y < g.N; y++){
            if (g.A[x][y] && !visited[y]) {
                g.setNodeInfo(y, 1-g.getNodeInfo(x));
                visited[y] = 1;
                Q.push(y);
            }
            if(g.getNodeInfo(x)==0)
                g.setNodeInfo(y, 1);
            else
                g.setNodeInfo(y,0);
        }
    }
}

void isConnected(){
    visited = new char[g.N];
    for (int i = 0; i < g.N; i++)
        visited[i] = 0;
    int cnt = 0;
    bfs(3);
    for(int i = 0 ; i<g.N; i++){
        if(visited[i] == 1)
            cnt++;
    }
    if(cnt == g.N){
        cout<<"Graful este conex.";
    }
    else cout<<"Graful nu este connex.";
};

int main() {
    int i;
    g.addEdge(0,1);
    g.addEdge(1,2);
    g.addEdge(2,3);
    g.addEdge(3,0);
    g.addEdge(0,2);



    isConnected();



    cout<<"\n";

    for(int i =0; i< g.N; i++){
        int d = 0;
        for(int j = 0; j < g.N; j++){
            if(g.A[i][j]==1)
                d++;
        }
        if(d<g.N){
            cout<<"No";
            break;
        }
    }
    return 0;
}

