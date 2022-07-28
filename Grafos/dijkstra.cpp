/*
# Descrição:
O objetivo desse algoritmo é encontrar o menor polígono convexo (Convex Hull) que
engloba todos os pontos de um conjuto de pontos fornecido. A função principal é
o "convexHull()".

# Parâmetros:
vector<Point> a -> Vector contendo o conjunto de pontos a ser analisado.
bool include_collinear -> "true" para que o poligono de retorno contenha pontos 
colineares e "false" caso contrário (somente vértices)

# Retorno
A função retorna um vector contendo todos os pontos do menor poligono convexo
que engloba todos os pontos do conjunto fornecido.

# Complexidade:
O(nlogn), onde n é o total de pontos.

# Referências:
https://cp-algorithms.com/geometry/convex-hull.html#grahams-scan-algorithm
https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/

# Problemas:
https://www.beecrowd.com.br/judge/pt/problems/view/1464
*/

#include <bits/stdc++.h>
#define endl '\n'
#define INF 0x3f3f3f3f
#define SIZE 10001 // Tamanho do grafo
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

vector<vector<pair<int, int>>> listaAdjacencia(SIZE, vector<pair<int,int>>());
vector<int> custo; // Vetor contendo os custos mínimos de um vértice "A" até todos os outros.

void dijkstra(int s)
{
    custo.clear();
    int n = listaAdjacencia.size();
    for(int i = 0; i < n; i++)
        custo.push_back(INF); 
        
    priority_queue<pair<int, int>, vector<pair<int, int>>, greater<pair<int, int>>> heap;
    heap.push(make_pair(s, 0));
    custo[s] = 0;
    while(!heap.empty())
    {
        int u = heap.top().first;
        heap.pop();
        for(int i = 0; i < listaAdjacencia[u].size(); i++)
        {
            int v = listaAdjacencia[u][i].first;
            int weight = listaAdjacencia[u][i].second;
            if(custo[v] > custo[u] + weight)
            {
                custo[v] = custo[u] + weight;
                heap.push(make_pair(v, custo[v]));
            }
        }
    }
}