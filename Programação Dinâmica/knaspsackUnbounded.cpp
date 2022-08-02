/*
# Descrição:
O objetivo desse algortimo é retornar a combinação mais valiosa de produtos  
(somatório dos valores dos produtos)  que cabem em uma determinada mochila,  
considerando que os produtos são ilimitados (com repetição).

# Parâmetros: 
int *pesos → Vetor contendo os pesos de cada produto i, ou seja, o quanto cada produto ocupa de espaço na mochila.
int *valores → Vetor contendo os valores de cada produto i.
int tamanhoMochila → O tamanho máximo que a mochila comporta (capacidade).
int totalProdutos  → O total de produtos (tamanho do vetor *pesos)

# Retorno:
Essa função retorna um número inteiro representando o somatório dos valores 
dos produtos da combinação mais valiosa que cabe na mochila, considerando 
que os produtos são ilimitados (com repetição).

# Complexidade:
O(W*N), onde W é o peso total (capacidade) e N é a quantidade de itens.

# Referências:
https://www.geeksforgeeks.org/unbounded-knapsack-repetition-items-allowed/
https://www.youtube.com/watch?v=J79jlESWb5Y&ab_channel=Jo%C3%A3oPauloLeite

# Problemas:
https://www.beecrowd.com.br/judge/pt/problems/view/1487
*/

#include <bits/stdc++.h>
using namespace std;
  
int mochila_repeticao(int *pesos, int *valores, int tamanhoMochila, int totalProdutos)
{
    int memoria[tamanhoMochila + 1] = {0};

    for(int w = 1; w < tamanhoMochila + 1; w++)
        for(int j = 0; j < totalProdutos; j++)
            if(pesos[j] <= w)
                if(memoria[w - pesos[j]] + valores[j] > memoria[w])
                    memoria[w] = memoria[w - pesos[j]] + valores[j];

    return memoria[tamanhoMochila];
}
  
int main()
{
    int pesos[] = {12, 2, 1, 4, 1};
    int valores[] = {4, 2, 1, 10, 2};
    cout << mochila_repeticao(pesos, valores, 15, 5) << endl;
    return 0;
}