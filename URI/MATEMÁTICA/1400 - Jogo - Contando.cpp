// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo - Contando
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1400

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int n, m, k;
	while(scanf("%d %d %d", &n, &m, &k) and n+m+k){
		int num=1, go=1, pp=1, aux;
		bool yep;
		while(k>0){
			yep=false;
			aux=num;
			while(aux>1){
				if(aux%10==7){
					yep=true;
					break;
				}
				aux/=10;
			}
			if((num%7==0 || yep)&& pp==m){
				k--;
				if(k==0){
					printf("%d\n", num);
					break;
				}	
			}
			num++, pp+=go;
			if(pp==n || pp==1) go*=-1;
		}
	}
return 0;
}


