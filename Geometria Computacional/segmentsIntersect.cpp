/*
# Descrição:
O objetivo desse algoritmo é dado duas retas (p1, q1) e (p2, q2) encontrar
se elas se interceptam uma com a outra. A função principal é "doIntersect()"

# Parâmetros:  
Point p1 -> Ponto inicial da reta 1 
Point q1 -> Ponto final da reta 1
Point p2 -> Ponto inicial da reta 2 
Point q2 -> Ponto final da reta 2

# Retorno
A função retorna "true" caso as retas se interceptam e "false" caso contrário.

# Complexidade:
O(1)

# Referência:
https://www.geeksforgeeks.org/check-if-two-given-line-segments-intersect/

# Problemas:
Problema G - Prova substitutiva de ECOE44 (UNIFEI - 2022.1)
*/

#include <bits/stdc++.h>
using namespace std;

struct Point
{
    double x;
    double y;
};

bool onSegment(Point p, Point q, Point r)
{
    if (q.x <= max(p.x, r.x) && q.x >= min(p.x, r.x) && q.y <= max(p.y, r.y) && q.y >= min(p.y, r.y))
       return true;
  
    return false;
}
  
int orientation(Point p, Point q, Point r)
{
    double val = (q.y - p.y) * (r.x - q.x) - (q.x - p.x) * (r.y - q.y);
  
    if (val == 0) return 0;  
    return (val > 0)? 1: 2; 
}

bool doIntersect(Point p1, Point q1, Point p2, Point q2)
{
    int o1 = orientation(p1, q1, p2);
    int o2 = orientation(p1, q1, q2);
    int o3 = orientation(p2, q2, p1);
    int o4 = orientation(p2, q2, q1);
  
    if (o1 != o2 && o3 != o4)
        return true;
  
    if (o1 == 0 && onSegment(p1, p2, q1)) return true;
    if (o2 == 0 && onSegment(p1, q2, q1)) return true;
    if (o3 == 0 && onSegment(p2, p1, q2)) return true;
    if (o4 == 0 && onSegment(p2, q1, q2)) return true;
  
    return false; 
}

int main()
{
    Point p1 = {1.0, 1.0};
    Point q1 = {10.0, 1.0};

    Point p2 = {1.0, 2.0};
    Point q2 = {10.0, 2.0};
    
    if(doIntersect(p1, q1, p2, q2))
        cout << "Yes\n";
    else
        cout << "No\n";

    return 0;
}