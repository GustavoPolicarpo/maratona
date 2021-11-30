// Author: Gustavo Policarpo
// Name: William Xorando
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2500

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

const ll mod = 1e9+7;

int main()
{
	
	int n, m, k;
	
	while(scanf("%d %d %d", &n, &m, &k) !=EOF){
		
		if(!n) break;
		
		int vet[n+2]; rep(i, 0, n) scanf("%d", &vet[i]);
		
		int rot=m%n, ans=vet[(k-1-rot+n+n)%n];
		
		printf("%d\n", ans);
		
	}
	
	
	return 0;
	
}
