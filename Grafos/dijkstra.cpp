/*
# Descrição:
O objetivo desse algoritmo é encontrar a distância mínima de um vértice "s" de origem
para todos os outros vértices de um digrafo ponderado (somente pesos positivos).

# Parâmetros:
vector<vector<pair<int, int>>> listaAdjacencia -> Estrutura que representa o grafo orientado e ponderado.
int s -> Índice do vértice de origem.

# Constantes:
const int INF = 0x3f3f3f3f -> Constante representando o infinito.

# Retorno
A função não retorna nada mas cria um vector "custo" contendo o custo mínimo do vértice
de origem "s" até todos os outros vértices do grafo.

# Complexidade:
O((E+V)*log V), onde E e V são o total de arestas e vértices do grafo.

# Referências:
https://www.youtube.com/watch?v=7vzdwI0A-qw&t=503s&ab_channel=Jo%C3%A3oPauloLeite

# Problemas:
https://www.beecrowd.com.br/judge/pt/problems/view/1550
*/

#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

const int INF = 0x3f3f3f3f;
using namespace std;

vector<vector<pair<int, int>>> listaAdjacencia;
vector<int> custo;

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

int main()
{
    // grafo exemplo:
    listaAdjacencia.resize(5);
    listaAdjacencia[0].push_back(make_pair(1,  1));
    listaAdjacencia[0].push_back(make_pair(2,  10));
    listaAdjacencia[0].push_back(make_pair(4,  3));
    listaAdjacencia[1].push_back(make_pair(3,  5));
    listaAdjacencia[3].push_back(make_pair(2,  1));
    listaAdjacencia[4].push_back(make_pair(2,  6));
    listaAdjacencia[4].push_back(make_pair(3,  2));
    
    dijkstra(0);
    for(int i = 0; i < custo.size(); i++)
        cout << i << " - " << custo[i] << endl;
    cout << endl;

    return 0;
}