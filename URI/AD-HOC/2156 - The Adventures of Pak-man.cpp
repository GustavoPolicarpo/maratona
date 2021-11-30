// Author: Gustavo Policarpo
// Name: The Adventures of Pak-man
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2156

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
typedef pair < ii, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int L, C, I, dx, dy, out, x, y;
char mat[101][101], op[10001]; string aux;

bool dentro(int ax, int ay)
{
	return ax>=0 && ay>=0 && ax<L && ay<C && mat[ax][ay]!='#';
}

int main()
{
	while(scanf("%d %d %d", &L, &C, &I) and L+C+I){
		cin.ignore();
		dx=0, dy=1, out=0;
		rep(i, 0, L){
			getline(cin, aux);
			rep(j, 0, C){
				mat[i][j]=aux[j];
				if(mat[i][j]=='<')
					x=i, y=j;
			}
		}	
		scanf("%s", &op);
		rep(i, 0, I){
			if(op[i]=='W'){
				int ax=x+dx, ay=y+dy;
				if(!dentro(ax, ay)) continue;
				x=ax, y=ay;
				if(mat[x][y]=='*')
					mat[x][y]=' ', out++;
			}
			else if(op[i]=='U') dx=-1, dy=0;
			else if(op[i]=='D') dx=1, dy=0;
			else if(op[i]=='L') dx=0, dy=-1;
			else if(op[i]=='R') dx=0, dy=1;
		}
		printf("%d\n", out);
	}
	
return 0;
}
