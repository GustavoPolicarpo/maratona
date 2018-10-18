// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Bodybuilder
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2144

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

int main()
{
	double w1, w2, r, rm, rmtt=0.0, cont=0;
	while(scanf("%lf %lf %lf", &w1, &w2, &r)){
		if(w1==0 && w2==0 && r==0) break;
		rm=(w1+w2)/2.0*(1+r/30.0);
		rmtt+=rm; cont++;
		//cout << rm << endl;
		if(rm<13) printf("Nao vai da nao");
		else if(rm<14) printf("E 13");
		else if(rm<40) printf("Bora, hora do show! BIIR!");
		else if(rm<60) printf("Ta saindo da jaula o monstro!");
		else printf("AQUI E BODYBUILDER!!");
		printf("\n");	
	}
	if(rmtt/cont>40) 
		printf("\nAqui nois constroi fibra rapaz! Nao e agua com musculo!\n");
			
return 0;
}
