/*
# Descrição:
O objetivo desse algoritmo é explorar um array 2D de maneira recursiva 
semelhante ao DFS. Nesse arquivo esta presente dois estilos diferentes
de implementação, a função "explore()" e a função "exploreV2()".

# Constantes:
int aux1[] = {-1, +1, 0, 0}; -> Vetor auxiliar para a primeira função explore.
int aux2[] = {0, 0, -1, +1}; -> Vetor auxiliar para a primeira função explore.
#define MAX 50 -> Tamanho máximo da matriz.

# Parâmetros:
int m[MAX][MAX] -> Matriz global que se deseja explorar.
int N -> Total de linhas da matriz.
int M -> Total de colunas da matriz.

int i -> índice da linha da célula desejada.
int j -> índice da linha da coluna desejada.
int x -> Valor auxiliar para parâmetro (varia conforme o problema)

# Retorno
As funções não retornam nada mas alteram a matriz global.

# Complexidade:
Aproximadamente O(N*M)

# Referência:
https://www.geeksforgeeks.org/depth-first-traversal-dfs-on-a-2d-array/

# Problemas:
BEE 2012
*/

#include <bits/stdc++.h>
#define MAX 50
using namespace std;

// Matriz exemplo (remover a inicialização)
int m[MAX][MAX] = {{ 1, 1, 1, 1, 1, 0},
                   { 1, 0, 0, 0, 1, 0},
                   { 1, 0, 1, 1, 1, 0},
                   { 1, 0, 0, 0, 0, 0}};
int N, M;

int aux1[] = {-1, +1, 0, 0};
int aux2[] = {0, 0, -1, +1};
void explore(int i, int j, int x)  // Alterar conforme necessário
{
    m[i][j] = 2;
    for(int k = 0; k < 4; k++)
        if(i+aux1[k] >= 0 && i+aux1[k] < N && j+aux2[k] >= 0 && j+aux2[k] < M && m[i+aux1[k]][j+aux2[k]] == x) 
            explore(i+aux1[k], j+aux2[k], x);
}

void exploreV2(int i, int j, int x)
{
    if(m[i][j] == 2 || m[i][j] == 3) return;
    if(m[i][j] == x) m[i][j] = 3;
    if(i > 0) exploreV2(i-1, j, x);
    if(j > 0) exploreV2(i, j-1, x);
    if(i < N-1) exploreV2(i+1, j, x);
    if(j < M-1) exploreV2(i, j+1, x);
}

int main()
{
    // Exemplo: converter 1 -> 2 e 0 -> 3
    N = 4; M = 6;
    explore(0, 0, 1);
    exploreV2(0, 5, 0);

    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << m[i][j] << " ";
        cout << endl;
    }
    return 0;
}