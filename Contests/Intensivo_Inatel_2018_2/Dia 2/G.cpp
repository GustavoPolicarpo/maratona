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
	
	int N;
	while(cin >> N and N){
		int n[N]; rep(i, 0, N) cin >> n[i];
		int ans = 0, aux = 0;
		rep(i, 0, N){
			aux+=n[i];
			if(aux<0) aux = 0;
			ans = max(ans, aux);
		}
		if(ans==0) puts("Losing streak.");
		else printf("The maximum winning streak is %d.\n", ans);
	}
	
	return 0;
} 
