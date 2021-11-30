// Author: Gustavo Policarpo
// Name: Trilhas
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2296

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
	int N, Q, ans=INF, aux, id;
	scanint(N);
	rep(i, 0, N){
		
		scanint(Q); int n[Q];
		rep(j, 0, Q) scanint(n[j]);
		
		aux=0;
		rep(j, 1, Q)
			aux+=max(n[j]-n[j-1], 0);
		
		if(ans>aux){
			ans=aux;
			id=i+1;
		}
		//cout << aux << endl;
		aux=0;
		for(int j=Q-2; j>=0; j--)
			aux+=max(n[j]-n[j+1], 0);
		
		//cout << aux << endl;	
		if(ans>aux){
			ans=aux;
			id=i+1;
		}
	}	
	
	printf("%d\n", id);
	



return 0;
}



