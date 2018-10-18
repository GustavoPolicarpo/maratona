// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Teclado Quebrado
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1642

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;




int main(){
	
	int n; string s;
	
	while(1){
		
		cin >> n; if(!n) break;
		cin.ignore(); getline(cin, s);
		
		int vet[200]; memset(vet, 0, sizeof vet);
		int ans=0, i=0, j=0, atual=0, cnt=0, fim=s.size();
		
		while(j<fim){
			
			if(vet[s[j]] || cnt<n){
				if(!vet[s[j]]) cnt++;
				vet[s[j]]++, j++, atual++; 
			}else{
				if(vet[s[i]]==1) cnt--;
				vet[s[i]]--, i++, atual--;
			}
			
			ans=max(ans, atual);
			
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
