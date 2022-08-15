/*
# Descrição:

# Parâmetros: 

# Retorno:

# Complexidade:
O(10*dig*soma*flag)

# Referências:
https://www.geeksforgeeks.org/digit-dp-introduction/

# Problemas:
https://www.spoj.com/problems/PR003004/
https://www.beecrowd.com.br/judge/pt/problems/view/1492
https://codeforces.com/problemset/problem/1036/C
*/

#include <bits/stdc++.h>
#define MAX 16
typedef long long ll; 
using namespace std;

ll dp[MAX][9*MAX][2];

ll solve(int dig, int soma, bool flag, vector<int> digitos)
{
    if(dig == -1)
        return soma;
    
    if(dp[dig][soma][flag] != -1 && !flag)
        return dp[dig][soma][flag];

    ll resp = 0, limite = flag ? digitos[dig] : 9;
    for(int i = 0; i <= limite; i++)
        resp += solve(dig - 1, soma + i, flag && (i == limite), digitos);
    return dp[dig][soma][flag] = resp;
}

vector<int> num2vector(ll num)
{
    vector<int> d;
    while(num > 0)
    {
        d.push_back(num % 10);
        num /= 10;
    }
    return d;
}

int main()
{
    ll n, a, b;
    vector<int> vecA, vecB;
    memset(dp, -1, sizeof(dp));
    
    cin >> n;
    while(n--)
    {
        cin >> a >> b;
        vecA = num2vector(a - 1);
        vecB = num2vector(b);
        cout << solve(vecB.size() - 1, 0, 1, vecB) - solve(vecA.size() - 1, 0, 1, vecA) << endl;
    }

    return 0;
}