#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;



int main(){
	
	int n, m; scanf("%d %d", &n, &m);
	int a[n+1], sa[n+1]; sa[0] = 0;
	rep(i, 1, n+1){
		scanf("%d", &a[i]);
		sa[i] = sa[i-1]+a[i];
	}
	int l, r;
	while(m--){
		scanf("%d %d", &l, &r);
		int s = sa[r] - sa[l-1];
		if(s&1) puts("Nao");
		else puts("Sim");
	}
	
	return 0;
} 
