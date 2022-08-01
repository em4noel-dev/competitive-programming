/*
# Descrição:
O objetivo desse algoritmo é calcular a quantidade de digitos de n!.
A função utiliza a Kamenetsky’s formula. Ela pode falhar para alguns
casos de números muito grandes, como por exemplo para n = 6561101970383.

# Parâmetros: 
int n -> Número que se deseja saber a quantidade de digitos ao aplicar a operação de fatorial.

# Retorno:
A função retorna a quantidade de digitos de n!.

# Complexidade:
O(1)

# Referências:
https://www.geeksforgeeks.org/count-digits-factorial-set-2/
https://mathoverflow.net/questions/19170/how-good-is-kamenetskys-formula-for-the-number-of-digits-in-n-factorial

# Problemas:
Nenhum por enquanto.
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll findDigits(int n)
{
    if (n < 0)
        return 0;
    if (n <= 1)
        return 1;
    double x = ((n * log10(n / M_E) + log10(2 * M_PI * n) / 2.0));
    return floor(x) + 1;
}
 
int main()
{
    cout << findDigits(254) << endl;
    cout << findDigits(255) << endl;
    return 0;
}