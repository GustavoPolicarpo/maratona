// Author: Gustavo Policarpo
// Name: Swap It or Not?
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2564

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

int main(){
	
	int n;
	
	while(scanf("%d", &n)!=EOF){
		int v[n], r[n], maior=0, id=-1;
		rep(i, 1, n){
			scanf("%d %d", &v[i], &r[i]);
			if(v[i]>maior){
				maior=v[i];
				id=i;
			}
		}
		
		int cnt=r[id]!=1;
		rep(i, id+1, n) if(r[i]) cnt++;
		
		printf("%d\n", cnt);
		
	}
	
	
	return 0;
	
}
