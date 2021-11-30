// Author: Gustavo Policarpo
// Name: Lighter Mounts
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2794

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int N;
ii n[5050];

int main(){
	
	scanf("%d", &N);
	rep(i, 0, N) scanf("%d %d", &n[i].F, &n[i].S);
	sort(n, n+N);
	
	rep(i, 1, N){
		if(n[i].S > n[i-1].S){
			puts("N");
			return 0;
		}
	}
	
	puts("S");
	
	return 0;
}
