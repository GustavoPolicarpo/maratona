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
	
	int x, y, t = 0;
	cin >> x >> y;
	
	while(x>0 || y>0){
		//cout << x << " " << y << '\n';
		if(t==0){
			if(x>y){
				cout << 1 << " " << x-y << '\n';
				x-=(x-y);
			}else if(y>x){
				cout << 2 << " " << y-x << '\n';
				y-=(y-x);
			}else{
				cout << 1 << " " << 1 << '\n';
				x--;
			}
			fflush(stdout);
		}else{
			int p, v; cin >> p >> v;
			if(p==1) x-=v;
			else y-=v;
		}
		t^=1;
	}
	
	return 0;
} 
