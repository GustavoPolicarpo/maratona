// Author: Gustavo Policarpo
// Name: Isosceles
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2243

//#define gc getchar_unlocked
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
const int mod = 1e9 + 7;
#define error 1e-9

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

int N, e[50005], d[50005], n[50005], ans;

int main()
{
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d", &n[i]);
	
	e[0]=n[0];
	rep(i, 1, N){
		e[i]=min(n[i], e[i-1]+1);
	} 
	
	d[N-1]=n[N-1]; ans=0;
	for(int i=N-2; i>=0; i--){
		d[i]=min(n[i], d[i+1]+1);
		
	}
	
	rep(i, 0, N){
		int aux=min(d[i], e[i]);
		int aui=min(i-0, N-i-1) + 1;
		ans=max(ans, min(aux, aui));
	}
	
	printf("%d\n", ans);
	
		
return 0;
}
