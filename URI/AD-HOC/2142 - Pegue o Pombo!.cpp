// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pegue o Pombo!
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2142

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
#define error 1e-5

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int A, M, mat[1000][1000];
int main()
{
	while(scanf("%d %d",&A, &M) !=EOF){
		if(M*3>A){
			printf("Raios! Raios Duplos! Raios Triplos!\n");
			continue;
		}
		int fim=sqrt(A)-1, mov=A+1, ini=0, dx=0, dy=1, x=0, y=0;
		bool a=true, b=false, c=false, d=false;
		while(mov--){
			mat[x][y]=mov;
			//cout << ini << " " << fim << " " << x << " " << y << endl;
			x+=dx, y+=dy;
			//if(x==sqrt(A)/2 && y==sqrt(A)/2) break;
			if(y==fim && a) dx=1, dy=0, a=false, b=true;
			if(x==fim && b) dx=0, dy=-1, fim--, b=false, c=true;
			if(y==ini && c) dx=-1, dy=0, ini++, c=false, d=true;
			if(x==ini && d) dx=0, dy=1, d=false, a=true;			
		}
		fim=sqrt(A);
		int tam=0, aux=A;
		while(aux>=1){
			aux/=10; tam++;
		}
		bool um=false, dois=false;
		if(fim%2==0) um=true;
		else dois=true;
		
		rep(i, 0, fim){
			rep(j, 0, fim){
				if(mat[i][j]==0 && um) mat[i][j]=2;
				if(mat[i][j]==0 && dois) mat[i][j]=8;
				if(j==0){
					if(mat[i][j]==3*M) cout << setw(tam) << '!';
					else if(mat[i][j]==2*M) cout << setw(tam) << '*';
					else printf("%*d", tam, mat[i][j]); //cout << setw(tam) << mat[i][j];
				}
				else {
					if(mat[i][j]==3*M) cout << setw(tam+1) << '!';
					else if(mat[i][j]==2*M) cout << setw(tam+1) << '*';
					else printf("%*d", tam+1, mat[i][j]); //cout << setw(tam+1) << mat[i][j];
				}
				if(j==fim-1 && i<fim-1) printf(" "); //cout << " ";
			}		
			printf("\n");
		}
	}
return 0;
}


