// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Pedra Filosofal
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1838

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

struct ped{
	int ini, fim, sum;
};
int N, pd[1001][3601]; 
ped n[1001];

int solve(int i, int l)
{
	if(i==N) return 0;
	if(pd[i][l]!=-1) return pd[i][l];
	
	int ret=solve(i+1, l);
	if(n[i].ini>=l)
		ret=max(ret, solve(i+1, n[i].fim)+n[i].sum);
	
	return pd[i][l]=ret;
}

bool comp(ped a, ped b)
{
	if(a.ini>b.ini) return false;
	return true;
}
int main ()
{
	memset(pd, -1, sizeof pd);
	
	cin >> N;
	rep(i, 0, N){
		scanf("%d %d", &n[i].ini, &n[i].fim);
		n[i].sum=n[i].fim-n[i].ini;
	}
	sort(n, n+N, comp);
	
	int out=solve(0, 0);
	printf("%d\n", out);
	
return 0;
}
