// Author: Gustavo Policarpo
// Name: Factorial
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2129

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 
int mem[1000001];
int main()
{
	ll num=1, aux, z=1;
	for(ll i=1; i<=1000000; i++){
		aux=i;
		
		while(aux%10==0)
			aux/=10;
		num*=aux;
		
		while(num%10==0)
			num/=10;
			
		num%=10000000;
		mem[i]=num%10;
	}
	
	while(cin >> aux)
		cout << "Instancia " << z++ << '\n' << mem[aux] << '\n' << '\n';
 
return 0;
}
 
 
