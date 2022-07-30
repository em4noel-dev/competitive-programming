/*
# Descrição:
O objetivo desse algoritmo é calcular as duas raízes complexas de uma equação
de segundo grau no formato: ax^2 + bx + c = 0. Não funciona para a = 0.

# Parâmetros:
int a -> Coeficiente a da equação quadrática.
int b -> Coeficiente b da equação quadrática.
int c -> Coeficiente c da equação quadrática.

# Retorno
A função retorna um pair<complexNumber, complexNumber> contendo as duas soluções 
complexas da equação quadrática fornecida. A struct "complexNumber" representa
um número complexo com parte real e imaginária.

# Complexidade:
O(log(D)), onde D é o discriminante da equação quadrática.

# Referência:
https://www.geeksforgeeks.org/program-to-find-the-roots-of-quadratic-equation/

# Problemas:
Problema E - Simulado UFU - 30/07/2022 (Grid)
*/

#include <bits/stdc++.h>
using namespace std;

struct complexNumber{
    double real, imag;
};

pair<complexNumber, complexNumber> findRoots(int a, int b, int c)
{
    pair<complexNumber, complexNumber> resp;
    resp.first.imag = 0;
    resp.second.imag = 0;
    
    int d = b * b - 4 * a * c;
    double sqrt_val = sqrt(abs(d));

    if (d > 0) 
    {
        resp.first.real = (double) (-b + sqrt_val) / (2 * a);
        resp.second.real = (double) (-b - sqrt_val) / (2 * a);
    }
    else if (d == 0)
    {
        resp.first.real = -(double) b / (2 * a);
        resp.second.real = -(double) b / (2 * a);
    }
    else
    {
        resp.first.real = -(double) b / (2 * a);
        resp.first.imag = sqrt_val / (2 * a);

        resp.second.real = -(double) b / (2 * a);
        resp.second.imag =  -sqrt_val / (2 * a);
    }

    return resp;
}
 
int main()
{
    pair<complexNumber, complexNumber> resp;
    resp = findRoots(1, -7, 13);

    cout << "Primeira raiz: " << endl;
    cout << "real: " << resp.first.real << "; imag = " << resp.first.imag << endl;
    cout << "Segunda raiz: " << endl;
    cout << "real: " << resp.second.real << "; imag = " << resp.second.imag << endl;

    return 0;
}