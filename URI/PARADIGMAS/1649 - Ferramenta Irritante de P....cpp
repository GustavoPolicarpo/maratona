// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ferramenta Irritante de P...
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1649

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
	int n, m, r, c, lab[100][100]; char aux;
	while(scanf("%d %d %d %d", &n, &m, &r, &c) and n+m+r+c){
		rep(i, 0, n)
			rep(j, 0, m){
				scanf(" %c", &aux);
				lab[i][j]=aux-'0';
			}	
		int mov=0;
		rep(i, 0, n){
			rep(j, 0, m){
				if(lab[i][j]==1){
					int l=min(i,n-r), 
						k=min(j,m-c);
					rep(o, l, l+r)
						rep(p, k, k+c){
							if(lab[o][p]==1) lab[o][p]=0;
							else 			 lab[o][p]=1;
						}
							
					mov++;
				}
			}
		}
		rep(i, 0, n){
			rep(j, 0, m){
				if(lab[i][j]==1){
					mov=-1;
					break;
				}
			}
			if(mov==-1) break;
		}
		printf("%d\n", mov);
	}	
				
return 0;
}
