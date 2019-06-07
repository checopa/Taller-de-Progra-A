#include <bits/stdc++.h>

using namespace std;

// el comando typedef se puede utilizar como una forma de abreviar la declaracion de algunas estructuras
// FORMA DE USO: typedef 'nombre_de_estructura' 'nuevo_nombre_de_estructura'

typedef vector<int> vi;
typedef vector<vi> graph;

/*
IMPORTANTE: Recordar BFS tambien sirve para obtener distancia minima en grafos sin peso, pero esta implementacion 
			es para saber los nodos que estan en la misma componente conexa que el nodo s, por lo que el vector 
			visited esta inicializado con 0.

Despues de ejecutar la funcion, sea v un nodo en el grafo, si visited[v] es uno, entonces v esta en la misma componente
conexa que s, en caso contrario, visited[v] es cero.
*/

void BFS(int s, graph &M, vi &visited) {
	visited[s] = 1;

	queue<int> q; q.push(s);
	while(!q.empty()) {
		int u = q.front(); q.pop();

		for(int v : M[u]) {
			if(visited[v] == 0) {
				visited[v] = 1;
				q.push(v);
			}
		}
	}
}

//