// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Banco de Dados
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2148

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
#define error 1e-5

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int pd[15][100], S, D;

int solve(int i, int sum)
{
	if(i==D && sum==S) return 1;
	if(i==D) return 0;
	if(pd[i][sum]!=-1) return pd[i][sum];
	
	int ret=0;
	rep(j, 1, 7)
		ret+=solve(i+1, sum+j);
	
	return pd[i][sum]=ret;
}
int main()
{
	double dados[15];
	dados[0]=1;
	rep(i, 1, 14)
		dados[i]=dados[i-1]*6;	
		
	int C; cin >> C;
	while(C--){
		scanf("%d %d", &S, &D);
		memset(pd, -1, sizeof pd);
		int tt=solve(0, 0);
		double out=tt/dados[D];
		cout << fixed << setprecision(15) << out << endl;	
	}
return 0;
}


