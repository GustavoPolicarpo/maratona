// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fibonacci Rápido
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2164

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int main()
{
    double n; cin >> n;
    double a=(1+sqrt(5))/2;
    a=pow(a, n);
    double b=(1-sqrt(5))/2;
    b=pow(b, n);
    double out=(a-b)/sqrt(5);
    printf("%.1lf\n", out);

}

