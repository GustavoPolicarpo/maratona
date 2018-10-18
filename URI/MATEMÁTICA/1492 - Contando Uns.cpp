// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Contando Uns
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1492

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

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

ull A, B; int num[66]; 
ll pd[66][2][66];

ll solve(int i, int p, int q){
	if(i==-1) return q;
	if(pd[i][p][q]!=-1) return pd[i][p][q];
	
	ll ret=0;
	if(p) ret+=solve(i-1, p, q+1)+solve(i-1, p, q);
	else{ //se numero melhor, posso pegar o proximo com 1 ou zero
		if(num[i]==0) ret+=solve(i-1, p, q);
		//se for zero permaneco com 0
		else ret+=solve(i-1, 1, q)+solve(i-1, 0, q+1);
		//se for um posso ir com zero ou com um
	}
	return pd[i][p][q]=ret;
}
int main()
{
	while(scanf("%llu %llu", &A, &B) !=EOF){
		ll a=0, b=0; int i=0; A--;
		while(A){
			num[i++]=A%2;
			A/=2;
		}
		memset(pd, -1, sizeof pd);
		a=solve(i-1, 0, 0); i=0;
		while(B){
			num[i++]=B%2;
			B/=2;
		}
		memset(pd, -1, sizeof pd);
		b=solve(i-1, 0, 0);
		printf("%lld\n", b-a);
	}
	
	
	
return 0;
}
