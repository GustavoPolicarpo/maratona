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
	
	scanf("%d %d", &n, &m);
	rep(i, 0, n) scanf("%s", mat[i]);
	int x = 0, y = 0, dir = 1, ans = 0, aux = 0;
	while(42){
		y+=dir;
		if(y==-1 || y==m){
			x++, dir*=-1, y+=dir;
			if(x==n) break;
		}
		if(mat[x][y]=='.') aux++;
		else if(mat[x][y]=='L') aux = 0;
		ans = max(ans, aux);
	}
	
	cout << ans << '\n';
	return 0;
} 
