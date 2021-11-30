// Author: Gustavo Policarpo
// Name: Help the Federation
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1588

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

//freopen("in.txt", "r", stdin);
//

struct jogo{
	int pt, v, g, id;
};

bool comp(jogo a, jogo b){
	if(a.pt>b.pt) return true;
	if(b.pt>a.pt) return false;
	
	if(a.v>b.v) return true;
	if(b.v>a.v) return false;
	
	if(a.g>b.g) return true;
	if(b.g>a.g) return false;
	
	if(a.id<b.id) return true;
	return false;
}
int main()
{	//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	while(T--){
		int N, M; scanf("%d %d", &N, &M);
		jogo n[N];
		map<string, int> mapa; string a, b;
		map<int, string> rec;
		rep(i, 0, N){
			cin >> a;
			mapa[a]=i;
			rec[i]=a;
			n[i].v=0, n[i].g=0, n[i].pt=0, n[i].id=i;
		}
		int ga, gb;
		rep(i, 0, M){
			cin >> ga >> a >> gb >> b;
			int u=mapa[a], v=mapa[b];
			if(ga==gb){
				n[u].g+=ga, n[v].g+=gb;
				n[u].pt++, n[v].pt++;
			}
			else if(ga>gb){
				n[u].g+=ga, n[v].g+=gb;
				n[u].pt+=3, n[u].v++;
			}
			else{
				n[u].g+=ga, n[v].g+=gb;
				n[v].pt+=3, n[v].v++;
			}
		}
		sort(n, n+N, comp);
		rep(i, 0, N){
			cout << rec[n[i].id] << endl;
		}
	}
	
	

return 0;
}



