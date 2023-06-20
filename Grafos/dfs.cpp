/*
# Descrição:
O objetivo da função "dfs()" é aplicar o algoritmo de busca em profundidade em um 
grafo sem pesos nas arestas começando de um vértice "u". O objetivo da função
"bfs_explore()" é aplicar o algoritmo bfs em todos as componentes conexas do grafo.
Nesse código o grafo é representado por lista de adjacência.

# Parâmetros:
vector<vector<int>> adj -> Grafo representado por lista de adjacência.

dfs:
int u -> Vértice de origem do DFS.
int comp -> Índice da componente conexa do vértice u.

dfs_explore:
int vertices -> Total de vértices do grafo.

# Retorno
A função "dfs" percorre toda a componente conexa que o vértice "u" pertence, sempre
atualizando o vector "visited" que armazena se um determinado vértice foi visitado ou não.

A função "dfs_explore" não retorna nada, mas constroí o vector "ccnum" que contém
a identificação da componente conexa de cada vértice do grafo. Além disso, a variável
global "cc" armazena a quantidade total de componentes conexas do grafo.

# Complexidade:
O(V + E), Onde V é o total de vértices e E é o total de arestas do grafo.

# Referência:
https://www.youtube.com/watch?v=8tbSJuusgBI&t=1462s&ab_channel=Jo%C3%A3oPauloLeite

# Problemas:
Problema F - Prova substitutiva de ECOE44 (UNIFEI - 2022.1)
*/

#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);

using namespace std;

vector<vector<int>> adj;
vector<bool> visited;
vector<int> ccnum;
int cc;

void dfs(int u, int comp)
{
	unsigned int v;
	if(visited[u]) return;
	visited[u] = true;
	ccnum[u] = comp;
	for(v = 0; v < adj[u].size(); v++)
    	dfs(adj[u][v], comp);
    
    /*
    O trecho abaixo popula o vetor leaf[u] com a quantidade de folhas abaixo do vértice u.

    if(adj[u].size() == 1 && u != 1) 
    {
        leaf[u] = 1;
    }
    else
        for(ll v = 0; v < adj[u].size(); v++)
        {
            if(!visited[adj[u][v]])
            {
                dfs(adj[u][v]);
                leaf[u] += leaf[adj[u][v]];
            }
        }
    */
}

void dfs_explore(int vertices)
{
    visited.resize(vertices, false);
    ccnum.resize(vertices, false);

	cc = 0;
	for(int i = 0; i < vertices; i++)
    	if(!visited[i]) dfs(i, cc++);
}

int main()
{ _
    // grafo exemplo:
    adj.resize(8);

    adj[0].push_back(1); adj[0].push_back(2);
    adj[0].push_back(3); adj[1].push_back(0);
    adj[1].push_back(2); adj[2].push_back(0);
    adj[2].push_back(1); adj[2].push_back(3);
    adj[2].push_back(4); adj[2].push_back(5);
    adj[3].push_back(0); adj[3].push_back(2);
    adj[3].push_back(4); adj[4].push_back(2);
    adj[4].push_back(3); adj[5].push_back(2);
    adj[6].push_back(7); adj[7].push_back(6);
    
    dfs_explore(8);
    
    cout << "Total de compoenentes conexas: " << cc << endl;
    cout << "Componente conexa que cada vertice pertence:" << endl;
    for(int i = 0; i < ccnum.size(); i++)
        cout << i << " - " << ccnum[i] << endl;
    cout << endl;

    return 0;
}
