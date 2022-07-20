/*
# Descrição:
Essa função verifica se é possível formar um grafo simples por meio de uma sequência de graus fornecida,
utilizando o Teorema de Erdős–Gallai.

# Parâmetros: 
ull N -> total de vértices do grafo.
ull a[MAX] -> vetor global contendo o grau de cada vértice, começando no índice 1. 

# Constantes
#define INF 100000000 -> Número grande representando INFINITO. 
#define MAX 100001    -> Número máximo de vértices do grafo.

# Retorno
"true" caso for possível, "false" caso não for possível.

# Complexidade:
≈ O(N), onde N é o número de vértices do grafo, considerando que a sequência de graus 
esteja ordenada em ordem não-crescente.

# Referência:
Aulas do professor Leandro Miranda Zatesko (UTFPR):
https://drive.google.com/file/d/1A3Y82RQr6Za0_PsJ0zatISLbKaLrzILI/view
https://drive.google.com/file/d/1tXpFALiICkkTSJqSieuf1XkpS-jhcVnY/view

# Problemas:
https://www.beecrowd.com.br/judge/pt/problems/view/1462
*/

#include <bits/stdc++.h>
#define INF 100000000
#define MAX 100001
using namespace std;
typedef unsigned long long int ull;
ull a[MAX], l[MAX], r[MAX], j[MAX], s[MAX];

bool ErdosGallai(ull N)
{
    ull k;
    bool flag = true;

    // Ordenar em ordem não-crescente a sequência de graus
    sort(a + 1, a + N + 1, greater<ull>());

    // Cálculo do l[k]
    a[0] = 0; // Aproveitar que a posição 0 não está sendo utilizada
    for(k = 1; k <= N; k++)
        l[k] = l[k - 1] + a[k];
    
    // Cálculo do r[k]
    r[N] = 0;
    for(k = N - 1; k >= 1; k--)
        r[k] = r[k + 1] + a[k + 1];

    // Cálculo do j[k]
    a[0] = INF;
    ull _j = N;
    for(k = 1; k <= N; k++)
    {
        while(a[_j] < k) 
            _j--;
        j[k] = _j;
    }

    // Cálculo do S[k]
    for(k = 1; k <= N; k++)
        if(j[k] <= k)
            s[k] = r[k];
        else
            s[k] = (j[k] - k)*k + r[j[k]];
    
    // Verificar se a soma dos graus é par (primeira condição do teorema)
    if(l[N] % 2 != 0)
        flag = false;

    // Verificando a segunda condição do teorema
    for(k = 1; k <= N; k++)
        if(l[k] > k*(k - 1) + s[k])
            flag = false;
    
    return flag;
}

int main()
{
    // 3 vértices com grau 1
    a[1] = 1;
    a[2] = 1; 
    a[3] = 1;
    cout << ErdosGallai(3) << endl;

    // 3 vértices com grau 2
    a[1] = 2;
    a[2] = 2; 
    a[3] = 2;
    cout << ErdosGallai(3) << endl;
    
    return 0;
}