// Author: Gustavo Policarpo
// Name: Soma
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/3051

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define REP(i,a,b) for( int i = (int) a; i <= (int) b; i++ )
#define PER(i,a,b) for( int i = (int) a; i >= (int) b; i-- )
#define F first
#define S second
#define mk make_pair
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <double, ii> iii;
const int MAX = 2e3+3;
const int mod = 1e9+7;

int N, K;
int x[500050];

int main(){
	
	scanf("%d %d", &N, &K);
	rep(i, 0, N) scanf("%d", &x[i]);
	
	ll i=0, j=0, s=0, l0=0, l1=0, ans = 0;
	while(j<N){
		if(x[j]==0) l1++;
		else l1=0;
		s+=x[j];
		j++;
		
		while(j<N && (s+x[j]<=K || x[j]==0)){
			if(x[j]==0) l1++;
			else l1=0;
			s+=x[j];
			j++;
		}
		
		while(i<j && (s-x[i]>=K || x[i]==0)){
			if(x[i]==0) l0++;
			else l0=0;
			s-=x[i];
			i++;
		}
		
		if(s==K){
			if(K!=0)
				ans = ans + (ll)(l0+1)*(l1+1);
			else ans = ans + ((ll(1)+l0)*l0/2);
		}
	}
	
	printf("%lld\n", ans);
    

    return  0;
}
