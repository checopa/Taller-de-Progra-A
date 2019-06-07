#include <bits/stdc++.h>

using namespace std;


vector<int> dist;
vector<int> inqueue;
vector<int> casos;

void bfs_visit(int s,vector<vector<int> > graph){
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
void mod(){
    for(int i=0;dist.size();i++){
        dist[i]=-1;
    }
    for(int i=0;inqueue.size();i++){
        inqueue[i]=-1;
    }
}
int men(){
    int min=INT_MAX;
    for(int i=0;dist.size();i++){
        dist[i]<min;
        min=dist[i];
    }
    return min;
}

void unlock(int L, int U,vector<int> RV){
    vector<vector<int> > graph(10001);
    queue<int> P;
    P.push(L);
    inqueue[L]=1;
    while(!P.empty()){
        int u=P.front();
        P.pop();
        for(int i=0;i<RV.size();i++){
            int val=(u+RV[i])%10000;
            if(inqueue[val]==-1){
                graph[u].push_back(val);
                graph[val].push_back(u);
                P.push(val);
            }

        }
    }
    bfs_visit(L,graph);
    casos.push_back(men());
}

int main(){
    int L,U,R,RV,ca=0;
    cin>>L>>U>>R;
    dist.resize(10001,-1);
    inqueue.resize(10001,-1);
    while(R!=0 && U!=0 && R!=0){
        vector<int> RR;
        for(int i=0;i<R;i++){
            cin>>RV;
            RR.push_back(RV);
        }
        unlock(L,U,RR);
        mod();
        ca++;
        cin>>L>>U>>R;
    }
    for(int i=0;i<ca;i++){
        cout<<"Case "<<i<<":";
        if(casos[i]==-1){
            cout<<"Permanently Locked"<<endl;
        }
        else{
            cout<<casos[i]<<endl;
        }
    }
    return 0;
}
