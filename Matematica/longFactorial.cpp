/*
# Descrição:
O objetivo desse algoritmo é calcular fatorial de um grande número, no qual
variáveis do tipo long long não possuem capacidade para armazena-los. A 
funçao utilizada é "longFactorial()".

# Constantes
#define MAX 500 -> Número maximo de digitos da saída.
Exemplo: 254! possui 503 digitos.

# Parâmetros: 
int n -> Número que se deseja calcular o fatorial.

# Retorno:
A função não retorna nada, mas calcula o fatorial de n, armazena no array res[MAX] 
e realiza sua impressão.

# Complexidade:
O(nlogn!)

# Referências:
https://www.geeksforgeeks.org/factorial-large-number/

# Problemas:
Problema G - Simulado UFU 3 - Matemática
*/

#include <bits/stdc++.h>
using namespace std;
 
#define MAX 500

int multiply(int x, int res[], int res_size)
{
    int carry = 0; 
    for (int i = 0; i < res_size; i++)
    {
        int prod = res[i] * x + carry;
        res[i] = prod % 10; 
        carry  = prod/10;   
    }
 
    while (carry)
    {
        res[res_size] = carry%10;
        carry = carry/10;
        res_size++;
    }
    return res_size;
}

void longFactorial(int n)
{
    int res[MAX];

    res[0] = 1;
    int res_size = 1;
 
    for (int x=2; x<=n; x++)
        res_size = multiply(x, res, res_size);
 
    // Impressão
    for (int i = res_size-1; i >= 0; i--)
        cout << res[i];
}

int main()
{
    longFactorial(100);
    return 0;
}