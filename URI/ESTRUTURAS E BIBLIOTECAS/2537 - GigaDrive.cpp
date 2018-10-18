// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: GigaDrive
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2537

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;

int bit[1010][1010], n, m, aux;

void update(int x, int y, int val){
    int yy; int L=n, C=n;
    while(x <= L){
        yy = y;
        while(yy <= C){
            bit[x][yy] += val;
            yy += (yy & -yy);
        }
        x += (x & -x);
    }
}

int query(int x, int y){
    int yy, sum = 0;
    while(x > 0){
        yy = y;
        while(yy > 0){
            sum += bit[x][yy];
            yy -= (yy & -yy);
        }
        x -= (x & -x);
    }
    return sum;
}


int main(){

	
	while(scanf("%d %d", &n, &m)!=EOF){
		
		rep(i, 0, n+2) rep(j, 0, n+2) bit[i][j]=0;
		
		rep(i, 1, n+1){
			rep(j, 1, n+1){
				scanf("%d", &aux);
				if(aux) update(i, j, 1);
			}
		}
		
		int x, y, xx, yy, ans;
		while(m--){
			scanf("%d %d", &x, &y); update(x, y, 1);
			scanf("%d %d %d %d", &x, &y, &xx, &yy);
			ans=query(xx, yy)-query(xx, y-1)-query(x-1, yy)+query(x-1, y-1);
			printf("%d\n", ans);
		}
		
	
	}

	return 0;

}
