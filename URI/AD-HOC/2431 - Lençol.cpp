// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lençol
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2431

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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

int a[2], b[2], c[3];

bool check(int i, int j){
	if(a[i]+b[j] >= c[0] && min(a[1^i], b[1^j]) >= c[1]) return true;
	if(a[i]+b[j] >= c[1] && min(a[1^i], b[1^j]) >= c[0]) return true;
	if(a[i] >= c[0] && a[1^i] >= c[1]) return true;
	if(a[i] >= c[1] && a[1^i] >= c[0]) return true;
	if(b[j] >= c[0] && b[1^j] >= c[1]) return true;
	if(b[j] >= c[1] && b[1^j] >= c[0]) return true;
	
	return false;
}
int main()
{
	cin>>a[0]>>a[1]>>b[0]>>b[1]>>c[0]>>c[1];
	
	int yep=0;
	
	rep(i, 0, 2)
	rep(j, 0, 2)
		if(check(i, j)) yep=1;
	
	yep ? puts("S") : puts("N");

	return 0;
	
}
