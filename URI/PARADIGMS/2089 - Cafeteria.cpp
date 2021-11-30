// Author: Gustavo Policarpo
// Name: Cafeteria
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2089

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, V, n[1001], v[100001];

int solve(){
	v[0]=1;
	rep(i, 0, N){
		for(int j=V; j>=0; j--){
			if(!v[j]) continue;
			int k=n[i]+j;
			//cout << k << endl;
			if(k>V) continue;
			v[k]=1;
		}
	}
	return v[V];
}
int main()
{
	while(scanf("%d %d", &V, &N) and V+N){
		rep(i, 0, N) scanf("%d", &n[i]), v[i]=0;
		rep(i, N, V+1) v[i]=0;
		sort(n, n+N);
		int yep=solve();
		if(yep) printf("sim\n");
		else printf("nao\n");
	}

return 0;
}


