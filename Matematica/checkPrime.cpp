/*
# Descrição:
A função "is_prime(int n)" tem como objetivo verificar se um dado número inteiro positivo
(diferente de zero) é primo ou não. Um número primo é aquele que é dividido apenas por 
um e por ele mesmo. 

# Parâmetros: 
int n -> Número a ser realizado o teste de primalidade.

# Retorno:
A função retorna um valor booleano informando se o número é primo ou não.

# Complexidade:
O(sqrt(N))

# Referências:
https://www.rookieslab.com/posts/fastest-way-to-check-if-a-number-is-prime-or-not

# Problemas:
https://www.spoj.com/problems/GONE/
*/

#include <bits/stdc++.h>
using namespace std;

bool is_prime(int n)
{
    if (n == 1)
        return false;

    int i = 2;
    while (i*i <= n) 
    {
        if (n % i == 0)
            return false;
        i += 1;
    }

    return true;
}

int main()
{
    cout << is_prime(11) << endl;
    cout << is_prime(1) << endl;
    cout << is_prime(6) << endl;
    return 0;
}