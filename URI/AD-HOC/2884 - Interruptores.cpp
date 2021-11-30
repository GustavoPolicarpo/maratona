// Author: Gustavo Policarpo
// Name: Interruptores
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2884

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


vector <bitset<1000> > vb;
bitset<1000> aux;

int main(){
	
	int n, m, qt, p;
	
	scanf("%d %d", &m, &n);
	
	rep(i, 0, m+1){
		aux.reset();
		scanf("%d", &qt);
		rep(i, 0, qt){
			scanf("%d", &p);
			aux.set(p-1);
		}
		vb.pb(aux);
	}

	int ans = -1;
	rep(z, 0, m*2+2){
		int k = z%m+1;
		if(!vb[0].count()){
			ans = z;
			break;
		}
		vb[0]^=vb[k];
	}
	
	cout << ans << '\n';
	
	
	return 0;
} 
