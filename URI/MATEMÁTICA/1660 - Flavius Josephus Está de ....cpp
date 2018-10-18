// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Flavius Josephus Está de ...
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1660

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000

typedef long long int ll;
typedef pair < double, double > ii;
typedef pair < int, ii > iii;



int main()
{
	int N, A, B;
	while(scanf("%d", &N) and N){
		scanf("%d %d", &A, &B);
		ll aux, atual=0, ans=0; map<ll, int> mm;
		mm[atual]++;
		while(1){
			atual=(atual*atual)%N;
			aux=(A*atual)%N;
			aux=(aux+B)%N;
			mm[aux]++;
			if(mm[aux]==2) ans++;
			else if(mm[aux]==3) break;
			atual=aux;
		}
		printf("%lld\n", N-ans);
	}
		
return (0);
}
