// Author: Gustavo Policarpo
// Name: Emoticons :-)
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1364

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back

using namespace std;
typedef long long int ll;


int main(){
	
	int N, M;
	while(scanf("%d %d", &N, &M) and N){
		vector <string> pattern; string s;
		rep(i, 0, N){
			cin >> s;
			pattern.pb(s);
		}
		int ans = 0; getline(cin, s);
		rep(i, 0, M){
			getline(cin, s);
			int yep = false;
			do{
				yep = true;
				int fst = s.size();
				rep(j, 0, N){
					int p = s.find(pattern[j]);
					if(p>=0 && p<s.size()){
						fst = min(fst, p+(int)pattern[j].size()-1);
						yep = false;
					}
				}
				if(!yep) s[fst] = ' ', ans++;
			}while(!yep);
		}
		printf("%d\n", ans);
	}
	
	return 0;
	
}

