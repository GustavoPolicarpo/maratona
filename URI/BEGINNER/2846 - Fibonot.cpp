// Author: Gustavo Policarpo
// Name: Fibonot
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2846

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

vector <int> fibnot;

int main(){
	
	int l1 = 0, l2 = 1, at = 1, k; cin >> k;
	
	while(42){
		at = l1 + l2;
		rep(i, l2+1, at){
			fibnot.pb(i);
			if(fibnot.size()==k){
				printf("%d\n", fibnot.back());
				return 0;
			}
		}
		l1 = l2;
		l2 = at;
	}
	
	return 0;
}
