// Author: Gustavo Policarpo
// Name: Digits Count
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1138

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

string num, aux;
int cmp, T;
ll pd[20][2][20][2];

ll solve(int i, bool p, int q, int z)
{
	if(i==T) return q;
	
	if(pd[i][p][q][z]!=-1) return pd[i][p][q][z];
	
	ll ret=0;
	if(z==1){
		if(p==1){
			int atual=num[i]-'0';
			rep(k, 0, atual+1)
				ret+=solve(i+1, atual==k, q, k==0);
		}
		else{
			rep(k, 0, 10)
				ret+=solve(i+1, 0, q, k==0);
		}
	}
	else{
		if(p==1){
			int atual=num[i]-'0';
			rep(k, 0, atual+1)
				ret+=solve(i+1, atual==k, q+(k==cmp), z);
		}
		else{
			rep(k, 0, 10)
				ret+=solve(i+1, 0, q+(k==cmp), z);
		}
	}
	
	return pd[i][p][q][z]=ret;
	
}

int main()
{
	int a, b;
	while(cin >> a >> b and a+b){
		ll v1[10], v2[10], v[10];
		if(a>0) a--;
		else num="0";
		num="";
		while(a>0){
			num+=(a%10)+'0';
			a/=10;
		}
		reverse(num.begin(), num.end());
		memset(v1, 0, sizeof v1); T=num.size();
		rep(i, 0, 10){
			memset(pd, -1, sizeof pd); cmp=i;
			v1[i]=solve(0, 1, 0, i==0);
		}
		num="";
		while(b>0){
			num+=(b%10)+'0';
			b/=10;
		}
		reverse(num.begin(), num.end());
		
		memset(v2, 0, sizeof v2); T=num.size();
		rep(i, 0, 10){
			memset(pd, -1, sizeof pd); cmp=i;
			v2[i]=solve(0, 1, 0, i==0);
		}
		memset(v, 0, sizeof v);
		rep(i, 0, 10)
			v[i]=v2[i]-v1[i];

		rep(i, 0, 9)
			cout << v[i] << " ";
		cout << v[9] << endl;			
	}	
return 0;
}


