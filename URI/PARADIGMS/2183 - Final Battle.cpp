// Author: Gustavo Policarpo
// Name: Final Battle
// Level: 10
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2183

#define gc getchar_unlocked
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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
int N, K; map<char, int> mapa;
int pd[101][101][32][11]; char mat[101][101];
int dx[]={0, 1}, dy[]={1, 0};
int solve(int x, int y, int mask, int tempo){
	
	if(x==N-1 && y==N-1) return 0;
	int &p=pd[x][y][mask][tempo];
	if(p!=-1) return p;
	int ret=INF;
	
	rep(i, 0, 2){
		int ax=x+dx[i], ay=y+dy[i];
		if(ax==N || ay==N || mat[ax][ay]=='#') continue;
		if(isdigit(mat[ax][ay])){
			if(tempo>0) ret=min(ret, solve(ax, ay, mask, tempo-1));
			else ret=min(ret, solve(ax, ay, mask, 0)+mat[ax][ay]-'0');
		}
		else{
			int aux=mask|mapa[mat[ax][ay]];
			if(aux==31){
				ret=min(ret, solve(ax, ay, 0, K));
			}
			else{
				if(tempo>0) ret=min(ret, solve(ax, ay, aux, tempo-1));
				else ret=min(ret, solve(ax, ay, aux, 0));	
			}
		}
	}

	return p=ret;
}
int main()
{
	scanf("%d %d", &N, &K);
	
	mapa['P']=1, mapa['O']=2, mapa['W']=4,
	mapa['E']=8, mapa['R']=16;
	
	rep(i, 0, N)
	rep(j, 0, N)
		scanf(" %c", &mat[i][j]);
	mat[0][0]='0';
	
	memset(pd, -1, sizeof pd);
	
	int out=solve(0, 0, 0, 0);
	if(out>=INF) printf("-1\n");
	else printf("%d\n", out+1);
		
return 0;
}

