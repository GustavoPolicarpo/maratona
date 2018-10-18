// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Frutas Avançadas
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1731

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

//freopen("in.txt", "r", stdin);
//

int main()
{
	string a, b;
	while(cin >> a >> b){
		int aa=0, bb=0, fim=min(a.size(), b.size());
		rep(i, 0, a.size()){
			if(a[i]==b[bb]) bb++;
			if(bb==b.size()) break;
		}
		rep(i, 0, b.size()){
			if(b[i]==a[aa]) aa++;
			if(aa==a.size()) break;
		}
		
		//cout << aa << " " << bb << endl;
		if(aa>=bb){
			cout << b;
			for(int i=aa; i<a.size(); i++) cout << a[i];
			cout << '\n';
		}
		else{
			cout << a;
			for(int i=bb; i<b.size(); i++) cout << b[i];
			cout << '\n';
		}
		
		
	}




return 0;
}



