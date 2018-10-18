// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cabo de Guerra
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1586

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

ll v[1000001]; char nomes[1000001][12]; 
int main()
{
	int N; 
	while(scanf("%d", &N) and N){
		rep(i, 0, N){
			scanf("%s", nomes[i]); int tam=strlen(nomes[i]), aux=0;
			rep(j, 0, tam) aux+=int(nomes[i][j]); //cout << nomes[i][j] << endl;
			//cout << aux << endl;
			v[i]=aux;
		}
		int ini=-1, fim=N, meio=(N-1)/2; bool yep=true;
		while(fim-ini>1){
			//cout << ini << " " << fim << " " << meio << endl;
			ll l=0, r=0;
			rep(i, 0, meio+1) l+=v[i]*(meio-i+1);
			rep(i, meio+1, N) r+=v[i]*(i-meio);
			//cout << l << " " << r << endl;
			if(l==r){
				yep=false;
				printf("%s\n", nomes[meio]);
				break;			
			}
			else if(l<r){
				ini=meio;
				meio=(ini+fim)/2;
			}
			else if(l>r){
				fim=meio;
				meio=(ini+fim)/2;
			}
		}
		if(yep) puts("Impossibilidade de empate.");
	}

return 0;
}
