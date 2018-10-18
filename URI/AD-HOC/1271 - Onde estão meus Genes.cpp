// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Onde estão meus Genes
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1271

#define gc getchar_unlocked
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
typedef pair < int, ii > iii;

//freopen("in.txt", "r", stdin);
//


int main()
{
//freopen("out.txt", "w", stdout);
	int N, R, Q, z=1;
	while(scanf("%d", &N) and N){
		printf("Genome %d\n", z++);
		int n[N+1];
		rep(i, 1, N+1) n[i]=i;
		scanf("%d", &R);
		int a, b;
		vector <ii> op;
		rep(i, 0, R){
			scanf("%d %d", &a, &b);
			op.pb(mp(a, b));
		}
		for(int i=op.size()-1; i>=0; i--){
			int a=op[i].F, b=op[i].S;
			while(a<b)	swap(n[a++], n[b--]);
		}
		
		//rep(i, 1, N+1) cout << n[i] << " ";
		//cout << endl;	
		scanf("%d", &Q);
		rep(i, 0, Q){
			scanf("%d", &a);
			printf("%d\n", n[a]);
		}
	}
		

return 0;
}

