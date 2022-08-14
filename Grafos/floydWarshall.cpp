/*
# Descrição:
O objetivo desse algoritmo é encontrar a distância mínima entre todos os pares
de vértices de um grafo representado por matriz de adjacências.

# Parâmetros: 
int V -> Total de vértices do grafo.
int d[MAX][MAX] -> Matriz de adjacências para representar o grafo (global). 

# Constantes
const int INF = 0x3f3f3f3f; -> Valor muito grande representado INFINITO.
#define MAX 100 -> Número máximo de vértices do grafo.

# Observações:
A matriz de adjacências d[MAX][MAX] deve ser inicializada com INF em todas as suas posições,
exceto para a diagonal principal, que deve ser preenchida com zeros.

# Retorno
A função não retorna nada, mas modifica a própria matriz de adjacências para se 
tornar a matriz de caminhos mínimos entre todos os pares de vértices.

# Complexidade:
O(V^3)

# Referência:
https://www.geeksforgeeks.org/floyd-warshall-algorithm-dp-16/

# Problemas:
BEE 1539
*/

#include <bits/stdc++.h>
#define MAX 100
const int INF = 0x3f3f3f3f;
using namespace std;

int d[MAX][MAX];

void floydWarshall(int V)
{
    int i, j, k;
    for (k = 0; k < V; k++)
        for (i = 0; i < V; i++)
            for (j = 0; j < V; j++) 
                if (d[i][j] > (d[i][k] + d[k][j]) && (d[k][j] != INF && d[i][k] != INF))
                    d[i][j] = d[i][k] + d[k][j];
}

int main()
{
    // Inicializando a matriz de adjacências
    for(int i = 0; i < 4; i++)
        for(int j = 0; j < 4; j++)
            d[i][j] = i != j ? INF : 0;

    // Setando as ligações de um grafo hipotético.
    d[0][1] = 5; d[0][3] = 10;
    d[1][2] = 3; d[2][3] = 1;

    floydWarshall(4); // Aplicando o algoritmo

    // Imprimindo a matriz de caminho mínimo.
    for(int i = 0; i < 4; i++)
    {
        for(int j = 0; j < 4; j++)
            cout << (d[i][j] == INF ? "INF" : to_string(d[i][j])) << " ";
        cout << endl;
    }

    return 0;
}