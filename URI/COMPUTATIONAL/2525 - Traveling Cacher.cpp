// Author: Gustavo Policarpo
// Name: Traveling Cacher
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2525

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

double dist(ii a, ii b){
	return sqrt(ll(b.F-a.F)*ll(b.F-a.F)+ll(b.S-a.S)*ll(b.S-a.S));
}

double check(ii a, ii b){
	return sqrt(ll(b.F-a.F)*ll(b.F-a.F));
}

vector <ii> n;
int main()
{
	
	int N, C, K, D;
	while(scanf("%d %d %d %d", &N, &C, &K, &D)!=EOF){
		ii aux; n.clear();
		
		rep(i, 0, N){
			scanf("%d %d", &aux.F, &aux.S);
			n.pb(aux);
		}
		
		sort(n.begin(), n.end()); int ans=0;
		
		rep(i, 0, C){
			
			scanf("%d %d", &aux.F, &aux.S);
			priority_queue <double> pq;
			
			rep(j, 0, N){
				
				double dst=dist(n[j], aux);
				
				if(dst==0){
					while(!pq.empty()) pq.pop();
					break;
				}
				
				if(pq.size()==K){
					if(dst>=pq.top()){
						if(check(n[j], aux)>=pq.top()) break;
					}
					else{
						pq.pop();
						pq.push(dst);
					}
				}else{
					pq.push(dst);
				}
				
			}
			
			double sum=0;
			while(!pq.empty()){
				sum+=pq.top();
				pq.pop();
			}
			
			if(sum>=D) ans++;
			
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
