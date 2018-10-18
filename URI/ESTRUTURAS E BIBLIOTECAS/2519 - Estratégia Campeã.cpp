// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Estratégia Campeã
// Nível: 4
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2519

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;
typedef pair <double, ii> iii;

int bit[1010][1010], L, C, aux, Q, r, a, b, c, d;

void update(int x, int y, int val){
    int yy;
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
	
	while(scanf("%d %d", &L, &C)!=EOF){
		
		rep(i, 1, L+1) rep(j, 1, C+1) bit[i][j]=0;
		
		rep(i, 1, L+1){
			rep(j, 1, C+1){
				scanf("%d", &aux);
				if(aux) update(i, j, 1);
			}
		}
		
		scanf("%d", &Q);
		
		while(Q--){
			scanf("%d %d %d %d %d", &r, &a, &b, &c, &d);
			if(r){
				printf("%d\n", query(c, d)-query(c, b-1)-query(a-1, d)+query(a-1, b-1));
			}else{
				update(a, b, -1);
				update(c, d, 1);
			}
			
		}
		
	}
	
	return 0;
	
}
