// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude Patatatitu
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2724

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


bool C(string a, string b){
	if(a.size() < b.size()) return true;
	rep(i, 0, a.size() - b.size() + 1){
		rep(j, 0, b.size()){
			if(a[i+j]!=b[j]) break;
			if(j==b.size()-1){
				if(i+j==a.size()-1) return false;
				if((a[i+j+1]>='A' && a[i+j+1]<='Z')) return false;
			}
		}
	}
	return true;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	vector <string> a, b; string s;
	
	rep(z, 0, T){
		
		if(z) puts("");
		
		a.clear(), b.clear();
		
		int N; cin >> N;
		rep(i, 0, N){
			cin >> s;
			a.pb(s);
		}
		
		int M; cin >> M;
		rep(i, 0, M){
			cin >> s;
			bool yep = true;
			rep(j, 0, N){
				yep = C(s, a[j]);
				if(!yep) break;
			}
			yep ? puts("Prossiga") : puts("Abortar");
		}
		
	}

	
	return 0;
	
}
