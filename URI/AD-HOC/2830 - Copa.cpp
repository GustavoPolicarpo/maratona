// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Copa
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2830

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 



int main(){
	
	vector <string> out;
	out.pb("oitavas"); out.pb("quartas"); out.pb("semifinal"); out.pb("final");
	vector <int> jog; int aux;
	
	rep(i, 0, 16){
		//cin >> aux;
		aux = i+1;
		jog.pb(aux);
	}
	
	int a, b; cin >> a >> b;
	
	aux = 0;
	while(42){
		vector <int> pass;
		for(int i=0; i<jog.size()-1; i+=2){
			if((jog[i]==a && jog[i+1]==b) || (jog[i]==b && jog[i+1]==a)){
				cout << out[aux] << '\n';
				return 0;
			}
			if(jog[i]==a || jog[i]==b){
				pass.pb(jog[i]);
			}else{
				pass.pb(jog[i+1]);
			}
		}
		jog = pass;
		aux++;
	}
	
	
	
	return 0;
}  
