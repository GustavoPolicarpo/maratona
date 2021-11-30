// Author: Gustavo Policarpo
// Name: Medical Clinic Queue
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2506

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

int main(){
	
	int N;
	
	while(scanf("%d", &N) !=EOF){
		
		int h, m, c, ta, ans=0;
		
		scanf("%d %d %d", &h, &m, &c);
		ta=h*60+m;
		
		while(1){
			if(ta%30==0) break;
			ta++;
		}
		
		int aux=h*60+m+c;
		if(ta > aux) ans++;
		ta=max(ta+30, h*60+m+30);
		
		rep(i, 1, N){
			
			scanf("%d %d %d", &h, &m, &c);
			
			while(1){
				if(ta%30==0) break;
				ta++;
			}
			
			int aux=h*60+m+c;
			if(ta > aux) ans++;
			ta=max(ta+30, h*60+m+30);
			
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
