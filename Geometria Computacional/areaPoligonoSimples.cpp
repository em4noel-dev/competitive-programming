/*
# Descrição:
A função polygonArea retorna a área de um polígono simples dada as coordenadas
ordenadas dos seus n vértices. Aqui ordenado significa que as coordenadas são 
dadas no sentido horário ou anti-horário do primeiro ao último vértice. O algoritmo
utiliza a "Shoelace formula".

# Parâmetros: 
vector<pair<ld, ld>> pontos -> Vector contendo todos os n vértices. first: coordenada x ; second: coordenada y

# Retorno:
A área do polígono simples formado pelos pontos fornecidos.

# Complexidade:
O(n)

# Referência:
https://www.geeksforgeeks.org/area-of-a-polygon-with-given-n-ordered-vertices/

# Problemas:
https://www.eolymp.com/en/problems/60
*/

#include <bits/stdc++.h>
typedef long double ld;
using namespace std;

ld polygonArea(vector<pair<ld, ld>> pontos)
{
    ld area = 0.0;
    int n = pontos.size(), j = n - 1;
    for (int i = 0; i < n; i++)
    {
        area += (pontos[j].first + pontos[i].first) * (pontos[j].second - pontos[i].second);
        j = i;
    }
    return abs(area / 2.0);
}

int main()
{
    vector<pair<ld, ld>> pontos{make_pair(0, 1.5), make_pair(2, 3), make_pair(4, 7)};
    cout << polygonArea(pontos) << endl;
    return 0;
}