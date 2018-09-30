#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int n, m;
char mat[1010][1010];

int main(){
	
	rep(i, 0, 1010) rep(j, 0, 1010) mat[i][j] = '$';
	
	cin >> n >> m;
	rep(i, 505, 505+n) rep(j, 0, m) cin >> mat[i][j];
	
	string out;
	for(int i=505+n; i>=0; i--){
		for(int j=0; j<n+505-i; j++){
			if(mat[i+j][j]=='$') continue;
			out.pb(mat[i+j][j]);
		}
	}
	
	cout << out << '\n';
	
	return 0;
}
