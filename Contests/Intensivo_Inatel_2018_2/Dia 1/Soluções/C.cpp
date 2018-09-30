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
	
	double n, h; cin >> n >> h;
	double areaT = 1.0*h/2.0;
	double area = areaT/n;
	
	rep(i, 1, n){
		if(i-1) printf(" ");
		printf("%.8lf", sqrt(h*h*i/n));
	}	printf("\n");
	
	return 0;
} 
