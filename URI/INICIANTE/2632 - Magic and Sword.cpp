// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Magic and Sword
// Nível: 5
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2632

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

int dano[4];
int raio[4][3];
map<string, int> C;

int main(){
	
	C["fire"] = 0, dano[0] = 200, raio[0][0] = 20, raio[0][1] = 30, raio[0][2] = 50;
	C["water"] = 1, dano[1] = 300, raio[1][0] = 10, raio[1][1] = 25, raio[1][2] = 40;
	C["earth"] = 2, dano[2] = 400, raio[2][0] = 25, raio[2][1] = 55, raio[2][2] = 70;
	C["air"] = 3, dano[3] = 100, raio[3][0] = 18, raio[3][1] = 38, raio[3][2] = 60;
	
	int T; cin >> T;
	
	while(T--){
		int W, H, X0, Y0; cin >> W >> H >> X0 >> Y0;
		string S; int L, X, Y; cin >> S >> L >> X >> Y;
		int s = C[S], damage = 0;
		
		if( sqrt((X0-X)*(X0-X) + (Y0-Y)*(Y0-Y)) <= 1e-9+raio[s][L-1]) damage = dano[s];
		Y0+=H;
		if( sqrt((X0-X)*(X0-X) + (Y0-Y)*(Y0-Y)) <= 1e-9+raio[s][L-1]) damage = dano[s];
		Y0-=H, X0+=W;
		if( sqrt((X0-X)*(X0-X) + (Y0-Y)*(Y0-Y)) <= 1e-9+raio[s][L-1]) damage = dano[s];
		Y0+=H;
		if( sqrt((X0-X)*(X0-X) + (Y0-Y)*(Y0-Y)) <= 1e-9+raio[s][L-1]) damage = dano[s];
		X0-=W, Y0-=H;
		if(X>=X0 && X<=X0+W && Y>=Y0 && Y<=Y0+H) damage = dano[s];
		if(X>=X0 && X<=X0+W && (abs(Y0-Y)<=raio[s][L-1] || abs(Y0+H-Y)<=raio[s][L-1])) damage = dano[s];
		if(Y>=Y0 && Y<=Y0+H && (abs(X0-X)<=raio[s][L-1] || abs(X0+W-X)<=raio[s][L-1])) damage = dano[s];
		
		printf("%d\n", damage);
		
	}
	return 0;
}
