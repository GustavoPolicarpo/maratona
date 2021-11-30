// Author: Gustavo Policarpo
// Name: Chocolate
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2328

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;



int main (){
	
	//freopen("in.txt", "r", stdin);
	
	
	
	int N, aux; cin >> N; int out=0;
	
	rep(i, 0, N){
		cin >> aux;
		out+=aux-1;
	}
	
	printf("%d\n", out);
			
	return 0;
	
}
	

