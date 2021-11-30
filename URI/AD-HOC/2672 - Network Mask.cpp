// Author: Gustavo Policarpo
// Name: Network Mask
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2672

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
typedef pair < int, ii > iii;


void sol(int n, vector <int> in){
	
	ll qt = pow(2, 32-n) - 2;
	vector <int> v;
	
	rep(i, 0, n) v.pb(in[i]);
	rep(i, n, 32) v.pb(0);
	
	cout << "Endereco de rede: ";
	rep(i, 0, 4){
		int num = 0;
		rep(j, 0, 8){
			num*=2;
			num+=v[i*8+j];
		}
		if(i) cout << '.';
		cout << num;
	}	cout << '\n';
	
	v.clear();
	rep(i, 0, n) v.pb(in[i]);
	rep(i, n, 32) v.pb(1);
	
	cout << "Endereco de broadcast: ";
	rep(i, 0, 4){
		int num = 0;
		rep(j, 0, 8){
			num*=2;
			num+=v[i*8+j];
		}
		if(i) cout << '.';
		cout << num;
	}	cout << '\n';
	
	cout << "Numero de maquinas: " << qt << '\n';
	
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	string s;
	while(getline(cin, s)){
		
		int tipo = 0; vector <int> v;
		
		rep(i, 0, s.size()) if(s[i]=='/') tipo = 1;
		
		if(tipo==0){
			s.pb('.');
			rep(i, 0, s.size()){
				if(s[i]==' '){
					i++;
					int num = 0;
					while(i<s.size()){
						if(s[i]=='.'){
							vector <int> aux;
							while(num){
								aux.pb(num%2);
								num/=2;
							}
							while(aux.size()<8) aux.pb(0);
							reverse(aux.begin(), aux.end());
							rep(j, 0, aux.size()) v.pb(aux[j]);
							num = 0, i++;
						}else{
							num*=10;
							num+=s[i++]-'0';
						}
					}
				}
			}
			int cnt = 0;
			rep(i, 0, v.size()){
				if(v[i]==0) break;
				cnt++;
			}
			v.clear(); int i = 0, num = 0;
			while(i<s.size() && s[i]!=' '){
				if(s[i]=='.'){
					vector <int> aux;
					while(num){
						aux.pb(num%2);
						num/=2;
					}
					while(aux.size()<8) aux.pb(0);
					reverse(aux.begin(), aux.end());
					rep(j, 0, aux.size()) v.pb(aux[j]);
					num = 0, i++;
				}else{
					num*=10;
					num+=s[i++]-'0';
				}
			}
			vector <int> aux;
			while(num){
				aux.pb(num%2);
				num/=2;
			}
			while(aux.size()<8) aux.pb(0);
			reverse(aux.begin(), aux.end());
			rep(j, 0, aux.size()) v.pb(aux[j]);
			sol(cnt, v);
		}else{
			rep(i, 0, s.size()){
				if(s[i]=='/'){
					i++;
					int num = 0, cnt = 0;
					while(i<s.size()){
						num*=10;
						num+=s[i++]-'0';
					}
					cnt = num;
					v.clear(); i = 0, num = 0;
					while(i<s.size() && s[i]!=' ' && s[i]!='/'){
						if(s[i]=='.'){
							vector <int> aux;
							while(num){
								aux.pb(num%2);
								num/=2;
							}
							while(aux.size()<8) aux.pb(0);
							reverse(aux.begin(), aux.end());
							rep(j, 0, aux.size()) v.pb(aux[j]);
							num = 0, i++;
						}else{
							num*=10;
							num+=s[i++]-'0';
						}
					}
					vector <int> aux;
					while(num){
						aux.pb(num%2);
						num/=2;
					}
					while(aux.size()<8) aux.pb(0);
					reverse(aux.begin(), aux.end());
					rep(j, 0, aux.size()) v.pb(aux[j]);
					sol(cnt, v);
					break;
				}
			}
		}
		puts("");
		
	}
	
		
	return 0;
	
}
