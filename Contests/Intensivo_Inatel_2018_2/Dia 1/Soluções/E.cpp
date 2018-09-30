#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int main(){
	
	int n;
	while(cin >> n){
		int r = 0, t = 0;
		while(42){
			r = (r*10+1)%n;
			t++;
			if(r==0) break;
		}
		cout << t << '\n';
	}
	
	return 0;
} 
