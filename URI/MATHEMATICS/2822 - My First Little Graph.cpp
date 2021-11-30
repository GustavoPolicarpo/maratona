// Author: Gustavo Policarpo
// Name: My First Little Graph
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2822

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

int C[200020], N, Q;
ll bit[200020][2];
multiset <int> ms;
multiset <int> :: iterator it;

void update(int x, int v, int p){
	for(; x<=N; x+=x&-x) bit[x][p]+=v;
}

ll query(int x, int p){
	ll ret = 0;
	for(; x>0; x-=x&-x) ret+=bit[x][p];
	return ret;
}

int main(){
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; scanf("%d", &T);
	while(T--){
		scanf("%d", &N);
		
		ms.clear();
		rep(i, 1, N+1){
			C[i] = i;
			ms.insert(C[i]);
			bit[i][0] = bit[i][1] = 0;
		}
		
		rep(i, 1, N+1){
			update(i, 1, 0);
			update(i, i, 1);
		}
		
		scanf("%d", &Q);
		int op, i, k;
		while(Q--){
			scanf("%d", &op);
			if(op==2){
				it = ms.begin(); ll L = *it;
				it = ms.end(); it--; ll R = *it;
				ll M = (L+R)/2;
				ll l = query(M, 0), r = query(R, 0)-l;
				ll sl = query(M, 1), sr = query(R, 1)-sl;
				//cout << L << " " << R << " " << M << " " << l << " " << r << " " << sl << " " << sr << '\n';
				ll ans = (ll)(l)*R - sl + sr - (ll)(r)*L - R + L;
				printf("%lld\n", ans);
			}else{
				scanf("%d %d", &i, &k);
				ms.erase(ms.find(C[i]));
				update(C[i], -1, 0);
				update(C[i], -C[i], 1);
				C[i] = k;
				ms.insert(C[i]);
				update(C[i], 1, 0);
				update(C[i], C[i], 1);
			}
		}
	}
	
	return 0;
}
