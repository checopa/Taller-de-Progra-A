#include <bits/stdc++.h>

using namespace std;

// el comando typedef se puede utilizar como una forma de abreviar la declaracion de algunas estructuras
// FORMA DE USO: typedef 'nombre_de_estructura' 'nuevo_nombre_de_estructura'

typedef vector<int> vi;
typedef vector<vi> graph;

/*
IMPORTANTE: Recordar DFS NO SIRVE (repito NO SIRVE) para obtener distancia minima en grafos sin peso, las implementaciones
			que estan acá son para determinar los nodos que estan en la componente conexa del nodo s.

A diferencia de BFS, DFS se puede implementar de forma recursiva o iterativa (con un stack).
La mayor diferencia entre las dos implementaciones es la facilidad para modificarla y usabilidad en distintos casos.
La implementacion iterativa es la mas rapida.
La implementacion recursiva es mas facil de entender y de modificar para los distintos usos de DFS (eg: toposort y
calculo de componentes fuertemente conexas).

Despues de ejecutar la funcion, sea v un nodo en el grafo, si visited[v] es uno, entonces v esta en la misma componente
conexa que s, en caso contrario, visited[v] es cero.
*/

void DFS_iterative(int s, graph &M, vi &visited) {
	stack<int> st;
	st.push(s);

	while(!st.empty()) {
		int u = st.top(); st.pop();

		visited[u] = 1;
		for(int v : M[u]) {
			if(visited[v] == 0) {
				visited[v] = 1;
				st.push(v);
			}
		}
	}
}

void DFS_recursive(int s, graph &M, vi &visited) {
	visited[s] = 1;
	for(int v : M[s]) {
		if(visited[v] == 0) {
			DFS_recursive(v, M, visited);
		}
	}
}

//