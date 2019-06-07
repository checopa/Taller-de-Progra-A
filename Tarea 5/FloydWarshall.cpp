#include<bits/stdc++.h>

using namespace std;

typedef vector<long long> vi;
typedef vector<vi> graph;

const long long INF = 1e15;

/*
Para el caso de un grafo con pesos, en la posicion (u, v) de la matriz de adyacencia se encuentra el 'peso' asociado a la 
entre el nodo u y el nodo v.

IMPORTANTE: A diferencia del algoritmo de Dijkstra, el algoritmo de FloydWarshall utiliza una matriz de adyacencia y se
			demora mucho mas en ejecutarce, pero entrega la distancia minima para cualquier par de nodos un el grafo.

IMPORTANTE: G[u][v] sera igual a INF si no existe camino entre los nodos u y v, pero si el peso
			en las aristas es muy grande, puede que esto no sea asi (una opcion es usar una distancia 
			que nunca se puede alcanzar en el problema)

IMPORTANTE: Inicialmente la matriz de adyacencia tiene que tener los costos para las aristas del grafo, mientras que para 
			las aristas que no estan en el grafo, se les asigna un valor "infinito" (usualmente un numero muy grande, puede 
			usar la variable INF definida al inicio)

Al finalizar, G[u][v] es la menor distancia entre el nodo u y el nodo v del grafo.
*/

// AdjMat es la matriz de adyacencia de un grafo.
void allShortestPath(graph &AdjMat) {
	int n = AdjMat.size();
	for (int k = 0; k < n; k++) 
		for (int i = 0; i < n; i++)
			for (int j = 0; j < n; j++)
				AdjMat[i][j] = min(AdjMat[i][j], AdjMat[i][k] + AdjMat[k][j]);

}

