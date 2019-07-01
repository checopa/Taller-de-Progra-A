#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

// Algoritmo de Dinic para obtener el flujo máximo en un grafo 
// con capacidades en las aristas (dirigido o no dirigido) entre
// un nodo fuente (source) y un nodo de salida (sink o dest)

class Dinic {
    struct edge {
        int to, rev;
        ll f, cap;
    };
 
    vector<vector<edge> > g;
    vector<ll> dist;
    vector<int> q, work;
    int n, sink;
 
    bool bfs(int start, int finish) {
        dist.assign(n, -1);
        dist[start] = 0;
        int head = 0, tail = 0;
        q[tail++] = start;
        while (head < tail) {
            int u = q[head++];
            for (int i = 0; i < g[u].size(); ++i) {
                const edge &e = g[u][i];
                int v = e.to;
                if (dist[v] == -1 and e.f < e.cap) {
                    dist[v] = dist[u] + 1;
                    q[tail++] = v;
                }
            }
        }
        return dist[finish] != -1;
    }
 
    ll dfs(int u, ll f) {
        if (u == sink)
            return f;
        for (int &i = work[u]; i < (int)g[u].size(); ++i) {
            edge &e = g[u][i];
            int v = e.to;
            if (e.cap <= e.f or dist[v] != dist[u] + 1)
                continue;
            ll df = dfs(v, min(f, e.cap - e.f));
            if (df > 0) {
                e.f += df;
                g[v][e.rev].f -= df;
                return df;
            }
        }
        return 0;
    }
 
public:
    Dinic(int n) {
        this->n = n;
        g.resize(n);
        dist.resize(n);
        q.resize(n);
    }
 
    void add_edge(int u, int v, ll cap) {
        edge a = {v, (int)g[v].size(), 0, cap};
        edge b = {u, (int)g[u].size(), 0, 0}; //Poner cap en vez de 0 si la arista es bidireccional
        g[u].push_back(a);
        g[v].push_back(b);
    }
 
    ll max_flow(int source, int dest) {
        sink = dest;
        ll ans = 0;
        while (bfs(source, dest)) {
            work.assign(n, 0);
            while (ll delta = dfs(source, LLONG_MAX))
                ans += delta;
        }
        return ans;
    }
};

int main() {
    int n = 4;
    Dinic dinic(n); // Inicialización, n es el número de nodos

    dinic.add_edge(0, 1, 5); // agregar arista entre u y v con capacidad cap,
    dinic.add_edge(0, 2, 3); // los nodos están indexados desde 0
    dinic.add_edge(1, 3, 2);
    dinic.add_edge(2, 3, 4);

    cout << dinic.max_flow(0, 3) << "\n"; // obtener el max flow entre source y dest
}
