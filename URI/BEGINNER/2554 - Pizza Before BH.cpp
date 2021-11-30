// Author: Gustavo Policarpo
// Name: Pizza Before BH
// Level: 3
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2554

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


int main(){

	int n, d;
	
	while(cin >> n >> d){
		vector <string> v; string s;
		int id=-1;
		
		rep(i, 0, d){
			cin >> s;
			v.pb(s);
			int cnt=0, aux;
			rep(j, 0, n){
				cin >> aux;
				cnt+=aux;
			}
			if(cnt==n && id==-1) id=i;
		}
		
		if(id==-1) puts("Pizza antes de FdI");
		else cout << v[id] << '\n';
	}


	return 0;

}
