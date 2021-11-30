// Author: Gustavo Policarpo
// Name: Rangel's Challenge
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2851

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

int p[101], v[100010], ans[100010];

int main(){
    
    int n; scanf("%d", &n);
    rep(i, 0, n) scanf("%d", &v[i]);
    
    memset(p, 0x3f3f3f3f, sizeof p);
    memset(ans, 0x3f3f3f3f, sizeof ans);
    
    for(int i=n-1; i>=0; i--){
    	for(int j=v[i]+1; j<=100; j++)
    		ans[i] = min(ans[i], p[j]);
		p[v[i]] = i;
	}
	
	rep(i, 0, n){
		if(i) printf(" ");
		if(ans[i]==0x3f3f3f3f) printf("*");
		else printf("%d", v[ans[i]]);
	}	puts("");
	
    return 0;
}  
