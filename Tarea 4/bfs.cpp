#include "iostream"
#include "vector"
#include "queue"

using namespace std;

vector<vector<int> > graph;
vector<int> dist;

void bfs_visit(int s){
    queue<int> Q;
    dist[s]=0;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();

        for(int v:graph[u]){
            if(dist[v]==-1){
                dist[v]=dist[u]+1;
                Q.push(v);
            }
        }
    }
}

void bfs(){
    dist.resize(graph.size(),-1);
    for(int i=0; i<graph.size();i++){
        if(dist[i]==-1){
            bfs_visit(i);
        }
    }
}