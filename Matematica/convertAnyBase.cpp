/*
# Descrição:
Dados dois inteiros positivos A e B e uma string S de tamanho N, denotando um 
número na base A, o objetivo da função "convertBase()" é converter a string S 
da base A para a base B. A ideia do algoritmo é converter para a string S para
a representação decimal e posteriormente converte-lo para a nova base B.

# Funções auxiliares:
int toDeci(string str, int base) -> Converte um número de uma determinada base para decimal.
string fromDeci(int base, int inputNum) -> Converte um número na base decimal para outra base.
int val(char c) -> Função que retorna o ASCII de um determinado caracter.
char reVal(int num) -> Função para retornar o char equivalente ao int "num".

# Parâmetros:  
string s -> Número na base "a" a ser convertido.
ll a -> Base original do número
ll b -> Nova base.

# Retorno
A função "convertBase(string s, ll a, ll b)" retorna a conversão do número
de base "a" representado pela string "s" para a base "b".

# Complexidade:
O(N), onde N é o tamanho da string "s".

# Referência:
https://www.geeksforgeeks.org/convert-a-number-from-base-a-to-base-b/

# Problemas:
BEE 1538
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;
 
ll val(char c)
{
    if (c >= '0' && c <= '9')
        return (ll)c - '0';
    else
        return (ll)c - 'A' + 10;
}

char reVal(ll num)
{
    if (num >= 0 && num <= 9)
        return (char)(num + '0');
    else
        return (char)(num - 10 + 'A');
}
 
ll toDeci(string str, ll base)
{
    ll len = str.size();
    ll power = 1;
    ll num = 0;
 
    for (int i = len - 1; i >= 0; i--) 
    {
        if (val(str[i]) >= base) 
        {
            printf("Invalid Number");
            return -1;
        }
        num += val(str[i]) * power;
        power = power * base;
    }
    return num;
}

string fromDeci(ll base, ll inputNum)
{
    string res = "";
    while (inputNum > 0) 
    {
        res += reVal(inputNum % base);
        inputNum /= base;
    }
    reverse(res.begin(), res.end());
    return res;
}

string convertBase(string s, ll a, ll b)
{
    ll num = toDeci(s, a);
    string ans = fromDeci(b, num);
    return ans;
}
 
int main()
{
    cout << convertBase("FF", 16, 2) << endl;
    return 0;
}