// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Humm.. Andar ou Correr.. ...
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1595

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
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int main()
{	
	int T; cin >> T;
	while(T--){
		int S, C, R;
		scanf("%d %d %d", &S, &C, &R);
		double aux, tempo=0.0;
		vector <double> s;
		rep(i, 0, S){
			scanf("%lf", &aux);
			s.pb(aux);
		}
		sort(s.begin(), s.end());
		rep(i, 0, S){
			if(C>0)
				tempo+=1.0/(s[i]+R), C--;
			else
				tempo+=1.0/s[i];	
		}
		printf("%.2lf\n", tempo);
	}
		
return 0;
}
