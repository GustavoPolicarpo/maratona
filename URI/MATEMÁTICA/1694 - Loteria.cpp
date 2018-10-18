// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Loteria
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1694

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
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



ll C[55][55];
void pascal(int n){
	rep(i, 0, n){
		C[i][0]=C[i][i]=1;
		rep(j, 1, i)
			C[i][j]=C[i-1][j-1]+C[i-1][j];
	}
}

bool prime(int n){
	if(n<2) return 0;
	if(n==2) return 1;
	if(n%2==0) return 0;
	for(int i=3; i<=sqrt(n); i+=2)
		if(n%i==0) return 0;
	return 1;
}

int ehprimo[2505];
void primos(int n){
	rep(i, 0, n){
		if(prime(i)) ehprimo[i]=1;
		else ehprimo[i]=0;
	}
}

int main()
{
	pascal(52);
	primos(2502);
	
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k) and n){
		if(k>n && k>m){
			printf("%d\n", 0);
			continue;
		}
		
		int mat[n][m], cnt=0;
		rep(i, 0, n)
		rep(j, 0, m)
		mat[i][j]=cnt++;
		
		ll ans=0;
		rep(i, 0, n){
			cnt=0;
			rep(j, 0, m)
			if(!ehprimo[mat[i][j]])
				cnt++;
			ans+=C[cnt][k];
		}
		
		rep(j, 0, m){
			cnt=0;
			rep(i, 0, n)
			if(!ehprimo[mat[i][j]])
				cnt++;
			ans+=C[cnt][k];
		}
		
		if(k==1) ans/=2;
		printf("%lld\n", ans);
		
	}
	
	return 0;
	
}
