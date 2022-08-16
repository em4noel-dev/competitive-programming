/*
# Descrição:
O objetivo dessa estratégia é contar a quantidade de inteiros "x" entre dois
inteiros "a" e "b" tal que x satisfaz uma propriedade especifica relacionada
com seus dígitos. Tendo isso em mente, a função "solve()" constroi recursivamente
todos os números menores ou iguais que uma entrada N e conta a quantidade 
de números que respeitam a determinada propriedade, utilizando uma matriz para 
armazenar os cálculos realizados, evitando possíveis retrabalhos. Para obter a 
quantidade requisita entre um intervalo "a" e "b", basta calcular solve(b) - solve(a-1). 
O exemplo presente nesse arquivo busca encontrar a soma total de todos dígitos dos 
números contidos em um intervalo entre "a" e "b".

# Observações:
-> O número N deve ser representado em um array de digitos, onde a primeira posição
é o dígito menos significativo (utilize a função auxiliar num2vector()).
ll dp[MAX][9*MAX][2] -> O tamanho da segunda dimensão da matriz dp é variável com o problema.
-> Para calcular solve(b) deve se chamar a função no main como: solve(vecB.size() - 1, 0, 1, vecB).

# Constantes:
#define MAX 16 -> Quantidade máxima de digitos possíveis para um número de entrada.

# Parâmetros:
int dig -> índice do digito atual da construção dos números.
int soma -> Parâmetro vinculado com a propriedade relacionada com os dígitos (Nesse caso é a soma total de dígitos)
bool flag -> Parâmetro booleano que informa se o digito atual deve ser limitado ou não.
vector<int> digitos -> Array contendo os dígitos do número "n" fornecido (digitos[0] -> dígito menos significativo)

# Função auxiliar:
vector<int> num2vector(ll num) -> converte um número inteiro em um array de dígitos.

# Retorno:
O retorno da função "solve()" é variável com o problema. Nesse exemplo ela
retorna o somatório de digitos dos prefixos que podem ser formados a partir 
do indice "dig" tais que o sufixo formado até então possui soma total "soma".
Se flag == true, então o sufixo formado não ultrapassa o sufixo do número
de entrada representado pelo array "digitos".

# Complexidade:
O(10*dig*soma*flag), onde dig*soma*flag é o tamanho da matriz dp.

# Referências:
https://www.geeksforgeeks.org/digit-dp-introduction/
https://www.youtube.com/watch?v=Ls57WZHu1BE&ab_channel=Programa%C3%A7%C3%A3oCompetitivaUNESP

# Problemas:
https://www.spoj.com/problems/PR003004/
https://www.beecrowd.com.br/judge/pt/problems/view/1492
https://codeforces.com/problemset/problem/1036/C
*/

#include <bits/stdc++.h>
#define MAX 16
typedef long long ll; 
using namespace std;

ll dp[MAX][9*MAX][2];

ll solve(int dig, int soma, bool flag, vector<int> digitos)
{
    // caso base
    if(dig == -1)
        return soma; // Teste da propriedade do número
    
    // Utilização da PD
    if(dp[dig][soma][flag] != -1 && !flag)
        return dp[dig][soma][flag];

    // Construção de todos os números possíveis menores ou iguais a N.
    ll resp = 0, limite = flag ? digitos[dig] : 9;
    for(int i = 0; i <= limite; i++)
        resp += solve(dig - 1, soma + i, flag && (i == limite), digitos);
    return dp[dig][soma][flag] = resp;
}

// Função auxiliar
vector<int> num2vector(ll num)
{
    vector<int> d;
    while(num > 0)
    {
        d.push_back(num % 10);
        num /= 10;
    }
    return d;
}

// Exemplo de main
int main()
{
    ll n, a, b;
    vector<int> vecA, vecB;
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        vecA = num2vector(a - 1);
        vecB = num2vector(b);
        cout << solve(vecB.size() - 1, 0, 1, vecB) - solve(vecA.size() - 1, 0, 1, vecA) << endl;
    }

    return 0;
}