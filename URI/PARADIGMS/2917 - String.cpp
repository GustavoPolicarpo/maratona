// Author: Gustavo Policarpo
// Name: String
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2917

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

int N, M[2000020];

int main(){
	
	while(scanf("%d", &N)!=EOF){
		rep(i, 0, 10*N){
			scanf("%d", &M[i]);
			M[10*N+i] = M[i];
		}
		int i = 0, j = 0, ans = -1, aux = 0;
		while(j<10*N*2){
			if(j >= N*10+i){
				aux -= M[i++];
			}
			while(i<j && M[i]<0) aux -= M[i++];
			ans = max(ans, aux);
			aux += M[j++];
			if(aux < 0) aux = 0, i = j;
			ans = max(ans, aux);
		}
		printf("%d\n", ans);
	}

	return 0;
} 
