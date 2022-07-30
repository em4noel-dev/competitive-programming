/*
# Descrição:
O objetivo desse algoritmo é construir a matriz tranposta de uma matriz qualquer.
A matriz transposta é contruída por referência na função "transpose".

# Parâmetros:
int A[][MAX] -> Matriz original.
int B[][MAX] -> Matriz transposta.
int M -> Total de linhas da matriz A.
int N -> Total de colunas da matriz A.

# Constantes:
#define MAX 50 -> Dimensão máxima da matriz.

# Retorno
A função não retorna nada mas modifica por referência a matriz B passada como
parâmetro.

# Complexidade:
O(M*N), Onde N é o número de colunas e M é o número de linhas da matriz.

# Referência:
https://www.geeksforgeeks.org/program-to-find-transpose-of-a-matrix/

# Problemas:
Problema B - Simulado UFU - 30/07/2022 (Grid)
*/

#include <bits/stdc++.h>
using namespace std;
#define MAX 50

void transpose(int A[][MAX], int B[][MAX], int M, int N)
{
    for(int i = 0; i < N; i++)
        for(int j = 0; j < M; j++)
            B[i][j] = A[j][i];
}

int main()
{
    int M = 3, N = 4;
    int A[MAX][MAX] = {{ 1, 1, 1, 1 },
                       { 2, 2, 2, 2 },
                       { 3, 3, 3, 3 }};
    int B[MAX][MAX];
    transpose(A, B, M, N);
 
    cout << "Matriz transposta: " << endl;
    for(int i = 0; i < N; i++)
    {
        for(int j = 0; j < M; j++)
            cout << " " << B[i][j];
        cout << "\n";
    }

    return 0;
}