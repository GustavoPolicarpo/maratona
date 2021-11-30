// Author: Gustavo Policarpo
// Name: Daunting Device
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2698

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

ll L, C, N;

set <iii> st;
ll qtc[100010];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanf("%lld %lld %lld", &L, &C, &N);
	
	st.insert(iii(ii(0, L-1), 1));
	qtc[1] = L;
	
	ll P, X, A, B, S, M1, M2; iii aux;
	while(N--){
		scanf("%lld %lld %lld %lld", &P, &X, &A, &B);
		
		S = qtc[P];
		M1 = (A+S*S)%L;
		M2 = (A+(S+B)*(S+B))%L;
		if(M1>M2) swap(M1, M2);
		
		set <iii> :: iterator it;
		vector <iii> er;
		vector <iii> in;
		
		it = st.lower_bound(iii(ii(M1, 0), 0));
		if(it!=st.begin()) it--;
		for(it = it; it!=st.end(); it++){
			aux = *it;
			if(aux.F.F > M2) break;
			if(aux.F.S < M1) continue;
			er.pb(aux);
		}
		
		rep(i, 0, er.size()){
			aux = er[i];
			st.erase(st.find(aux));
			qtc[aux.S] -= (aux.F.S - aux.F.F + 1);
			if(M1>aux.F.F) in.pb(iii(ii(aux.F.F, M1-1), aux.S));
			if(M2<aux.F.S) in.pb(iii(ii(M2+1, aux.F.S), aux.S));
		}
		
		rep(i, 0, in.size()){
			aux = in[i];
			qtc[aux.S] += (aux.F.S - aux.F.F + 1);
			st.insert(aux);
		}
		
		qtc[X] += (M2 - M1 + 1);
		st.insert(iii(ii(M1, M2), X));
		
	}
	
	ll ans = 0;
	rep(i, 1, C+1) ans = max(ans, qtc[i]);
	
	printf("%lld\n", ans);
	
	return 0;
}
