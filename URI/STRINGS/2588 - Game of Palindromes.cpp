// Author: Gustavo Policarpo
// Name: Game of Palindromes
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2588

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;

int main(){

	char s[1010];
	
	while(scanf("%s", s)!=EOF){
	
		int tam=strlen(s); vector <int> v(26, 0);
		
		rep(i, 0, tam) v[s[i]-'a']++;
		
		int ans=0;
		rep(i, 0, 26) if(v[i]&1) ans++;
		
		printf("%d\n", max(ans-1, 0));
		
	}
	
	

	return 0;
	
}
