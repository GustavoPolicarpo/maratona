// Author: Gustavo Policarpo
// Name: Par ou Ímpar
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2286

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main ()
{
	int N, z=1;
	while(scanf("%d", &N) and N){
		printf("Teste %d\n", z++);
		string a, b;
		cin >> a >> b;
		
		int aa, bb;
		while(N--){
			scanf("%d %d", &aa, &bb);
			if((aa+bb) % 2 == 0) cout << a << '\n';
			else cout << b << '\n';
		}
		
		cout << '\n';
		
	}
	
  
  return 0;
}
