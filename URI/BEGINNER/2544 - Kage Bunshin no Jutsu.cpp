// Author: Gustavo Policarpo
// Name: Kage Bunshin no Jutsu
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2544

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
	
		int i=0;
		while(1<<i!=n)  i++;
		
		cout << i << '\n';
	
	}


	return 0;

}
