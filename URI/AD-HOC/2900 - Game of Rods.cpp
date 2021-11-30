// Author: Gustavo Policarpo
// Name: Game of Rods
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2900

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
	
	int N;
	while(cin >> N and N){
		int C, V, qt = 0;
		rep(i, 0, N){
			cin >>  C >> V;
			qt += (V/2);
		}
		qt/=2;
		cout << qt << '\n';
	}
	cout << '\n';
	
	

	return 0;
} 
