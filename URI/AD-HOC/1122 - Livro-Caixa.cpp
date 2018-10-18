// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Livro-Caixa
// Nível: 6
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1122

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F
#define limite 10000005

typedef pair < int, int > ii;
typedef long long int ll;

int N, F, n[40];
int pd[45][80000], aux[45];

int solve(int i, int sum)
{
	if(i==N){
		if(sum==F) return 1;
		return 0;
	}
	if(pd[i][sum+40000]!=-1) return pd[i][sum+40000];
	int a=solve(i+1, sum+n[i]);
	int b=solve(i+1, sum-n[i]);	
	if(a==1){
		if(aux[i]==0 || aux[i]==1) aux[i]=1;
		else aux[i]=3;
	}
	if(b==1){
		if(aux[i]==0 || aux[i]==2) aux[i]=2;
		else aux[i]=3;
	}
	return pd[i][sum+40000]=max(a, b);
}
int main ()
{
	while(scanf("%d %d", &N, &F) and N+F){
		rep(i, 0, N) scanf("%d", &n[i]);
		memset(aux, 0, sizeof aux);
		memset(pd, -1, sizeof pd);
		solve(0, 0);
		if(aux[N-1]==0) printf("*\n");
		else{
			rep(i, 0, N){
				if(aux[i]==1) cout << '+';
				else if(aux[i]==2) cout << '-';
				else cout << '?';
			}
			cout << endl;
		}
	}

return 0;
}
