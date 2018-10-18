// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Baile de Reconciliação
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1999

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

#define MAX 100000
int dan[MAX];

int main()
{
	rep(i, 1, sqrt(MAX))
	rep(j, i, MAX){
		ll aux=i*j;
		if(aux>=MAX-1) break;
		dan[aux]++;
		rep(k, j, MAX/j){
		if(i*k>=MAX-1 || j*k>=MAX-1) break;
		aux=i*j+i*k+j*k;
		if(aux>=MAX-1 ) break;
		//cout << aux << endl;
		dan[aux]++;
		}	
	}
	
	int N;
	while(scanf("%d", &N)){
		if(N==-1) break;
		printf("%d\n", dan[N]);
	}	
	
	
return 0;
}


