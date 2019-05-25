#include "bits/stdc++.h"

using namespace std;

vector<vector<int> > graph(200001);
vector<int> visit;
vector<int> input(200001);
vector<int> orden(200001);
int cont=1;
int valid=1;

void bfs_visit(int s){
    queue<int> Q;
    visit[s]=1;
    Q.push(s);
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();

        for(int v:graph[u]){
            if(visit[v]==-1){
                if(orden[cont]!=v){
                    valid=0;
                }
                visit[v]=1;
                cont++;
                Q.push(v);
            }
        }
    }
}

bool ordenar(int i,int j){
    return input[i]<input[j];
}


int main(){
    int n,j,k;
    cin>>n;
    visit.resize(graph.size(),-1);
    for(int i=0;i<(n-1);i++){
        cin>>j>>k;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }
    for(int i=0;i<n;i++){
        cin>>orden[i];
        input[orden[i]]=i;
    }


    for(int i=1;i<=n;i++){
        sort(graph[i].begin(),graph[i].end(),ordenar);
    }
    bfs_visit(1);
    if(cont==n && valid==1){
        cout<<"YES"<<endl;
    }
    else{
        cout<<"NO"<<endl;
    }

    return 0;
}

