/*
# Descrição:
O objetivo da função "distance()" é calcular a distância de dois pontos
bidimensionais dado suas coordenadas X e Y.

# Parâmetros: 
int x1 -> Coordenada X do primeiro ponto.
int y1 -> Coordenada Y do primeiro ponto.
int x2 -> Coordenada X do segundo ponto.
int y2 -> Coordenada Y do segundo ponto.

# Retorno:
A função retorna a distância (double) entre dois pontos bidimensionais.

# Complexidade:
O(logn), devido o uso da função sqrt().

# Referências:
https://www.geeksforgeeks.org/program-calculate-distance-two-points/

# Problemas:
BEE 1539
*/

#include <bits/stdc++.h>
using namespace std;

double distance(int x1, int y1, int x2, int y2)
{
    return sqrt(pow(x2 - x1, 2) + pow(y2 - y1, 2) * 1.0);
}

int main()
{
    cout << distance(3, 4, 4, 3) << endl;
    return 0;
}