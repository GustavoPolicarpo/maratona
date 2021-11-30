// Author: Gustavo Policarpo
// Name: Eggfruit Cake
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3016

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
 
using namespace std;
 
typedef long long int ll;
typedef pair <int, int> ii;


string B;
int S;
queue <int> q;

int main(){
	
	cin >> B >> S;
	rep(i, 0, S-1) B.pb(B[i]);
	
	rep(i, 0, B.size()){
		if(B[i]=='E'){
			q.push(i);
		}
	}
	
	int i=0, j=S-1; ll ans=0;
	while(j<B.size()){
		if(q.size() && q.front()<=j){
			ans = ans + j-q.front() + 1;
		}
		j++;
		i++;
		if(q.size() && q.front()<i){
			q.pop();
		}
	}
	
	cout << ans << "\n";
	

	return 0;
}
