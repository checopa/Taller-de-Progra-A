#include <bits/stdc++.h>

using namespace std;


typedef pair<long long, long long> ii;
typedef vector<ii> vii;
typedef vector<vector<ii> > wgraph;

typedef vector<long long> vi;


vi dist;
vi p;
wgraph M;

void Dijsktra(long long s) {
	dist[s] = 0;
	priority_queue<ii, vector<ii>, greater<ii> > pq; pq.push(ii(0, s));

	while (!pq.empty()) {
		ii front = pq.top(); pq.pop();
		long long d = front.first, u = front.second;
		if (d > dist[u]) continue;
		
		//cout << u+1 << endl;

		for (long long j = 0; j < M[u].size(); j++) {
			ii v = M[u][j];
			if (dist[u] + v.first < dist[v.second]) {
				dist[v.second] = dist[u] + v.first;
				pq.push(ii(dist[v.second], v.second));

				p[v.second] = u;
			}
		}
	}
}

int main(){
    long long m,n,w,a,b;
    cin>>n>>m;
    dist.resize(n+1,1e15);
    p.resize(n+1);
    M.resize(n+1);
    for(long long i=0;i<m;i++){
        cin>>a>>b>>w;
        M[a].push_back(ii (w,b));
        M[b].push_back(ii (w,a));
    }
    Dijsktra(1);
    vi nodos;
    long long aux=p[n];
    nodos.push_back(n);
    if(aux!=0){
        while(aux!=0){
            nodos.push_back(aux);
            aux=p[aux];
        }
        for(long long i=nodos.size();i>0;i--){
            cout<<nodos[i-1]<<" ";
        }
        cout<<endl;
        return 0;
    }
    cout<<-1<<endl;
    return 0;
}