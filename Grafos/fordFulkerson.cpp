/*
# Descrição:
O objetivo desse algoritmo é encontrar o fluxo máximo entre um vértice de origem (fonte) até
um vértice de destino (sumidouro). O grafo é representado por matriz de adjacência. A função
principal utilizada é "fordFulkerson()".
OBS: Remover o grafo global exemplo ao utilizar o algoritmo.

# Parâmetros:
int graph[V][V] -> Grafo representado por matriz de adjacência.
int s -> Índice do vértice de origem (fonte)
int t -> Índice do vértice de destino (sumidouro)

# Constantes
#define V 202 -> Número máximo de vértices do grafo.

# Retorno
A função retorna o fluxo máximo de um vértice fonte "s" para um vértice destino "t"

# Complexidade:
O(EV^3), Onde V e E são respectivamente, a quantidade de vértices e arestas do grafo. 

# Referência:
https://www.geeksforgeeks.org/ford-fulkerson-algorithm-for-maximum-flow-problem/

# Problemas:
Problema B - Prova substitutiva de ECOE44 (UNIFEI - 2022.1)
*/

#include <bits/stdc++.h>
#define V 202
using namespace std;

// Grafo exemplo
int graph[V][V] = {{ 0, 16, 13, 0,  0, 0}, { 0, 0, 10, 12, 0,  0},
                   { 0,  4, 0,  0, 14, 0}, { 0, 0,  9,  0, 0, 20},
                   { 0,  0, 0,  7,  0, 4}, { 0, 0,  0,  0, 0,  0}};

bool bfs(int rGraph[V][V], int s, int t, int parent[])
{
	bool visited[V];
	memset(visited, 0, sizeof(visited));
 
	queue<int> q;
	q.push(s);
	visited[s] = true;
	parent[s] = -1;

	while (!q.empty()) 
    {
    	int u = q.front();
    	q.pop();
 
    	for (int v = 0; v < V; v++) 
        {
        	if (visited[v] == false && rGraph[u][v] > 0) 
            {
            	if (v == t) 
                {
                	parent[v] = u;
                	return true;
            	}
            	q.push(v);
            	parent[v] = u;
            	visited[v] = true;
        	}
    	}
	}
	return false;
}

int fordFulkerson(int s, int t)
{
	int u, v;
	int rGraph[V][V];
	for (u = 0; u < V; u++)
    	for (v = 0; v < V; v++)
        	rGraph[u][v] = graph[u][v];

	int parent[V];
	int max_flow = 0;
	while (bfs(rGraph, s, t, parent)) 
    {
    	int path_flow = INT_MAX;
    	for (v = t; v != s; v = parent[v]) 
        {
        	u = parent[v];
        	path_flow = min(path_flow, rGraph[u][v]);
    	}
 
    	for (v = t; v != s; v = parent[v]) 
        {
        	u = parent[v];
        	rGraph[u][v] -= path_flow;
        	rGraph[v][u] += path_flow;
    	}
 
    	max_flow += path_flow;
	}
	return max_flow;
}

int main()
{
    cout << "Fluxo maximo entre os vertices 0 e 5: " << fordFulkerson(0, 5);
	return 0;
}