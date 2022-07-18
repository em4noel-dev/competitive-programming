/*
# Descrição:
Dada uma string de entrada e uma substring, Encontre a frequência de ocorrências de uma substring em uma determinada string.
# Parâmetros: 
vector<pair<ld, ld>> pontos -> Vector contendo todos os n vértices. first: coordenada x ; second: coordenada y

# Complexidade:
O(n)

# Referência:
https://www.geeksforgeeks.org/frequency-substring-string/

# Problemas:
https://www.eolymp.com/en/problems/60

Referência:
*/

#include <bits/stdc++.h>
typedef long long int lli;
using namespace std;

void computeLPSArray(string pat, int M, int lps[])
{
    int len = 0;
    int i = 1;
    lps[0] = 0;

    while (i < M) 
        if (pat[i] == pat[len]) 
        {
            len++;
            lps[i] = len;
            i++;
        }
        else
            if (len != 0) 
                len = lps[len - 1];
            else
            {
                lps[i] = len;
                i++;
            }
}
  
int KMPSearch(string pat, string txt)
{
    int M = pat.length();
    int N = txt.length();
    int lps[M];
    int j = 0; 
    computeLPSArray(pat, M, lps);
    int i = 0;
    int res = 0;
    int next_i = 0;
  
    while (i < N)
    {
        if (pat[j] == txt[i])
        {
            j++;
            i++;
        }

        if (j == M)
        {
            j = lps[j - 1];
            res++;
        }
        else if (i < N && pat[j] != txt[i])
        {
            if (j != 0)
                j = lps[j - 1];
            else
                i = i + 1;
        }
    }
    return res;
}

int main()
{
    cout << KMPSearch("luiz", "luizabcluizabcluizabc") << endl;
    return 0;
}