/*
# Descrição:
O objetivo desse algoritmo é encontrar o raio da circunferência inscrita em
um triângulo de lados a, b e c. Uma circunferência inscrita em um triângulo 
é quando está no seu interior e possui apenas um ponto em comum com cada um
de seus lados. A formula utilizada para encontrar o raio é:
raio = área do triangulo / semiperímetro do triângulo

# Parâmetros: 
double a -> Lado do triângulo. 
double b -> Lado do triângulo.
double c -> Lado do triângulo.

# Retorno:
A função retorna o raio da circunferência inscrita no triângulo de lados fornecidos.

# Complexidade:
O(log(n)), por causa da utilização do sqrt

# Referências:
https://www.geeksforgeeks.org/program-to-find-the-radius-of-the-incircle-of-the-triangle/

# Problemas:
PROBLEMA I - Simulado 8 - UFU
*/

#include <bits/stdc++.h>
using namespace std;

double findRadiusOfIncircle(double a, double b, double c)
{
    if (a < 0 || b < 0 || c < 0)
        return -1;
 
    double p = (a + b + c) / 2;
    double area = sqrt(p * (p - a) * (p - b) * (p - c));
    double radius = area / p;
    return radius;
}

int main()
{
    cout << findRadiusOfIncircle(2, 2, 3) << endl;
    return 0;
}