// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Média Não é Rápida o Sufi...
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1729

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

int main(){
	
	int N; double D;
	cin >> N >> D;
	
	int T;
	while(scanf("%d ", &T)!=EOF){
		double ta=0.0; int yep=1; string s;
		rep(z, 0, N){
			cin >> s;
			
			if(s[0]=='-'){
				yep=0;
				continue;
			}
			
			int i=0, h=0, m=0, ss=0;
			while(isdigit(s[i])){
				h*=10;
				h+=s[i]-'0';
				i++;
			}
			i++;
			while(isdigit(s[i])){
				m*=10;
				m+=s[i]-'0';
				i++;
			}
			i++;
			while(i<s.size()){
				ss*=10;
				ss+=s[i]-'0';
				i++;
			}
			ta+=h*60*60+m*60+ss;
			//cout << h << " " <<  m << " " << ss << '\n';
		}
		
			//cout << "-----\n";
		
		int m= int(ta/D/60.0);
		int ss=round((ta/D)-60*m);
		if(ss>=60){
			m++;
			ss%=60;
		}
		
		if(!yep) printf("%3d: -\n", T);
		else printf("%3d: %d:%02d min/km\n", T, m, ss );
	}
	
	return 0;
	
}
