// Author: Gustavo Policarpo
// Name: Arranging Tasks
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1704

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
typedef pair < ii, int > iii;


bool cmp(ii a, ii b){
	if(a.S!=b.S) return a.S<b.S;
	return a.F>b.F;
}

int main(){
	
	int n, h;
	
	while(scanf("%d %d", &n, &h)!=EOF){
		
		ii v[n];
		rep(i, 0, n) scanf("%d %d", &v[i].F, &v[i].S);
		
		sort(v, v+n, cmp);
		priority_queue <int> pq;
		
		int ans=0;
		rep(i, 0, n){
			if(pq.size()+1>v[i].S){
				if(pq.size() && -pq.top()<v[i].F){
					ans+=-pq.top();
					pq.pop();
					pq.push(-v[i].F);
				}else{
					ans+=v[i].F;
				}
			}else{
				pq.push(-v[i].F);
			}
		}
		
		cout <<  ans << '\n';
		
	}
	
	return 0;
	
}
