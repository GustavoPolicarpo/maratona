// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Trenó Lotado
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2726

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
typedef pair < int, ii > iii;


ll pc[55][55];
void pascal(){
	pc[0][0] = 1;
	pc[1][1] = 1;
	rep(i, 2, 55){
		pc[i][0] = 1;
		pc[i][1] = 1;
		rep(j, 2, 55){
			pc[i][j] = pc[i-1][j-1] + pc[i-1][j];
		}
	}
}

ll C(int n, int d){
	if(d>n) return 0;
	return pc[n+1][d+1];
}

int N, K;
ll p[55], A, B;

ull solve(int i, ll x, ull k){
	if(k==0) return 1;
	if(i<0 || i+1<k) return 0;
	ll sum = 0;
	rep(j, 0, i+1) sum+=p[j];
	while(p[i]>x) sum-=p[i], i--;
	if(i==-1) return 0;
	//cout << i << " " << x << " " << k  << " " << sum << '\n';
	if(sum<=x) return C(i+1, k);
	ull ret = solve(i-1, x, k) + solve(i-1, x-p[i], k-1);
	//cout << sum << " bb " << x << " " << ret << '\n';
	return ret;
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	pascal();
	
	int T; cin >> T;
	while(T--){
		
		cin >> N >> K;
		rep(i, 0, N) cin >> p[i];
		cin >> A >> B;
		
		sort(p, p+N);
		
		ll a = solve(N-1, B, K);
		ll b = solve(N-1, A-1, K);
		//cout << a << " " << b << '\n';
		ll ans = a - b;
		
		cout << ans << '\n';
		
	}
		
	return 0;
	
}
