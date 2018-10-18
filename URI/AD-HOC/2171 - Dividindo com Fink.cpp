// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Dividindo com Fink
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2171

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define mod 1300031
#define error 1e-7

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

int main(){
	vector <int> sum;
	rep(i, 1, 1000){
		int aux=(i+1)*i/2;
		sum.pb(aux);
	}
	int N;
	while(scanf("%d", &N) and N){
		int u=0, v=0;
		int pos=lower_bound(sum.begin(), sum.end(), N) -sum.begin();
		if(sum[pos]>N) pos--;
		u=sum[pos], v=N-u;
		printf("%d %d\n", u, v);
	}
	
return 0;
}
