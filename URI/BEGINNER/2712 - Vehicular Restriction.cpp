// Author: Gustavo Policarpo
// Name: Vehicular Restriction
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2712

#include <bits/stdc++.h>

#define INF 1LL << 30
#define rep(i, a, b) for(int i = int(a); i < int(b); i++)
#define pb push_back
#define debug(x) cout << #x << " = " << x << endl;
#define debug2(x,y) cout << #x << " = " << x << " --- " << #y << " = " << y << "\n";
#define debugM( x, l, c ) { rep( i, 0, l ){ rep( j, 0, c ) cout << x[i][j] << " "; printf("\n");}}
#define all(S) (S).begin(), (S).end()
#define F first
#define S second
#define mk make_pair
#define FOR(i,a,b) rep(i,a,b+1)
#define SET(c,v) memset(c, v, sizeof c);

using namespace std;

typedef long long int ll;
typedef pair <ll, ll> ii;


int main()
{
	
	int N; cin >> N; string s; cin.ignore();
	while(N--){
		getline(cin, s);
		
		if(s.size()!=8){
			puts("FAILURE");
			continue;
		}
		
		bool yep = true;
		rep(i, 0, 3) if(s[i]<'A' || s[i]>'Z') yep = false;
		if(s[3]!='-') yep = false;
		rep(i, 4, 8) if(s[i]<'0' || s[i]>'9') yep = false;
		
		if(!yep){
			puts("FAILURE");
			continue;
		}
		
		if(s[7]=='1' || s[7]=='2') puts("MONDAY");
		if(s[7]=='3' || s[7]=='4') puts("TUESDAY");
		if(s[7]=='5' || s[7]=='6') puts("WEDNESDAY");
		if(s[7]=='7' || s[7]=='8') puts("THURSDAY");
		if(s[7]=='9' || s[7]=='0') puts("FRIDAY");
		
	}
		
    return 0;
}
