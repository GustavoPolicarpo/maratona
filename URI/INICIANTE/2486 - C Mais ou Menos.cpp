// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: C Mais ou Menos?
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2486

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
typedef pair < double, ii > iii;

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



int main()
{
	map<string, int> mapa;
	mapa["suco"]=120,
	mapa["morango"]=85,
	mapa["mamao"]=85,
	mapa["goiaba"]=70,
	mapa["manga"]=56,
	mapa["laranja"]=50,
	mapa["brocolis"]=34;
	
	int T;
	while(cin >> T and T){
		int tt=0, qt;
		string in;
		rep(i, 0, T){
			cin >> qt;
			cin >> in;
			tt+=mapa[in]*qt;
			getline(cin, in);
		}
		
		if(tt>=110 && tt<=130){
			printf("%d mg\n", tt);
		}
		else if(tt<110){
			printf("Mais %d mg\n", 110-tt);
		}
		else{
			printf("Menos %d mg\n", tt-130);
		}
		
	}
	
	return 0;
	
}
