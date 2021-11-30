// Author: Gustavo Policarpo
// Name: Which Triangle
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2313

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	ll n[3];
	rep(i, 0, 3) cin >> n[i];
	sort(n, n+3);
	
	if(n[2]>=n[0]+n[1]){
		puts("Invalido");
		return 0;
	}
	
	if(n[0]==n[2]) puts("Valido-Equilatero");
	else if(n[0]==n[1] || n[1]==n[2]) puts("Valido-Isoceles");	
	else puts("Valido-Escaleno");
	
	if(n[0]*n[0]+n[1]*n[1]==n[2]*n[2]) puts("Retangulo: S");
	else puts("Retangulo: N");


return 0;
}



