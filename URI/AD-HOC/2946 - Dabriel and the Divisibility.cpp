// Author: Gustavo Policarpo
// Name: Dabriel and the Divisibility
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2946

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 
int N, M;
char s[100010];
vector <int> st;
int aux;

int main(){
	
	scanf("%s %d", s, &M);
	
	N = strlen(s);
	
	while(M--){
		scanf("%d", &aux);
		int r = 0;
		rep(i, 0, N){
			r = r*2;
			r = r + (s[i]=='1');
			r = r%aux;
		}
		if(!r) st.pb(aux);
	}
	
	sort(st.begin(), st.end());
	
	if(!st.size()) puts("Nenhum");
	else{
		int yep = 0;
		for(auto x : st){
			if(yep) printf(" ");
			printf("%d", x);
			yep = 1;
		}	puts("");
	}
		
	
	return 0;
}

