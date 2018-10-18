// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogo da Matriz
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2710

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

int bit[505][505];
int L=502, C=502;

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

	int Q, x, y, z, w, v; char op;
	
	while(cin >> Q){
		memset(bit, 0, sizeof bit);
		while(Q--){
			cin >> op;
			if(op=='A'){
				cin >> x >> y;
				cout << query(x, y) << '\n';
			}else{
				cin >> x >> y >> z >> w >> v;
				update(x, y, v);
				update(z+1, y, -v);
				update(x, w+1, -v);
				update(z+1, w+1, v);
			}
		}
	}
	
    return 0;
}
