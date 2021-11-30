// Author: Gustavo Policarpo
// Name: In Braille
// Level: 2
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1357

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
typedef pair < int, int > ii;
typedef pair < ii, int > iii;


string tb[3];
map<string, int> td;

int main()
{
	
	tb[0]=".**.*.*****.*****..*";
	tb[1]="**..*....*.**.*****.";
	tb[2]="....................";
	td[".***.."]=0;
	td["*....."]=1;
	td["*.*..."]=2;
	td["**...."]=3;
	td["**.*.."]=4;
	td["*..*.."]=5;
	td["***..."]=6;
	td["****.."]=7;
	td["*.**.."]=8;
	td[".**..."]=9;
	
	int N;
	while(scanf("%d", &N) and N){
		char op; cin >> op;
		
		if(op=='S'){
			string s; cin >> s;
			rep(j, 0, 3){
				rep(i, 0, s.size()){
					if(i) cout << " ";
					int aux=s[i]-'0';
					cout << tb[j][aux*2] << tb[j][aux*2+1];
				}	
				cout << '\n';
			}	
		}
		
		else{
			string s[N]; string aux;
			vector <string> v;
			
			rep(i, 0, 3){
				rep(j, 0, N){
					cin >> aux;
					v.pb(aux);
				}
			}
			rep(i, 0, N){
				rep(j, 0, 3){
					aux=v[i+j*N];
					rep(k, 0, 2) s[i].pb(aux[k]);
				}
			}
			
			rep(i, 0, N) cout << td[s[i]];
			cout << '\n';
			
		}
		
		
		
	}
	
	return 0;
	
}
