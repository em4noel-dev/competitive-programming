/*
# Descrição:
A função "power" calcula a potência x^y (inteiros) sem problemas
de precisão. Isso é uma maneira alternativa para evitar problemas 
com a função pow() do C++. 

# Parâmetros: 
ll x -> Base.
ll y -> Expoente (maior ou igual a zero).

# Retorno:
A função retorna o resultado de x^y (ambos long long int).

# Complexidade:
O(log(y)), onde y é o expoente.

# Referências:
https://www.geeksforgeeks.org/write-a-c-program-to-calculate-powxn/

# Problemas:
https://neps.academy/br/competition/1394/exercise/1312
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll power(ll x, ll y)
{
    ll temp;
    if( y == 0)
        return 1;
    temp = power(x, y / 2);
    if (y % 2 == 0)
        return temp * temp;
    else
        return x * temp * temp;
}

int main()
{
    ll resp = power(10, 18);
    cout << resp << endl;
    return 0;
}