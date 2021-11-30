// Author: Gustavo Policarpo
// Name: Knights Again
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2808

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
//#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

ii pa, ap;

int dx[] = {-2, -2, -1, -1, 1, 1, 2, 2},
	dy[] = {-1, 1, -2, 2, -2, 2, -1, 1};
	
int main(){
	
	string a, b; cin >> a >> b;
	
	pa.F = a[0]-'a', pa.S = a[1]-'0';
	ap.F = b[0]-'a', ap.S = b[1]-'0';
	
	rep(i, 0, 8){
		if(pa.F+dx[i]==ap.F && pa.S+dy[i]==ap.S){
			puts("VALIDO");
			return 0;
		}
	}
	
	puts("INVALIDO");
	

	return 0;
}
