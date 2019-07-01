#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
typedef vector<vi> vvi;
typedef vector<string> vs;

// Algoritmo para obtener un orden topológico
// en un grafo dirigido sin ciclos (DAG)

vvi adj(105); // Lista de adyacencia del grafo
vi vis(105); // Arreglo de visitados para dfs
vi ans; // Arreglo donde se guarda el orden topológico de los nodos
vs letras;
vi esta;

void topo_sort(int v) {
    vis[v] = 1;
    for (int i = 0; i < adj[v].size(); ++i) {
        int to = adj[v][i];
        if (!vis[to]) topo_sort(to);
    }
    ans.push_back(v); // es un dfs modificado, solo basta agregar esta linea
}

bool is(int k){
    for (int i=0;i<esta.size();i++){
        if(esta[i]==k){
            return true;
        }
    }
    return false;
}

int main() {

    string s;
    cin>>s;
    int n=0;
    while(s!="#"){
        letras.push_back(s);
        cin>>s;
    }

    for(int i=0;i<(letras.size()-1);i++){
        for(int j=0;j<(min(letras[i].size(),letras[i+1].size()));j++){
            if(!is((int)letras[i][j])){
                esta.push_back((int)letras[i][j]);
            }

            if(letras[i][j]!=letras[i+1][j]){
                adj[(int)letras[i][j]].push_back((int)letras[i+1][j]);
                break;
            }
        }
    }
    n=esta.size();
    for (int i = 0; i < n; ++i) {
        if (!vis[esta[i]]) {
            topo_sort(esta[i]);
        }
    }

    // terminado el loop, ans tiene el orden en reversa
    reverse(ans.begin(), ans.end());
    for (int i = 0; i < ans.size(); ++i) cout << (char)ans[i];
    cout << "\n";

    return 0;
}
