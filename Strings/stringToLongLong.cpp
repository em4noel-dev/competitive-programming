/*
# Descrição:
A função "convertStringToLongLong()" tem como objetivo converter uma
string representando um número na base 10 para o tipo long long int
do C++.

# Parâmetros: 
string number -> String que representa o número a ser convertido.

# Retorno:
A função retorna a conversão da string em long long int.

# Complexidade:
Aproximadamente O(N), onde N é o tamanho da string.

# Referências:
https://cplusplus.com/reference/cstdlib/strtoll/
https://stackoverflow.com/questions/21887274/convert-string-to-long-long-int

# Problemas:
https://neps.academy/br/competition/1394/exercise/1312
*/

#include <bits/stdc++.h>
typedef long long ll;
using namespace std;

ll convertStringToLongLong(string number)
{
    char char_array[number.size() + 1];
    strcpy(char_array, number.c_str());
    char* endptr = NULL;
    return strtoll(char_array, &endptr, 10);
}

int main()
{
    ll num = convertStringToLongLong("1000000000000000000");
    cout << num << endl;
    return 0;
}