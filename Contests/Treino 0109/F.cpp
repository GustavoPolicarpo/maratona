#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int main(){
	
	int n, m, k; cin >> n >> m >> k;
	int r = n-m;
	//(x+k)/n >= 0.7 -> x+k >= 0.7*n -> x = 0.7*n-k -> x = (7n - 10k + 9)/10
	int x = (7*n - 10*k + 9)/10;
	if(x>r) x = -1;
	else if(x<0) x = 0;
	cout << x << '\n';
	
	int f = k+r;
	int p = (f*100)/n;
	cout << p << '\n';
	
	return 0;
} 
