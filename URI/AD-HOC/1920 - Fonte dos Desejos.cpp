// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fonte dos Desejos
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1920

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

struct ponto{
	int x, y;
	
	ponto (){}
	ponto(int x, int y) : x(x), y(x) {}
	
	ll dstO(ponto o){
		return ((o.x-x)*(o.x-x)+(o.y-y)*(o.y-y));
	}
};

struct score{
	int dentro, borda, fora;
	score(){}
	score(int x) : dentro(x), borda(0), fora(0) {}
	
};
int main()
{
	int N, r1, r2; ponto O, a, b; score C, P;
	while(scanf("%d", &N) and N){
		scanf("%d %d %d %d", &O.x, &O.y, &r1, &r2); C=P=score(0);
		
		ll in=r1*r1, borda=r2*r2;
		
		rep(i, 0, N){
			
			scanf("%d %d", &a.x, &a.y);
			ll c=a.dstO(O); //cout << c << endl;
			if(c<in) C.dentro++;
			else if (c<=borda) C.borda++;
			else C.fora++;
			
			scanf("%d %d", &b.x, &b.y);
			ll p=b.dstO(O); //cout << p << endl;
			if(p<in) P.dentro++;
			else if (p<=borda) P.borda++;
			else P.fora++;
		}
		
		//cout << C.dentro << " " << C.borda << " " <<
		//	P.dentro << " " << P.borda << endl;
		if(C.dentro>P.dentro) puts("C > P");
		else if(P.dentro>C.dentro) puts("P > C");
		else if(C.borda>P.borda) puts("C > P");
		else if(P.borda>C.borda) puts("P > C");
		else puts("C = P");		
	}
	return 0;		
}



