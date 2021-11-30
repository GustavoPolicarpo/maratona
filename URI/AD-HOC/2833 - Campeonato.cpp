// Author: Gustavo Policarpo
// Name: Campeonato
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2833

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
		cin >> aux;
		jog.pb(aux);
	}
	
	aux = 0;
	while(42){
		vector <int> pass;
		for(int i=0; i<jog.size()-1; i+=2){
			if((jog[i]==1 && jog[i+1]==9) || (jog[i]==9 && jog[i+1]==1)){
				cout << out[aux] << '\n';
				return 0;
			}
			if(jog[i]==1 || jog[i]==9){
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
