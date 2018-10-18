// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo com Números
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1707

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

ll pd[10][2][100][10]; int fim;
char x[10];

ll solve(int pos, int mr, int sum, int last){
	
	if(pos==fim){
		if(last&1) return sum;
		return 0;
	}
	
	ll &p=pd[pos][mr][sum][last]; ll ret=0;
	if(p!=-1) return p;
	
	rep(i, 0, mr ? x[pos]-'0'+1 : 10)
		ret+=solve(pos+1, mr&(i==x[pos]-'0'), sum+i, i);
	
	return p=ret;
}


int main()
{
	
	int xx, yy, p;
	while(scanf("%d %d", &xx, &yy) !=EOF){
		
		if(xx>yy) swap(xx, yy); xx--;
		
		
		p=0;
		while(xx){
			x[p++]=(xx%10)+'0';
			xx/=10;
		}	reverse(x, x+p);
		memset(pd, -1, sizeof pd); fim=p;
		
		ll a=solve(0, 1, 0, 0);
		
		p=0;
		while(yy){
			x[p++]=(yy%10)+'0';
			yy/=10;
		}	reverse(x, x+p);
		memset(pd, -1, sizeof pd); fim=p;
		
		ll b=solve(0, 1, 0, 0);
		
		printf("%lld\n", max(a, b)-min(a, b));
	}
	
	
	return 0;
	
}
