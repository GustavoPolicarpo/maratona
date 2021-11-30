// Author: Gustavo Policarpo
// Name: Complete Naebbirac’s Sequ...
// Level: 7
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2697

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
typedef pair < int, int > ii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int K, N; cin >> K >> N;
	int n[N+2], k[K+2];
	memset(k, 0, sizeof k);
	
	rep(i, 0, N){
		cin >> n[i];
		k[n[i]]++;
	}
	
	if(N%K==0){
		vector <int> v;
		rep(i, 1, K+1) if(k[i]!=N/K) v.pb(i);
		if(v.size()==2){
			if(k[v[0]] < k[v[1]]) swap(v[0], v[1]);
			printf("-%d +%d\n", v[0], v[1]);
			return 0;
		}
	}
	
	if((N+1)%K==0){
		vector<int> v;
		rep(i, 1, K+1) if(k[i]==(N+1)/K -1) v.pb(i);
		if(v.size()==1){
			printf("+%d\n", v[0]);
			return 0;
		}
	}
	
	if((N-1)%K==0){
		vector<int> v;
		rep(i, 1, K+1) if(k[i]==(N-1)/K +1) v.pb(i);
		if(v.size()==1){
			printf("-%d\n", v[0]);
			return 0;
		}
	}
	
	puts("*");
	return 0;
	
}
