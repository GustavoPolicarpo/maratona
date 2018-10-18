// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Os Icosaedros do Lagarto
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2155

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
#define error 1e-12

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct pt{
	int x, y, e;
};

bool comp(pt a, pt b)
{
	if(a.e>b.e) return false;
	return true;
}

double dist(pt a, pt b)
{
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}
double grafo[10][10];
int main()
{
	int C, z=1;
	scanf("%d", &C);
	while(C--){
		vector <pt> cor; pt aux;
		scanf("%d %d", &aux.x, &aux.y); aux.e=0;
		cor.pb(aux);
		rep(i, 0, 6){
			scanf("%d %d %d", &aux.e, &aux.x, &aux.y);
			cor.pb(aux);
		}
		sort(cor.begin(), cor.end(), comp);
		
		rep(i, 0, 7)
			rep(j, i+1, 7)
				grafo[i][j]=grafo[j][i]=dist(cor[i], cor[j]);
						
		double mindist=INF;
		int um, dois, tres, quatro, cinco, seis;
		rep(a, 0, 1){
			rep(b, 0, 7){
				if(a==b) continue;
				rep(c, 0, 7){
					if(a==c || b==c) continue;
					rep(d, 0, 7){
						if(a==d || b==d || c==d) continue;
						rep(e, 0, 7){
							if(a==e || b==e || c==e || d==e) continue;
							rep(f, 0, 7){
								if(a==f || b==f || c==f || d==f || e==f) continue;
								rep(g, 0, 7){
									if(a==g || b==g || c==g || d==g || e==g || f==g) continue;
									double ddtotal=grafo[a][b]+grafo[b][c]+grafo[c][d]+				
												grafo[d][e]+grafo[e][f]+grafo[f][g]+grafo[g][a];
												
									if(ddtotal-mindist<-error){
										mindist=ddtotal;
										um=b, dois=c, tres=d, quatro=e, cinco=f, seis=g;
									}						
								}
							}
						}
					}
				}
			}
		}
		printf("Caso %d:\n", z++);
		if(um>=4) um++; if(dois>=4) dois++; 
		if(tres>=4) tres++; if(quatro>=4) quatro++; 
		if(cinco>=4) cinco++; if(seis>=4) seis++;
		printf("%d->%d->%d->%d->%d->%d->%d->%d: %.5lf\n", 4, um, dois, tres, quatro, cinco, seis, 4, mindist);
	
		
	}
	
	
return 0;
}


