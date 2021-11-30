// Author: Gustavo Policarpo
// Name: Discovering Password
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2252

#include <bits/stdc++.h>

#define rep(i,a,b) for(int i=a; i<b; i++)

using namespace std;

typedef pair <double, int> ii;
int main(){
    
	int n, z=1;
	ii m[20]; 
	
	while(scanf("%d", &n) !=EOF){	
			rep(i, 0, 10){
			scanf("%lf", &m[i].first); m[i].first=-m[i].first; 
			m[i].second=i;
		}
		sort(m, m+11);
		printf("Caso %d: ", z++);
		rep(i, 0, n){
			printf("%d", m[i].second);
		}
		printf("\n");
	}
	
	return 0;
}
