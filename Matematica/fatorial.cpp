/*
# Descrição:
A função "factorial()" calcula o fatorial de um número N.
N! = N * (N-1) * (N-2) * (N-3) * ... * 1.

# Parâmetros: 
ll n -> Número que se deseja calcular o fatorial (Maior valor possível: 20 - long long int).

# Retorno:
A função retorna o fatorial de n (n!).

# Complexidade:
O(n)

# Referências:
https://www.geeksforgeeks.org/program-for-factorial-of-a-number/

# Problemas:
BEE 1153
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll factorial(ll n)
{
    return (n == 1 || n == 0) ? 1 : n * factorial(n - 1);
}

int main()
{
    ll resp = factorial(20);
    cout << resp << endl;
    return 0;
}