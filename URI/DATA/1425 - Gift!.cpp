// Author: Gustavo Policarpo
// Name: Gift?!
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1425

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
ll readInt();


int main(){
	int N, M;
	while(scanf("%d %d", &N, &M) and N){
		
		queue <ii> q;
		q.push(mp(1, 2)); bool yep=false;
		
		if(N<38 && M!=1){
			while(!q.empty()){
				int u=q.front().F, t=q.front().S; q.pop();
	
				ll j1=u-(2*t-1);
				ll j2=u+(2*t-1);
	
				if(j1==M || j2==M){
					yep=true;
					break;
				}
				if(j1>0) q.push(mp(j1, t+1));
				if(j2<N+1) q.push(mp(j2, t+1));	
			}
		}
		else yep=true;
		
		if(yep) puts("Let me try!");
		else puts("Don't make fun of me!");
	}
		
return 0;
}
