// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Saltos Ornamentais
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2311

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int N; cin >> N;
	while(N--){
		string name; cin >> name; cout << name << " ";
		double t, n[7];
		scanf("%lf", &t);
		rep(i, 0, 7) scanf("%lf", &n[i]);
		sort(n, n+7);
		double sum=0;
		
		rep(i, 1, 6) sum+=n[i];
		
		printf("%.2lf\n", sum*t);
	}
	




return 0;
}



