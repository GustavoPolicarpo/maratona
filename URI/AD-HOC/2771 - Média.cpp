// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Média
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2771

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int main(){
    
    int N, K;
    while(cin >> N >> K){
    	int n[N];
    	rep(i, 0, N) cin >> n[i];
    	vector <int> v;
    	rep(i, 0, N){
    		rep(j, i+1, N){
    			rep(k, j+1, N){
    				v.pb(n[i]+n[j]+n[k]);
				}
			}
		}
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		cout << fixed << setprecision(1) << (double)v[K-1]/3.0 << '\n';
	}
	
}

