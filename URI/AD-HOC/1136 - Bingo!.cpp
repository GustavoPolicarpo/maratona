// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bingo!
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1136

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

const ll mod = 1e9+7;
const ull MAX = mod*mod*2;
const int INF = 0x3f3f3f3f;

void scanint(ull &x){
    register ull ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N, B;
	
	while(scanf("%d %d", &N, &B) and N+B){
		
		int ball[B+2]; rep(i, 0, B) scanf("%d", &ball[i]);
		
		int alc[N+2]; rep(i, 0, N+1) alc[i]=0;
		
		rep(i, 0, B){
			rep(j, 0, B){
				int aux=abs(ball[i]-ball[j]);
				alc[aux]=1;
			}
		}
		
		int yep=1;
		rep(i, 0, N+1){
			if(!alc[i]){
				yep=0;
				break;
			}
		}
		
		if(yep) puts("Y");
		else puts("N");
		
	}
	
	return 0;
	
}
