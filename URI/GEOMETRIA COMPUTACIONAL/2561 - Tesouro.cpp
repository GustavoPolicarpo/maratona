// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Tesouro
// Nível: 3
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2561

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

struct rect{
	int x0, y0, x1, y1;
};

int main()
{
	
	rect a, b;
	
	while(scanf("%d %d %d %d", &a.x0, &a.y0, &a.x1, &a.y1)!=EOF){
		  scanf("%d %d %d %d", &b.x0, &b.y0, &b.x1, &b.y1);
		  
		  if(a.x0>a.x1) swap(a.x0, a.x1);
		  if(b.x0>b.x1) swap(b.x0, b.x1);
		  
		  if(a.y0>a.y1) swap(a.y0, a.y1);
		  if(b.y0>b.y1) swap(b.y0, b.y1);
		  
		  //cout << a.x0 << " " << a.y0 << " " << a.x1 << " " << a.y1 << '\n';
		  //cout << b.x0 << " " << b.y0 << " " << b.x1 << " " << b.y1 << '\n';
		  
		  rect c;
		  
		  c.x0=max(a.x0, b.x0);
		  c.x1=min(a.x1, b.x1);
		  c.y0=max(a.y0, b.y0);
		  c.y1=min(a.y1, b.y1);
		  
		  if(c.x1-c.x0<0 || c.y1-c.y0<0) puts("inexistente");
		  else if(c.x1-c.x0==0 && c.y1-c.y0==0) puts("ponto");
		  else if(c.x1-c.x0==0 || c.y1-c.y0==0) puts("linha");
		  else if( (c.x1-c.x0)*(c.y1-c.y0)<=10) puts("adequada");
		  else puts("grande");
		  
	}
	
	return 0;
	
}
