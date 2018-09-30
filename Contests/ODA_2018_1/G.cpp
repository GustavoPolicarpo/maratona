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
	
	int a, b; cin >> a >> b;
	int qa = 0, qb = 0;
	rep(i, 1, a+1) if(a%i==0) qa++;
	rep(i, 1, b+1) if(b%i==0) qb++;
	if(qa>qb) puts("Jogador 1");
	else if(qb>qa) puts("Jogador 2");
	else puts("Empate");
	
	return 0;
}
