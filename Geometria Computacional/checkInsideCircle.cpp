/*
# Descrição:
O objetivo da função "isInside()" é verificar se um dado ponto está ou não
contido em uma circunferência. A ideia é utilizar o cálculo da distancia
entre dois pontos (sem utilizar sqrt).

# Parâmetros: 
int circle_x -> Coordenada X do centro da circunferência.
int circle_y -> Coordenada Y do centro da circunferência.
int rad -> Raio da circunferência.
int x -> Coordenada X do ponto de teste.
int y -> Coordenada Y do ponto de teste.

# Retorno:
A função retorna "true" caso o ponto esteja contido dentro da circunferência e false caso contrário.

# Complexidade:
O(1)

# Referências:
https://www.geeksforgeeks.org/find-if-a-point-lies-inside-or-on-circle/

# Problemas:
BEE 1539
*/

#include <bits/stdc++.h>
using namespace std;

bool isInside(int circle_x, int circle_y, int rad, int x, int y)
{
    return ((x - circle_x) * (x - circle_x) + (y - circle_y) * (y - circle_y) <= rad * rad);
}

int main()
{
    cout << isInside(0, 1, 2, 1, 1) << endl;
    return 0;
}