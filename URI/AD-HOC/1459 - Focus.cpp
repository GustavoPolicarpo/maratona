// Author: Gustavo Policarpo
// Name: Focus
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1459

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

vector <ii> n;
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	while(scanf("%d", &N) !=EOF){
		n.clear(); int A, B;
		rep(i, 0, N){
			scanint(A), scanint(B);
			n.pb(mp(A, B));
		}
			sort(n.begin(), n.end());
			int cnt=1;
			int aux=n[0].S;
			rep(i, 1, N){
				if(n[i].F<=aux){
					aux=min(aux, n[i].S);
					continue;
				}
				cnt++, aux=n[i].S;
			}
			printf("%d\n", cnt);
		}
				
return 0;
}
