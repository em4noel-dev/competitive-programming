#include<bits/stdc++.h>
using namespace std;

/*
# Descrição:
O objetivo desse algoritmo é gerar todas as permutações possíveis de um array sem a necessidade de 
ordenar seus elementos, diferentemente da função next_permutation() do C++. A função principal é
a "permute()".

# Parâmetros:  
vector<int> &nums -> Array base para gerar todas as permutações.

# Retorno
A função retona um vector<vector<int>> contendo todas as permutações possível do array base;

# Complexidade:
o(N!*N)

# Referência:
https://takeuforward.org/data-structure/print-all-permutations-of-a-string-array/

# Problemas:
Problema A - Prova substitutiva de ECOE44 (UNIFEI - 2022.1)
*/

void recurPermute(vector <int> &ds, vector <int> &nums, vector<vector <int>> &ans, int freq[]) 
{
    if (ds.size() == nums.size()) 
    {
        ans.push_back(ds);
        return;
    }

    for (int i = 0; i < nums.size(); i++) 
        if (!freq[i]) 
        {
            ds.push_back(nums[i]);
            freq[i] = 1;
            recurPermute(ds, nums, ans, freq);
            freq[i] = 0;
            ds.pop_back();
        }
}

vector<vector<int>> permute(vector<int> &nums)
{
    vector <vector <int>> ans;
    vector <int> ds;
    int freq[nums.size()];
    for (int i = 0; i < nums.size(); i++) 
        freq[i] = 0;
    recurPermute(ds, nums, ans, freq);
    return ans;
}

int main() 
{
    vector<int> v{4, 5, 6, 7};
    vector<vector<int>> permutacoes = permute(v);

    cout << "Todas as permutacoes do array [4, 5, 6, 7]: " << endl;
    for (int i = 0; i < permutacoes.size(); i++) 
    {
        for (int j = 0; j < permutacoes[i].size(); j++)
            cout << permutacoes[i][j] << " ";
        cout << endl;
    }
}