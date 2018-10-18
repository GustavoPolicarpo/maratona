// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Guloso
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1594

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;

typedef unsigned int ui;

ui v[1000010];
ll N, K, S, sum;
deque <int> dq;

ll solve(){
	
	dq.clear(); sum=0;
	
	rep(i, 0, K){
		while(!dq.empty() && v[i]>=v[dq.back()]) dq.pop_back();
		dq.pb(i);
	}
	
	rep(i, K, N){
		sum+=v[dq.front()];
		while(!dq.empty() && dq.front()<=i-K) dq.pop_front();
		while(!dq.empty() && v[i]>=v[dq.back()]) dq.pop_back();
		dq.pb(i);
	}
	
	sum+=v[dq.front()];
	
	return sum;
		
}


int main(){
	
	int T; cin >> T;
	while(T--){
		
		scanf("%lld %lld %lld", &N, &K, &S); 
		
		v[0] = S;
		for (int i = 1; i < N; ++i)
    		v[i] = (1LL*v[i-1]*1103515245 + 12345) % (2147483648LL);
    	
    	printf("%lld\n", solve());
		
	}
	
	return 0;
	
}
