// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Triângulos
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1472

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{

	int N;
	while(scanf("%d", &N) !=EOF ){
		set <ull> sk; ull si[N+1]; int aux, cont=0;
		si[0]=0;
		
		rep(i, 0, N){
			scanf("%d", &aux);
			si[i+1]=si[i]+aux;
			sk.insert(si[i+1]);
		}
		if(si[N]%3!=0){
			cout << 0 << endl;
			continue;
		}
		int div=si[N]/3;
		rep(i, 1, N-1){
			if(sk.count(si[i]+div) && 
				sk.count(si[i]+2*div))
				cont++;
		}
		printf("%d\n", cont);
	}	
return 0;
}
