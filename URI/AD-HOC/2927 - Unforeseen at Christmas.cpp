// Author: Gustavo Policarpo
// Name: Unforeseen at Christmas
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2927

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;


int main(){

	int A, C, X, Y; cin >> A >> C >> X >> Y;
	
	int r = C-X-Y-A-1;
	if(r>=0){
		puts("Igor feliz!");
	}else{
		if(X*2>Y){
			puts("Caio, a culpa eh sua!");
		}
		else{
			puts("Igor bolado!");
		}
	}
			
	return 0;
}
