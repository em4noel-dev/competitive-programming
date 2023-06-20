/*
Algumas propriedades da aritmética Modular:

Adição Modular:
-> (a + b) mod m = ((a mod m) + (b mod m)) mod m

Subtração Modular:
-> (a - b) mod m = ((a mod m) - (b mod m)) mod m

Multiplicação Modular:
-> (a * b) mod m = ((a mod m) * (b mod m)) mod m
-> (a * b) mod m = ((a mod m) * b) mod m

Divisão Modular:
-> (a / b) mod m = (a * (inverse of b)) mod m

Exponenciação Modular:
-> A^B mod C = ( (A mod C)^B ) mod C

Identidade:
-> (a mod m) mod m = a mod m

Resto de divisão de um número utilizando seus dígitos: 
123 mod K = (((1 mod K)*10 + 2) mod K)*10 + 3) mod K

Referências + outras propriedades como Inversa Modular/Exponenciação Modular Rápida:
https://math.stackexchange.com/questions/5366/very-simple-question-but-what-is-the-proof-that-x-y-mod-m-x-mod-m-y-mod
https://www.hackersfriend.com/articles/modular-arithmetic-for-competitive-programming
https://pt.khanacademy.org/computing/computer-science/cryptography/modarithmetic/a/modular-multiplication
https://en.wikipedia.org/wiki/Modulo_operation
https://codeforces.com/submissions/AmateurCode/page/3 -> Problem F - Ira and Flamenco
https://codeforces.com/blog/entry/72527
*/

// Algumas funções prontas

ll modadd(ll a,ll b,ll m){ a %= m;b %= m; return (a + b) % m;}
ll modmul(ll a,ll b,ll m){ a %= m;b %= m; return (a * b) % m;}
ll modsub(ll a,ll b,ll m){ a %= m;b %= m; return (a - b + m) % m;}
ll gcd(ll a, ll b){ if(b == 0) return a; return gcd(b, a % b);}

// EXPONENCIAÇÃO com MOD para encontrar o inverso multiplicativo de um número b. inverse of b = b^(P - 2); onde P normalmente é o primo 1000000007
ll expo(ll a, ll n, ll md){ ll res=1; while(n){ if(n&1) {res = modmul(res,a,md);--n;} else {a = modmul(a,a,md);n >>= 1;}} return res;}  
ll expo(ll a, ll n){ ll res=1; while(n){ if(n&1) {res *= a;--n;} else {a *= a;n >>= 1;}} return res;}
