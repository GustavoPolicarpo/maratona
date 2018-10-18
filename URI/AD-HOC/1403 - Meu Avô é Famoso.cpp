// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Meu Avô é Famoso
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1403

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



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N, M;
	while(1){
		scanf("%d %d", &N, &M); if(!N) break;
		int mat[N][M], aux;
		map<int, int> mapa; map<int, int>:: iterator it; vector <ii> go;
		rep(i, 0, N)
		rep(j, 0, M){
			scanf("%d", &aux);
			mapa[aux]++;
		}
		bool take=false; int use=0;
		for(it=mapa.begin(); it!=mapa.end(); it++){
			go.pb(mp(-it->second, it->first));
		}
		sort(go.begin(), go.end());
		rep(i, 1, go.size()){
			if(!take){
				use=go[i].F;
				take=true;
			}
			if(go[i].F!=use) break;
			//if(i>1) printf(" ");
			printf("%d ", go[i].S);
		}
		printf("\n");
	}
						
return 0;
}
