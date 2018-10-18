// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Elevador Lotado
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1611

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
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, C, M, m[50005];

int main()
{
	int T; cin >> T;
	while(T--){
		scanf("%d %d %d", &N, &C, &M);
		rep(i, 0, M) scanf("%d", &m[i]);
		sort(m, m+M);
		int c=C, j=M-1; ll out=0;
		while(j>=0){
			out+=m[j]*2;
			while(c>0){
				j--, c--;
			}
			c=C;
		}
		printf("%lld\n", out);
	}
	
return 0;
}
