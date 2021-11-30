// Author: Gustavo Policarpo
// Name: Volleyball
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2310

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
	double tt[3], t[3], aux;
	rep(i, 0, 3) tt[i]=t[i]=0.0;
	while(N--){
		string name; cin >> name;
		rep(i, 0, 3){
			cin >> aux;
			tt[i]+=aux;
		}
		rep(i, 0, 3){
			cin >> aux;
			t[i]+=aux;
		}
	}
	rep(i, 0, 3){
		if(tt[i]<0.5) tt[i]=1.0;
	}
	
	printf("Pontos de Saque: %.2lf %%.\n", t[0]*100.0/tt[0]);
	printf("Pontos de Bloqueio: %.2lf %%.\n", t[1]*100.0/tt[1]);
	printf("Pontos de Ataque: %.2lf %%.\n", t[2]*100.0/tt[2]);



return 0;
}



