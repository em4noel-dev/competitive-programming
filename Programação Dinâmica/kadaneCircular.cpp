/*
# Descrição:
O objetivo desse algoritmo é encontrar a maior soma de um subarray circular
contíguo (números consecutivos) a partir de um array principal fornecido. 
A função utiliza a ideia do Kadane’s Algorithm juntamente com programação dinâmica.

# Parâmetros: 
vector<ll> a -> Array que se deseja procurar o subarray circular contíguo de soma máxima.

# Retorno:
A função retorna a maior soma de um subarray circular contíguo.

# Complexidade:
O(n)

# Referências:
https://www.geeksforgeeks.org/maximum-contiguous-circular-sum/

# Problemas:
https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/I
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
  
ll maxCircularSum(vector<ll> a)
{
    int n = a.size();
    if (n == 1)
        return a[0];
 
    ll sum = 0;
    for (int i = 0; i < n; i++) 
        sum += a[i];
    
    ll curr_max = a[0], max_so_far = a[0], curr_min = a[0], min_so_far = a[0];
 
    for (int i = 1; i < n; i++) 
    {
        curr_max = max(curr_max + a[i], a[i]);
        max_so_far = max(max_so_far, curr_max);
        curr_min = min(curr_min + a[i], a[i]);
        min_so_far = min(min_so_far, curr_min);
    }
 
    if (min_so_far == sum)
        return max_so_far;
 
    return max(max_so_far, sum - min_so_far);
}
  
int main()
{
    vector<ll> a =  { 11, 10, -20, 5, -3, -5, 8, -13, 10};
    cout << "Maximum circular sum is " << maxCircularSum(a) << endl;
    return 0;
}