// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Schweisen
// Nível: 7
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1112

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

int bit[1002][1002];
int L, C, Q, P;

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

	while(scanf("%d %d %d", &L, &C, &P) and L+C+P){
		L++, C++;
	    memset(bit, 0, sizeof(bit));
	    scanf("%d", &Q);
	    int qt, x, y, z, w; char op;
	    rep(i, 0, Q){
	    	scanf(" %c", &op);
	    	if(op=='A'){
	    		scanf("%d %d %d", &qt, &x, &y);
	    		update(x+1, y+1, qt);
			}
			else{
				scanf("%d %d %d %d", &x, &y, &z, &w);
				x++, y++, z++, w++;
				int a, b, c, d;
				a=min(x, z), b=min(y, w);
				c=max(x, z), d=max(y, w);
				int out=query(c, d);
				if(a>1){
					out-=query(a-1, d);
				}	
				if(b>1){
					out-=query(c, b-1);
				}
				if(min(x, z)>1 && min(y, w)>1){
					out+=query(a-1, b-1);
				}
				out*=P;
				printf("%d\n", out);
			}	
		}
		printf("\n");
	}

    return 0;
}




