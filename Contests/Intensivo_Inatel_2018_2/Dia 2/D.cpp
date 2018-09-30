#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

string conver(int n){
	string ret;
	while(n){
		ret.pb(n%10+'0');
		n/=10;
	}
	reverse(ret.begin(), ret.end());
	if(!ret.size()) ret.pb('0');
	return ret;
}

string s;
int pd[10][10][2][2][10][2];

int solve(int i, int q, int p, int z, int l, int m){
	if(i==s.size()) return q;
	int &ret = pd[i][q][p][z][l][m];
	if(ret!=-1) return ret;
	ret = 0;
	for(int j=0; j<(p==1?10:s[i]-'0'+1); j++){
		ret = ret+solve(i+1, q+(l==0?(z==1&&j==l):(j==l)), p||(j<s[i]-'0'), z||(j>0), l, m);
	}
	return ret;
}

int main(){
	
	int A, B;
	while(cin >> A >> B){
		if(A==0 && B==0) break; A--;
		memset(pd, -1, sizeof pd); 
		rep(i, 0, 10){
			if(i) printf(" ");
			s = conver(B); int QB = solve(0, 0, 0, 0, i, 0);
			s = conver(A); int QA = solve(0, 0, 0, 0, i, 1);
			printf("%d", QB-QA);
		}	printf("\n");
	}
	
	return 0;
} 
