/*
# Descrição:
O objetivo desse algoritmo é encontrar todos os subgrafos fortemente conexos de um grafo direcionado 
sem pesos nas arestas em tempo linear. A função “strongconnect” é uma função auxiliar utilizada pela 
função principal “tarjan”. Um grafo é fortemente conexo se em todo par de vértices, os vértices são 
mutuamente atingíveis.

# Parâmetros:
vvi graph(MAX, vi()) -> grafo principal representado por lista de adjacência. (começa pelo vértice 1 e não pelo 0)
int totalVertices -> Total de vértices do grafo.

# Constantes
#define MAX 2001 -> Número máximo de vértices do grafo.

# Retorno
A função “tarjan(int totalVertices)" não retorna nada, mas preenche a lista global “scc” 
que contém todos os vértices de cada um dos subgrafos fortemente conexos do grafo principal.

# Complexidade:
O(V + E), Onde V é o total de vértices e E é o total de arestas do grafo.

# Referência:
https://gist.github.com/APwhitehat/e2ae94b811defc7407bc320f98fd268b

# Problemas:
https://www.beecrowd.com.br/judge/pt/problems/view/1128
*/

#include <bits/stdc++.h>
#define MAX 2001
using namespace std;
typedef vector<int> vi;
typedef vector<vi> vvi;

int foundat;
vvi graph(MAX, vi()), scc;
vi disc, low;
bool onstack[MAX];

void strongconnect(int u)
{
    static stack<int> st;
    disc[u] = low[u] = foundat++;
    st.push(u);
    onstack[u] = true;
    for(auto i : graph[u])
        if(disc[i] == -1)
        {
            strongconnect(i);
            low[u] = min(low[u], low[i]);
        }
        else if(onstack[i])
            low[u] = min(low[u], disc[i]);
    if(disc[u] == low[u])
    {
        vi scctem;
        while(1)
        {
            int v = st.top();
            st.pop(); onstack[v] = false;
            scctem.push_back(v);
            if(u == v) break;
        }
        scc.push_back(scctem);
    }
}

void tarjan(int totalVertices)
{
    foundat = 1;
    memset(onstack, false, MAX*sizeof(bool));
    disc.clear(); disc.resize(totalVertices+1, -1);
    low.clear(); low.resize(totalVertices+1);
    scc.clear();
    for(int i = 0; i < totalVertices; i++)
        if(disc[i+1] == -1)
            strongconnect(i+1);
}

int main()
{
    // grafo exemplo
    graph[1].push_back(5); // Começa pela vértice 1
    graph[2].push_back(1);
    graph[3].push_back(2);
    graph[3].push_back(4);
    graph[4].push_back(3);
    graph[5].push_back(2);
    graph[6].push_back(5);
    graph[6].push_back(2);
    graph[6].push_back(7);
    graph[7].push_back(6);
    graph[7].push_back(3);
    graph[8].push_back(8);
    graph[8].push_back(7);
    graph[8].push_back(4);

    tarjan(8);
    
    int i = 0;
    for(auto componenteForte : scc)  // Cada subgrafo fortemente conexo
    {
        cout << "Subgrafo fortemente conexo: " << ++i << endl;
        for(auto vertice : componenteForte) // Vértices do subgrafo em questão
            cout << vertice << " ";
        cout << endl;
    }
    graph.clear();

    return 0;
}