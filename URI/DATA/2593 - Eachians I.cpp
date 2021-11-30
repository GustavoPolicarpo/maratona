// Author: Gustavo Policarpo
// Name: Eachians I
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2593

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i(a); i < (b); i++)

#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back

#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}

#define mp make_pair
#define fst first
#define snd second

typedef pair<int,int> ii;
typedef long long ll;

const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;


vector <int> KMP(string text, string pattern)
{
    
    int n = text.size(), m = pattern.size();
    vector <int> ret, T(m+2);
 	
    int k = T[0] = -1;
    rep(i, 0, m)
    {
        while( ~k && pattern[i] != pattern[k] /*&& ( pattern[k] || pattern[i] <= k )*/ ) k = T[k];
        T[i + 1] = ++k;
    }
    
    
    k = 0;
    rep(i, 0, n)
    {
        while( ~k && text[i] != pattern[k] /*&& ( pattern[k] || text[i] <= k )*/ ) k = T[k];
        ++k;
        if( k == m ) ret.pb(i-m+1), k = T[k];
    }
    
    return ret;
    
}


int main()
{
	
	string text, pattern, aux;
	text.pb(' '); 
	getline(cin, aux); rep(i, 0, aux.size()) text.pb(aux[i]);
	text.pb(' ');
	
	int n; cin >> n;
	
	rep(i, 0, n){
		
		pattern="";
		pattern.pb(' ');
		cin >> aux; rep(j, 0, aux.size()) pattern.pb(aux[j]);
		pattern.pb(' ');
		
		vector <int> p = KMP(text, pattern);
		if(!p.size()) puts("-1");
		else{
			rep(j, 0, p.size()){
				if(j) printf(" ");
				printf("%d", p[j]);
			}	printf("\n");
		}
	}
	

	return 0;
	
}
