#include "iostream"
#include "vector"
#include "queue"

using namespace std;

vector<vector<int> > graph;
int t;
vector<int> entry_time;
enum color {UNVISITED,IN_STACK,VISITED};
vector<color> state;

void dfs_visit(int u){
    entry_time[t++];
    state[u]=IN_STACK;
    for(int v:graph[u]){
        if(state[v]==UNVISITED){
            dfs_visit(v);
        }
        else if (state[v]==IN_STACK){
            cout<<"Back Edge"<<endl;
        }
        else{
            if(entry_time[v]>entry_time[u]){
                cout<<"Forward Edge"<<endl;
            }
            else{
                cout<<"Cross Edge"<<endl;
            }
        }
    }
    state[u]=VISITED;
}

void dfs(){
    t=0;
    state.resize(graph.size(),UNVISITED);
    entry_time.resize(graph.size(),-1);

    for(int v:graph[u]){
        if(state[v]==UNVISITED){
            dfs_visit(u);
        }
    }
}