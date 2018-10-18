// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fui ao Mercado e Comprei...
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2090

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



//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	int n, k;
	while(scanf("%d %d", &n, &k) and n+k){
		vector <string> vet; string aux;
		rep(i, 0, n){
			cin >> aux;
			vet.pb(aux);
		}
		
		int atual=1, last=1, ans=0, next, one=0;
		while(1){
			//cout << atual << " " << next << " " << one<< '\n';
			//system("pause");
			
			if(one==1) next=atual, one=-1;
			else if(one==0) one=1;
			
			if(atual > k){
				one=0;
				atual-=last-1;
				while(atual!=k){
					ans++, atual++;
				}
			}
			
			if(atual==k){
				cout << vet[ans] << '\n';
				break;
			}
			
			
			atual+=last;
			last++;
		}
		
	}
	
	return 0;
	
}
