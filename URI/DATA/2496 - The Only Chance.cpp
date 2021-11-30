// Author: Gustavo Policarpo
// Name: The Only Chance
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2496

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

const ll mod = 1e9+7;


int main()
{
	
	int T; cin >> T;
	
	while(T--){
		
		int N; cin >> N;
		string s; cin >> s;
		
		int cnt=0;
		rep(i, 0, s.size()){
			int aux=s[i]-'A';
			if(aux == i) continue;
			if(s[aux]-'A'==i){
				cnt++;
				swap(s[i], s[aux]);
			}else{
				cnt=2;
				break;
			}
		}
		
		cnt == 1 ? puts("There are the chance.") : puts("There aren't the chance.");
		
	}
	
	
	return 0;
	
}
