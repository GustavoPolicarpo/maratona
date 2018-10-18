// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Baralho Embaralhado
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1709

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;



int main()
{
	int N; cin >> N;
	int c=1, aux=2*c, ans=1, n=N/2;
	while(aux!=c){
		if(aux<=n) aux*=2;
		else aux=aux*2-N-1;
		ans++;
	}
	cout << ans << endl;
	
return 0;
}
