#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;

// Algoritmo para obtener un orden topológico
// en un grafo dirigido sin ciclos (DAG)

vvi adj; // Lista de adyacencia del grafo
vi vis; // Arreglo de visitados para dfs
vi ans; // Arreglo donde se guarda el orden topológico de los nodos

void topo_sort(int v) {
    vis[v] = 1;
    for (int i = 0; i < adj[v].size(); ++i) {
        int to = adj[v][i];
        if (!vis[to]) topo_sort(to);
    }
    ans.push_back(v); // es un dfs modificado, solo basta agregar esta linea
}

int main() {
    int n, m;
    cin >> n >> m; // num de nodos y aristas

    // se lee la lista de adyacencia
    adj = vvi(n);
    vis = vi(n);
    for (int i = 0; i < m; ++i) {
        int a, b;
        cin >> a >> b;
        adj[a].push_back(b);
    }

    for (int i = 0; i < n; ++i) {
        if (!vis[i]) {
            topo_sort(i);
        }
    }

    // terminado el loop, ans tiene el orden en reversa
    reverse(ans.begin(), ans.end());

    cout << "orden: ";
    for (int i = 0; i < n; ++i) cout << ans[i] << " ";
    cout << "\n";
}
