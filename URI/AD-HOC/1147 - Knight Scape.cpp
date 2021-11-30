// Author: Gustavo Policarpo
// Name: Knight Scape
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1147

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3
#define MAXV 100001

#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

int dx[]={2, 2, 1, 1, -1, -1, -2, -2}, 
	dy[]={-1, 1, -2, 2, -2, 2, -1, 1};

int mat[10][10], z=1;

bool dentro(int x, int y){
	return x>=1 && y>=0 && x<9 && y<8 && mat[x][y]==0;
}

int main()
{
	string in;
	while(cin >> in){
		if(in=="0") break;
		memset(mat, 0, sizeof mat);
		int cx, cy, cnt=0;
		cx=in[0]-'0', cy=in[1]-'a';
		rep(i, 0, 8){
			cin >> in;
			int x=in[0]-'0', y=in[1]-'a';
			if(y>0) mat[x-1][y-1]=1;
			if(y<7) mat[x-1][y+1]=1;
		}
		/*rep(i, 1, 9){
			rep(j, 0, 8)
				cout << mat[i][j] << " ";
			cout << endl;
		}*/
		rep(i, 0, 8){
			int ax=cx+dx[i], ay=cy+dy[i];
			if(dentro(ax, ay)) cnt++;
		}
		printf("Caso de Teste #%d: %d movimento(s).\n", z++, cnt);
	}
	
	
	
	return 0;	
}
