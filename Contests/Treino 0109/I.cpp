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
	
	int N, T; scanf("%d %d", &N, &T);
	int t[N]; rep(i, 0, N) scanf("%d", &t[i]);
	
	int a = 0, aux = 0;
	rep(i, 0, N){
		if(aux+t[i]>T) break;
		aux+=t[i];
		a++;
	}
	
	int b = 0; aux = 0;
	for(int i=N-1; i>=0; i--){
		if(aux+t[i]>T) break;
		aux+=t[i];
		b++;
	}
	
	if(a==b) puts("Empate");
	else if(a>b) puts("Yan");
	else puts("Nathan");

	return 0;
} 
