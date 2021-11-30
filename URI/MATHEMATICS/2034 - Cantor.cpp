// Author: Gustavo Policarpo
// Name: Cantor
// Level: 7
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2034

#include <bits/stdc++.h>
#include <ext/pb_ds/assoc_container.hpp> 
#include <ext/pb_ds/tree_policy.hpp>

#include <ext/rope> //header with rope
using namespace std;
using namespace __gnu_cxx; //namespace with rope and some additional stuff
using namespace __gnu_pbds;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <char, char> ii;

const ll mod = 1000000007;
const int INF = 0x3f3f3f3f;


ll D, H, B;
string L, s;
ll pd[64][2][2];

void conver(ll n){
	s.clear();
	while(n){
		s.pb(n%B+'0');
		n/=B;
	}
	reverse(s.begin(), s.end());
	if(!s.size()) s.pb('0');
}

ll solve(int i, bool p, bool z){
	if(i==s.size())	return 1;
	if(pd[i][p][z]!=-1) return pd[i][p][z];
	ll ret = 0;
	for(int j=0; j<=(p?B-1:s[i]-'0'); j++){
		if(L[j]=='N' && (j!=0 || z==1)) continue;
		ret += solve(i+1, p|(j!=s[i]-'0'), z|(j!=0));
	}
	return pd[i][p][z] = ret;
}

int main(){

	while(cin >> D >> H >> B >> L){
		if(D==-1) break;
		
		memset(pd, -1, sizeof pd);
		conver(H);
		ll up = solve(0, 0, 0);
		memset(pd, -1, sizeof pd);
		conver(D-1);
		ll down = solve(0, 0, 0);
		cout << up - down << '\n';
		
	}
	
	return 0;
	
}
