// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Escada Perfeita
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2306

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N; cin >> N;
	int n[N], sum=0, nn[N], fim=0;
	
	rep(i, 0, N){
		scanf("%d", &n[i]);
		sum+=n[i], fim=max(fim, n[i]);
	}
	
	int ini=-1;
	
	rep(i, 1, fim){
		int aux=(i+i+N-1)*N/2;
		if(aux==sum){
			ini=i;
			break;
		}
		else if(aux>sum){
			printf("-1\n");
			return 0;
		}
	}
	
	nn[0]=ini;
	rep(i, 1, N) nn[i]=nn[i-1]+1;
	
	int out=0;
	
	rep(i, 0, N)
		out+=abs(nn[i]-n[i]);
	
	cout << out/2 << '\n';
	
	
	return 0;
}

