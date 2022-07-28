/*
# Descrição:
O objetivo desse algoritmo é encontrar o menor polígono convexo (Convex Hull) que
engloba todos os pontos de um conjuto de pontos fornecido. A função principal é
o "convexHull()".

# Parâmetros:
vector<Point> a -> Vector contendo o conjunto de pontos a ser analisado.
bool include_collinear -> "true" para que o poligono de retorno contenha pontos 
colineares e "false" caso contrário (somente vértices)

# Retorno
A função retorna um vector contendo todos os pontos do menor poligono convexo
que engloba todos os pontos do conjunto fornecido.

# Complexidade:
O(nlogn), onde n é o total de pontos.

# Referências:
https://cp-algorithms.com/geometry/convex-hull.html#grahams-scan-algorithm
https://www.geeksforgeeks.org/convex-hull-set-2-graham-scan/

# Problemas:
https://www.beecrowd.com.br/judge/pt/problems/view/1464
*/

#include <bits/stdc++.h>
#define endl '\n'
#define _ ios_base::sync_with_stdio(0); cin.tie(0);
using namespace std;

struct Point 
{
    double x, y;
};

int orientation(Point a, Point b, Point c) 
{
    double v = a.x * (b.y-c.y) + b.x*(c.y-a.y) + c.x*(a.y-b.y);
    if (v < 0) return -1;
    if (v > 0) return +1;
    return 0;
}

bool cw(Point a, Point b, Point c, bool include_collinear) 
{
    int o = orientation(a, b, c);
    return o < 0 || (include_collinear && o == 0);
}

bool collinear(Point a, Point b, Point c) 
{
    return orientation(a, b, c) == 0;
}

vector<Point> convexHull(vector<Point> a, bool include_collinear = false)
{
    Point p0 = *min_element(a.begin(), a.end(), [](Point a, Point b) {
        return make_pair(a.y, a.x) < make_pair(b.y, b.x);
    });

    sort(a.begin(), a.end(), [&p0](const Point& a, const Point& b) {
        int o = orientation(p0, a, b);
        if (o == 0)
            return (p0.x-a.x)*(p0.x-a.x) + (p0.y-a.y)*(p0.y-a.y)
                < (p0.x-b.x)*(p0.x-b.x) + (p0.y-b.y)*(p0.y-b.y);
        return o < 0;
    });

    if (include_collinear) 
    {
        int i = (int)a.size()-1;
        while (i >= 0 && collinear(p0, a[i], a.back())) i--;
        reverse(a.begin()+i+1, a.end());
    }

    vector<Point> st;
    for (int i = 0; i < (int)a.size(); i++) 
    {
        while (st.size() > 1 && !cw(st[st.size()-2], st.back(), a[i], include_collinear))
            st.pop_back();
        st.push_back(a[i]);
    }

    return st;
}

int main()
{ _
    vector<Point> pontos;
    Point p1, p2, p3, p4, p5, p6, p7, p8;
    p1.x = 0; p1.y = 3; p2.x = 1; p2.y = 1;
    p3.x = 2; p3.y = 2; p4.x = 4; p4.y = 4;
    p5.x = 0; p5.y = 0; p6.x = 1; p6.y = 2;
    p7.x = 3; p7.y = 1; p8.x = 3; p8.y = 3;

    pontos.push_back(p1); pontos.push_back(p2);
    pontos.push_back(p3); pontos.push_back(p4);
    pontos.push_back(p5); pontos.push_back(p6);
    pontos.push_back(p7); pontos.push_back(p8);

    vector<Point> poligono = convexHull(pontos, true);
    for(Point p : poligono)
        cout << "(" << p.x << ";" << p.y << ")" << endl;
    cout << endl;
    
    return 0;
}