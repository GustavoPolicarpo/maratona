// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Botas Perdidas
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1245

#include <bits/stdc++.h>
using namespace std;

int esq[70], dir[70];
int a, tam, out=0;
char lad; 

int main(){
	
	while(cin >> a){
		for(int i=0;i<70;i++){
		esq[i]=0;
		dir[i]=0;
		}
		
		out=0;
		while(a--){
			cin >> tam >> lad;
			if(lad=='D')
				dir[tam]++;
			else
				esq[tam]++;
		}
		
		for(int i=29;i<62;i++){
			if(dir[i]>0 && esq[i]>0){
				dir[i]--;
				esq[i]--;
				out++;
				i--;
			}
		}
		
		cout << out << endl;
	}
	
}
