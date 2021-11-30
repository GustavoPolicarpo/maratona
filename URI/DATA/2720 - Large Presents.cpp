// Author: Gustavo Policarpo
// Name: Large Presents
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2720

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


struct use{
	int id, h, w, l;
};

bool cmp(use a, use b){
	int va = a.h*a.w*a.l;
	int vb = b.h*b.w*b.l;
	if(va!=vb) return va > vb;
	return a.id < b.id;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	while(T--){
		int n, m; scanf("%d %d", &n, &m); use aux;
		vector <use> v;
		
		rep(i, 0, n){
			scanf("%d %d %d %d", &aux.id, &aux.h, &aux.w, &aux.l);
			v.pb(aux);
		}
		
		sort(v.begin(), v.end(), cmp);
		
		vector <int> out;
		rep(i, 0, m) out.pb(v[i].id);
		sort(out.begin(), out.end());
		
		rep(i, 0, m){
			if(i) printf(" ");
			printf("%d", out[i]);
		}	puts("");
	}
	return 0;
	
}
