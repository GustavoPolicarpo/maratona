// Author: Gustavo Policarpo
// Name: Building a Field
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2904

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int,int> ii;


int N, L[200020], S[200020], T;
set <int> H;

int main(){
	
	int N;	scanf("%d", &N);
	rep(i, 0, N){
		scanf("%d", &L[i]);
		L[i+N] = L[i];
		T+=L[i];
	}
	
	if(T&1){
		puts("N");
		return 0;
	}
	
	rep(i, 0, 2*N){
		if(i) S[i] = S[i-1];
		S[i]+=L[i];
		H.insert(S[i]);
	}
	
	int qt = 0;
	rep(i, 0, 2*N){
		if(H.count(S[i]+T/2)){
			qt++;
		}
	}
		
	puts(qt>=4 ? "Y" : "N");
	
	return 0;
}

