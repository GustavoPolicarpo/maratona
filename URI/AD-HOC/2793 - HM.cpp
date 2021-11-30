// Author: Gustavo Policarpo
// Name: HM
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2793

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

char r[10000010]; 
int t, m = 0, f = 0, cnt = 0;
ll mod = 1e9+7;

int main(){
	
	gets(r); t = strlen(r);
	rep(i, 0, t){
		if(r[i]=='M') m++;
		else f++;
		if(m==f) cnt++;
	}
	
	ll ans = 1, base = 2; cnt--;
	while(cnt){
		if(cnt&1) ans = (ans*base)%mod;
		base = (base*base)%mod;
		cnt = cnt/2;
	}
	
	cout << ans << "\n";

	return 0;
}
