#include "iostream"
#include "vector"
#include "queue"

using namespace std;

vector<vector<int> > graph(100001);
vector<int> visit;
int bipartito;

void bfs_visit(int s){
    queue<int> Q;
    if(graph[s].size()!=0){
        visit[s]=0;
        Q.push(s);
    }
    while(!Q.empty()){
        int u=Q.front();
        Q.pop();

        for(int v:graph[u]){
            if(visit[v]==-1){
                visit[v]=(visit[u]+1)%2;
                Q.push(v);
            }
            else{
                if(visit[v]==visit[u]){
                    bipartito=1;
                }
            }
        }
    }
}


void bfs(int n){
    //visit.resize(graph.size(),-1);
    for(int i=0; i<n;i++){
        if(visit[i]==-1){
            bfs_visit(i);
        }
    }
}


int main(){
    int n,m,j,k;
    cin>>n>>m;
    bipartito=0;
    visit.resize((n+1),-1);
    for(int i=0;i<m;i++){
        cin>>j>>k;
        graph[j].push_back(k);
        graph[k].push_back(j);
    }
    bfs(n);
    vector<int> first;
    vector<int> second;
    if(bipartito){
        cout<<-1<<endl;
        return 0;
    }
    for(int i=0;i<visit.size();i++){
        if(visit[i]==1){
            first.push_back(i);
        }
        if(visit[i]==0){
            second.push_back(i);
        }
    }
    cout<<first.size()<<endl;
    for(int i=0;i<first.size();i++){
        cout<<first[i]<<" ";
    }
    cout<<endl;
    cout<<second.size()<<endl;
    for(int i=0;i<second.size();i++){
        cout<<second[i]<<" ";
    }
    cout<<endl;


    return 0;
}

