// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Primeiro Contato
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1970

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

int N, K, pd[101][51][51][51], tempo[101];

int solve(int i, int a, int b, int c)
{
	if(i==N) return 0;
	if(pd[i][a][b][c]!=-1) return pd[i][a][b][c];
	int ret=solve(i+1, a, b, c);
	
	if(a-tempo[i]>=0)
		ret=max(ret, solve(i+1, a-tempo[i], b, c)+tempo[i]);
	if(b-tempo[i]>=0)
		ret=max(ret, solve(i+1, a, b-tempo[i], c)+tempo[i]);
	if(c-tempo[i]>=0)
		ret=max(ret, solve(i+1, a, b, c-tempo[i])+tempo[i]);
		
	return pd[i][a][b][c]=ret;	
}
int main()
{
	cin >> N >> K;
	rep(i, 0, N)
		scanf("%d", &tempo[i]);
		
	int cart[3];
	cart[0]=0, cart[1]=0, cart[2]=0;
	rep(i, 0, K)
		scanf("%d", &cart[i]);
	
	memset(pd, -1, sizeof pd);
	int out=solve(0, cart[0], cart[1], cart[2]);
	
	printf("%d\n", out);
	
return 0;
}
