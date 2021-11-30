// Author: Gustavo Policarpo
// Name: Hunting Digletts
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2063

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

int vis[105], N, n[105];

int main()
{
	cin >> N;
	rep(i, 1, N+1)
		scanf("%d", &n[i]), vis[i]=0;
	vector <int> num;
	rep(i, 1, N+1){
		if(!vis[i]){
			int cont=0, u=i;
			while(!vis[u]){
				vis[u]=1;
				u=n[u];
				cont++;
			}
			num.pb(cont);
		}
	}
	sort(num.begin(), num.end());
	int mmc=num[0];
	rep(i, 1, num.size()){
		int aux=__gcd(num[i], mmc);
		mmc=mmc/aux*num[i];
	}
	printf("%d\n", mmc);
	
		
return 0;
}
