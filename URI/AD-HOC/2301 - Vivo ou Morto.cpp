// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Vivo ou Morto
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2301

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
	int N, M, Q, op, z=1;
	while(1){
		scanint(N), scanint(M);
		if(!N) break;
		int n[N], vivo[N];
		rep(i, 0, N) scanint(n[i]), vivo[i]=1;
		
		while(M--){
			scanint(Q), scanint(op); int i=0;
			while(Q--){
				while(vivo[i]==-1) i++;
				scanint(vivo[i++]);
			}
			
			rep(j, 0, N)
				if(vivo[j]!=op)
					vivo[j]=-1;
		}
		
		int ans=-1;
		rep(i, 0, N){
			if(vivo[i]!=-1){
				ans=n[i];
				break;
			}
		}
			
		printf("Teste %d\n", z++);
		printf("%d\n\n", ans);
		
	}
	
	return 0;
}

