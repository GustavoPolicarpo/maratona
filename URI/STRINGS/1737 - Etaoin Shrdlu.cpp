// Author: Gustavo Policarpo
// Name: Etaoin Shrdlu
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1737

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
typedef pair < int, string > ii;
typedef pair < char, ii > iii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

bool my_comp(ii a, ii b){
	if(a.F != b.F) return a.F > b.F;
	return a.S < b.S;
}

int main()
{
	int n;
	while(scanf("%d", &n)){
		
		if(!n) break;
		cin.ignore();
		
		string all, aux;
		rep(i, 0, n) getline(cin, aux), all+=aux;
		
		map<string, int> mapa; int tt=0;
		rep(i, 0, all.size()-1){
			aux="";
			aux.pb(all[i]);
			aux.pb(all[i+1]);
			mapa[aux]++;
			tt++;
		}
		
		map<string, int> :: iterator it;
		vector <ii> v;
		for(it=mapa.begin(); it!=mapa.end(); it++){
			v.pb(mp(it->second, it->first));
		}
		
		sort(v.begin(), v.end(), my_comp);
		//reverse(v.begin(), v.end());
		
		for(int i=0; i<5; i++){
			cout << v[i].S << " " << v[i].F << " " << fixed << setprecision(6) << double(v[i].F)/tt << '\n';
		}
		
		cout << '\n';
		
	}
		
	
	return 0;
	
}
