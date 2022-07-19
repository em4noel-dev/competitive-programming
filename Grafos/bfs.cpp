/*
# Descrição:
O objetivo da função "bfs" é aplicar o algoritmo de busca em largura em um grafo sem pesos nas arestas 
(todas as arestas com peso 1) e calcular a distância mínima de um vértice “s” de origem em relação a 
todos os outros. Nesse código o grafo é representado por lista de adjacência.

# Parâmetros: 
int s -> Indíce do vértice de origem.

# Constantes
#define SIZE 1000001 -> Número máximo de vértices do grafo.

# Retorno
A função bfs não retorna nada, mas constroí o array "dist[SIZE]", que contém
as distância mínimas do vértice de origem "s" em relação a todos os outros.

# Complexidade:
O(V + E), Onde V é o total de vértices e E é o total de arestas do grafo.

# Referência:
https://www.youtube.com/watch?v=7vzdwI0A-qw&t=300s&ab_channel=Jo%C3%A3oPauloLeite

# Problemas:
https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/A
*/

#include <bits/stdc++.h>
#define SIZE 1000001
using namespace std;

vector<vector<pair<int, int>>> listaAdjacencia(SIZE, vector<pair<int,int>>());
int dist[SIZE];

void bfs (int s)
{
    memset(dist, -1, SIZE*sizeof(int));
    dist[s] = 0;
    queue <int> q;
    q.push(s);
    while (!q.empty())
    {
        int u = q.front();
        q.pop();
        for (int i = 0; i < listaAdjacencia[u].size(); i++)
        {
            int v = listaAdjacencia[u][i].first;
            if (dist[v] == -1)
            {
                dist[v] = dist[u] + 1;
                q.push(v);
            }
        }
    }
}

int main()
{
    // grafo exemplo. OBS: make_pair(ligante, peso)
    listaAdjacencia[0].push_back(make_pair(1, 1));
    listaAdjacencia[0].push_back(make_pair(3, 1));
    listaAdjacencia[0].push_back(make_pair(4, 1));
    listaAdjacencia[0].push_back(make_pair(5, 1));

    listaAdjacencia[1].push_back(make_pair(0, 1));
    listaAdjacencia[1].push_back(make_pair(2, 1));

    listaAdjacencia[2].push_back(make_pair(1, 1));
    listaAdjacencia[2].push_back(make_pair(3, 1));

    listaAdjacencia[3].push_back(make_pair(0, 1));
    listaAdjacencia[3].push_back(make_pair(2, 1));

    listaAdjacencia[5].push_back(make_pair(0, 1));
    listaAdjacencia[5].push_back(make_pair(4, 1));

    bfs(0);

    for(int i = 0; i < 5; i++)
        cout << dist[i] << " ";
    cout << endl;
    
    return 0;
}