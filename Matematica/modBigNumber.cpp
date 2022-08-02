/*
# Descrição:
O objetivo desse algoritmo é encontrar o resto de divisão de um número grande
(representado por uma string) por um número inteiro.

# Parâmetros: 
string num -> Dividendo.
int a -> Divisor.

# Retorno:
A função retorna o resto da divão de "num" por "a"

# Complexidade:
O(|num|), onde |num| é o total de digitos do dividendo.

# Referências:
https://www.geeksforgeeks.org/how-to-compute-mod-of-a-big-number/

# Problemas:
Problema G - Simulado UFU 4
*/

#include <bits/stdc++.h>
using namespace std;
 
int mod(string num, int a)
{
    int res = 0;
    for (int i = 0; i < num.length(); i++)
        res = (res * 10 + (int)num[i] - '0') % a;
    return res;
}
 
int main()
{
    string num = "12316767678678";
    cout << mod(num, 10);
    return 0;
}