// Author: Gustavo Policarpo
// Name: Sensor Accuracy
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2774

#include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)

int main(){
	
	int N, M;
	
	while(scanf("%d %d", &N, &M)!=EOF){
		int t = (N*60)/M; double v[t], X, s=0; 
		rep(i,0,t)
			scanf("%lf", &X), s+=X, v[i]=X;
		double m = s/t, resp=0;
		rep(i,0,t)
			resp += (v[i]-m)*(v[i]-m);
		resp /= (t-1);
		printf("%.5lf\n", sqrt(resp)); 
	}
	
	return 0;
}
