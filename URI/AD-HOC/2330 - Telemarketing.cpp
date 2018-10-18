// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Telemarketing
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2330

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
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


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


int N, L, l[1000010], n[1010];
int main ()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	scanint(N), scanint(L);
	rep(i, 0, L) scanint(l[i]);
	
	priority_queue <ii> pq;
	rep(i, 1, N+1) pq.push(mp(0, -i));
	rep(i, 0, L){
		int id=-pq.top().S, t=-pq.top().F; pq.pop();
		n[id]++;
		pq.push(mp(-(t+l[i]), -id));
	}
	
	rep(i, 1, N+1){
		printf("%d %d\n", i, n[i]);
	}
	
	
  
  return 0;
}
