// Author: Gustavo Policarpo
// Name: Automatic Correction of M...
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1657

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
typedef pair<int,int> ii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	
	//freopen("in.txt", "r", stdin);
	
	int N;
	while(cin >> N){
		map<string, int> mapa;
		vector <string> in;
		string s;
		rep(i, 0, N){
			cin >> s;
			in.pb(s);
			if(!mapa.count(s))
				mapa[s] = i;
		}
		int Q; cin >> Q;
		while(Q--){
			cin >> s;
			if(mapa.count(s)){
				cout << s << " is correct\n";
				continue;
			}
			int pos = N;
			
			rep(i, 0, s.size()){
				string t = s;
				t.erase(t.begin()+i);
				if(mapa.count(t)){
					pos = min(pos, mapa[t]);
				}
			}
			
			rep(i, 0, s.size()+1){
				rep(j, 0, 26){
					string t = s;
					t.insert(t.begin()+i, (char)(j+'a'));
					if(mapa.count(t)){
						pos = min(pos, mapa[t]);
					}
				}
			}
			
			rep(i, 0, s.size()){
				string t = s;
				rep(j, 0, 26){
					t[i] = (char)(j+'a');
					if(mapa.count(t)){
						pos = min(pos, mapa[t]);
					}
				}
			}
			
			string t = s;
			rep(i, 0, s.size()-1){
				swap(t[i], t[i+1]);
				if(mapa.count(t)){
					pos = min(pos, mapa[t]);
				}
				swap(t[i], t[i+1]);
			}
			
			if(pos==N){
				cout << s << " is unknown\n";
			}else{
				cout << s << " is a misspelling of " << in[pos] << '\n';
			}
		}
	}

	return 0;
}

