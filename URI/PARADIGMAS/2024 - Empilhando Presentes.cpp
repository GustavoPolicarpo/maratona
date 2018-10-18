// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Empilhando Presentes
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2024

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

struct presente{
	int l[3];
};

int N;
ll pd[1000][20001];
presente n[100001]; bool deuruim=true;

ll solve(int i, int a, int b)
{
	if(i==N){
		deuruim=false;
		return 10000000;
	}
	if(pd[i%1000][a+b]!=-1) return pd[i%1000][a+b];
	
	ll ret=0;
	
	if(n[i].l[0]<=a && n[i].l[1]<=b){
		ret=max(ret, solve(i+1,n[i].l[0], n[i].l[1])+n[i].l[2]);
	}
	if(n[i].l[0]<=a && n[i].l[2]<=b){
		ret=max(ret, solve(i+1,n[i].l[0], n[i].l[2])+n[i].l[1]);
	}
	if(n[i].l[1]<=a && n[i].l[2]<=b){
		ret=max(ret, solve(i+1,n[i].l[1], n[i].l[2])+n[i].l[0]);
	}
	
	return pd[i%1000][a+b]=ret;	
}

int main ()
{
	scanf("%d", &N);
	
	rep(i, 0, N){
		scanf("%d %d %d", &n[i].l[0],&n[i].l[1],&n[i].l[2]);
		sort(n[i].l, n[i].l+3);
	}
	
	memset(pd, -1, sizeof pd); 
	
	int out=solve(0, 10000, 10000);
	if(deuruim){
		printf("-1\n"); 
		return 0;
	}
	printf("%d\n", out-10000000);
			
return 0;
}
