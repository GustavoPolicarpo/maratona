// Author: Gustavo Policarpo
// Name: Null Sequences
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1900

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
typedef pair < ll, ll > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;



int main()
{
	
	//freopen("csmall2.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N; cin >> N;
	
	map < ll, int > mapa;
	
	ll ans=0, sum=0; int n; mapa[0]=1;
	
	rep(i, 0, N){
		cin >> n;
		sum+=n;
		ans+=mapa[sum];
		mapa[sum]++;
	}
	
	cout << ans << '\n';

	return 0;
	
}
