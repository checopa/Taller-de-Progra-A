#include "iostream"
#include "vector"
#include "queue"

using namespace std;

vector<vector<int> > graph(100001);
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
int max(vector<int> dist){
    int m=0;
    int ind=0;
    for(int i=0;i<dist.size();i++){
        if(m<dist[i]){
            m=dist[i];
            ind=i;
        }
    }
    return ind;
}


void bfs(){
    dist.resize(graph.size(),-1);
    for(int i=0; i<graph.size();i++){
        if(dist[i]==-1){
            bfs_visit(i);
        }
    }
}


int main(){
    int n,j,k,s,m;
    cin>>n;
    //graph.resize(n);
    dist.resize(graph.size(),-1);
    for(int i=0;i<(n-1);i++){
        cin>>j>>k;
        s=j;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }
    bfs_visit(s);
    m=max(dist);
    for(int i=0;i<dist.size();i++){
        dist[i]=-1;
    }
    bfs_visit(m);
    m=dist[max(dist)];
    cout<<m<<endl;
    return 0;
}

