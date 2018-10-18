// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fatores Permitidos
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2501

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;


typedef long long int ll;
//typedef unsigned long long int ull;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

ll v[111];
vector <ll> ni(111, 0), next_multiple(111, 0), ugly;
vector <ll> gen[2], in[2];
ll N, M;

void sol(int op){
	
    rep(i, 0, in[op].size()) next_multiple[i]=in[op][i], ni[i] = 0;
    ugly.clear(); 
	
	ugly.pb(1);
    gen[op].pb(ugly[0]);
    
	rep(i, 1, M){
		ugly.pb(1LL << 42);
		rep(j, 0, in[op].size()) ugly[i] = min(ugly[i], next_multiple[j]);
		//if(ugly[i]>=1000000000000000000LL) return;
		gen[op].pb(ugly[i]);
		rep(j, 0, in[op].size()){
			if(ugly[i] == next_multiple[j]){
				ni[j]++;
				next_multiple[j]=ugly[ni[j]]*in[op][j];
			}
		}
	}
}

ll check(ll n){
	ll ret = 0;
	ll qt = 0;
	rep(i, 0, gen[0].size()){
		while(qt<gen[1].size() && gen[0][i]<=n/gen[1][qt]) qt++;
		ret+=qt;
	}
	return ret;
}


int main(){
	
	while(scanf("%lld %lld", &N, &M)!=EOF){
		if(!N) break;
		
		in[0].clear(); gen[0].clear();
		in[1].clear(); gen[1].clear();
		
		rep(i, 0, N){
			scanf("%lld", &v[i]);
			in[i%2].pb(v[i]);
		}
		
		++M;
		sol(0);
		sol(1);
		reverse(gen[0].begin(), gen[0].end());
		
		//for(int i=0; i<gen[0].size(); i++) cout << gen[0][i] << " "; cout << '\n';
		//for(int i=0; i<gen[1].size(); i++) cout << gen[1][i] << " "; cout << '\n';
	
		ll ini = 0, fim = 1LL << 42, mid, ans;
		while(ini<=fim){
			mid = (ini+fim)/2;
			ll xua = check(mid);
			if(xua>=M){
				ans = mid;
				fim = mid-1;
			}else{
				ini = mid+1;
			}
		}
		
		printf("%lld\n", ans);
		
	}
	
	
	return 0;
}
