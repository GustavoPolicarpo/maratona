// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bolsa de Valores
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1932

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

int N, C, n[200001], pd[200001][2];

int solve(int i, int has)
{
	if(i==N) return 0;
	if(pd[i][has]!=-1) return pd[i][has];
	int ret=solve(i+1, has);
	
	if(has==0){
		ret=max(ret, solve(i+1, 1)-n[i]-C);
	}
	else
		ret=max(ret, solve(i+1, 0)+n[i]);
		
	return pd[i][has]=ret;
	
	
}
int main ()
{
	cin >> N >> C;
	rep(i, 0, N)
		scanf("%d", &n[i]);
	memset(pd, -1, sizeof pd);
	int out=solve(0, 0);
	printf("%d\n", out);
	

return 0;
}
