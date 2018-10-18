// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Casas de Westeros
// Nível: 4
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1862

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
#define MAXN 100001
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
}
*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int N, vis[1001];

int main()
{
	cin >> N;
	string n[N];
	rep(i, 0, N){
		cin >> n[i];
	}
	int nc=0, cnt;
	vector <int> mc;
	rep(i, 0, N){
		if(vis[i]) continue;
		nc++, cnt=0;
		rep(j, 0, N){
			if(n[i][j]=='S'){
				if(n[j]!=n[i]){
					printf("-1\n");
					return 0;
				}
				vis[j]=1;
				cnt++;
			}		
		}
		mc.pb(cnt);
	}
	sort(mc.begin(), mc.end());
	printf("%d\n", nc);
	for(int i=mc.size()-1; i>=0; i--){
		if(i<mc.size()-1) printf(" ");
		printf("%d", mc[i]);
	}
	printf("\n");

	
}


