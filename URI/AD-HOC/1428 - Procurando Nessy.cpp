// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Procurando Nessy
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1428

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
#define ALL(c) c.begin(), c.end() 
#define SORT(c) sort(ALL(c)) 
#define UNIQUE(c) { SORT(c); (c).resize( unique(ALL(c))-c.begin() ); }

#define INF 0x3F3F3F3
#define MAXV 100001

const double EPS = 1e-9;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < double, int > ii;
typedef pair < double, ii > iii;


int main()
{
	int T; cin >> T;
	while(T--){
		double n, m;
		scanf("%lf %lf", &n, &m);
		int out=round((n-1)/3.0)*round((m-1)/3.0);
		cout << out << endl;
	}
		
return 0;
}
