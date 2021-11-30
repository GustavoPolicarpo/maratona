// Author: Gustavo Policarpo
// Name: Random Bingo Cards
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1771

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

int in[25];
ii v[5];

int main ()
{
	v[0].F=1, v[0].S=15,
	v[1].F=16, v[1].S=30,
	v[2].F=31, v[2].S=45,
	v[3].F=46, v[3].S=60,
	v[4].F=61, v[4].S=75;
	
	while(scanf("%d", &in[0])!=EOF){
		int b=0, j=0, n=0, g=0, o=0;
		rep(i, 0, 25){
			if(i==0) ;
			else if(i==12) in[i]=40;
			else scanf("%d", &in[i]);
			if(in[i]<1) continue;
			else if(in[i]<=15) b++;
			else if(in[i]<=30) j++;
			else if(in[i]<=45) n++;
			else if(in[i]<=60) g++;
			else if(in[i]<=75) o++;
		}
		bool ok=true;
		rep(i, 0, 25){
			if(in[i]<v[i%5].F || in[i]>v[i%5].S){
				ok=false;
				break;
			}
		}
		if(ok){
			puts("OK");
			continue;
		}
		//cout << b << " " << j << " " << n << " " << g << " " << o << '\n';
		bool rc=false;
		if(b==5 && j==5 && n==5 && g==5 && o==5){
			rc=true;
		}
		if(rc){
			puts("RECICLAVEL");
			continue;
		}
		puts("DESCARTAVEL");
	}
	
	
  
  return 0;
}

