// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cadeado com Segredo
// Nível: 7
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1412

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

int main()
{

	char in[1001];
	while(scanf("%s", in) !=EOF){
		if(in[0]=='*') break;
		int fim=strlen(in), dist[fim+5], ini=0; 
		
		dist[0]=in[0]-'a';
		rep(i, 1, fim) dist[i]=(in[i]-in[i-1]+26)%26;
		dist[fim]=('a'-in[fim-1]+26)%26;
		
		sort(dist, dist+fim+1);
		
		while(dist[ini]==0) ini++;
		
		int aux, ans=0;
		while(ini<=fim){
			if(dist[ini] < 26-dist[fim]){
				ans+=dist[ini]; 
				dist[fim]+=dist[ini];
				ini++;
			}
			else if(dist[ini] > 26-dist[fim]){
				ans+=26-dist[fim];
				dist[ini]-=26-dist[fim];
				fim--;
			}
			else{
				ans+=dist[ini];
				ini++, fim--;
			}
		}
		
		printf("%d\n", ans);	
	}

return 0;
}
