// Author: Gustavo Policarpo
// Name: New Record
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2551

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;


int main(){

	int n;
	
	while(cin >> n){
		double a,b, r=0;
		
		rep(i, 0, n){
			cin >> a >> b;
			if(b/a>r){
				cout << i+1 << '\n';
				r=b/a;
			}
		}
	}

	return 0;

}
