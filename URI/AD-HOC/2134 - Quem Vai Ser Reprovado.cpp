// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Quem Vai Ser Reprovado?
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2134

#include<bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
using namespace std;
 
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
#define INF 0x3F3F3F3F
#define MAXV 100001
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct fefe{
	int nt; string nome;
};

bool cmp(fefe a, fefe b)
{
	if(a.nt>b.nt) return false;
	if(a.nt<b.nt) return true;
	
	if(a.nome>b.nome) return true;
	if(a.nome<b.nome) return false;
}
int main()
{
	int N, z=1; 
	fefe aux;
	while(scanf("%d", &N) !=EOF){
		vector <fefe> out;
		rep(i, 0, N){
			cin >> aux.nome >> aux.nt;
			out.pb(aux);
		}
		sort(out.begin(), out.end(), cmp);
		printf("Instancia %d\n", z++);
		cout << out[0].nome << '\n' << '\n';
		
	}
	
	

	
	
return 0;
}
