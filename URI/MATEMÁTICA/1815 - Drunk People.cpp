// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Drunk People?
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1815

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

const int INF = 0x3f3f3f3f;

double mat[105][105], p[105];

double markov(int n, int k)
{
	double v[n], aux;

	for (int i = 0; i < n; i++)
	{
		aux = 0.0;

		for (int j = 0; j < n; j++)
			aux += p[j] * mat[i][j];

		v[i] = aux;
	}

	for (int i = 0; i < n; i++) p[i] = v[i];

	return p[k];
}



int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int n, a, b, t, z=1;
	while(scanf("%d", &n) and n){ scanf("%d %d %d", &a, &b, &t);
		
		rep(i, 0, n) rep(j, 0, n) scanf("%lf", &mat[j][i]);
		
		double ans=0.0; rep(i, 0, n) p[i]=0.0; p[a-1]=1.0;
		
		rep(i, 0, t){
			ans+=markov(n, b-1);
			p[b-1]=0.0;
		}
		
		printf("Instancia %d\n%.6lf\n\n", z++, 1.0-ans);
		
	}
	
	return 0;
	
}
