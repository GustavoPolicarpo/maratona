// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Shuffle
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1770

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

int main()
{
	int N, K;
	while(scanf("%d %d", &N, &K) !=EOF){
		int n[N], k[K];
		rep(i, 0, N)
			scanf("%d", &n[i]);
		rep(i, 0, K)
			scanf("%d", &k[i]);
		int tt=0;
		set <int> tocou;
		rep(i, 0, K){
			int musica=k[i];
			tt+=n[musica-1];
			tocou.insert(musica);
			if(tocou.size()==N) break;
		}
		if(tocou.size()==N) printf("%d\n", tt);
		else printf("-1\n");
	}
	
	
return 0;
}
