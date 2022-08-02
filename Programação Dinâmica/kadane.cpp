/*
# Descrição:
O objetivo desse algoritmo é encontrar a maior soma de um subarray contíguo (números consecutivos) 
a partir de um array principal fornecido. A função utiliza a ideia do
Kadane’s Algorithm juntamente com programação dinâmica.

# Parâmetros: 
vector<int> a -> Array que se deseja procurar o subarray contíguo de soma máxima.

# Retorno:
A função retorna a maior soma de um subarray contíguo.

# Complexidade:
O(n)

# Referências:
https://www.geeksforgeeks.org/largest-sum-contiguous-subarray/

# Problemas:
https://codeforces.com/group/YgJmumGtHD/contest/103794/problem/I
*/

#include <bits/stdc++.h>
using namespace std;
  
int maxSubArraySum(vector<int> a)
{
   int max_so_far = a[0];
   int curr_max = a[0];
  
   for (int i = 1; i < a.size(); i++)
   {
        curr_max = max(a[i], curr_max+a[i]);
        max_so_far = max(max_so_far, curr_max);
   }
   return max_so_far;
}
  
int main()
{
   vector<int> a =  {-2, -3, 4, -1, -2, 1, 5, -3};
   cout << "Maximum contiguous sum is " <<  maxSubArraySum(a);;
   return 0;
}