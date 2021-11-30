// Author: Gustavo Policarpo
// Name: At Most Twice
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2013

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

#define MAXV 100001
const int mod = 1e9 + 7;
#define error 1e-9


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;
ll INF= ll(1)<<60;

ll pd[20][1<<9 + 1][1<<9 + 1][2];
string U; int fim;

ll solve(int i, int m1, int m2, bool z){
	
	if(i==fim) return 0;
	if(pd[i][m1][m2][z]!=-1) return pd[i][m1][m2][z];
	
	ll ret=-INF;
	int aux=U[i]-'0';
	ll b10=pow(10, (fim-i-1));
	
	if(z){
		rep(j, 0, aux+1){
			if(m1 & (1<<j)){
				if(m2 & (1<<j)) continue;
				ret=max(ret, solve(i+1, m1, m2|(1<<j), j==aux)+b10*j);
			}
			else ret=max(ret, solve(i+1, m1|(1<<j), m2, j==aux)+b10*j);
		}
	}
	
	else{
		rep(j, 0, 10){	
			if(m1 & (1<<j)){
				if(m2 & (1<<j)) continue;
				ret=max(ret, solve(i+1, m1, m2|(1<<j), 0)+b10*j);
			}
			else ret=max(ret, solve(i+1, m1|(1<<j), m2, 0)+b10*j);
		}
	}
	
	return pd[i][m1][m2][z]=ret;
}


int main(){
	memset(pd, -1, sizeof pd);
	cin >> U; fim=U.size();
	printf("%lld\n", solve(0, 0, 0, 1));
}
