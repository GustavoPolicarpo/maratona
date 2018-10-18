// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Onda Crítica
// Nível: 7
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1027

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
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

struct pt{
	int x, y;
};
pt n[1001]; int N, pd[1001][2];

int solve(int i, int s)
{
	if(pd[i][s]!=-1) return pd[i][s];
	int ret=0;
	rep(j, i+1, N){
		if(n[j].x==n[i].x) continue;
		if(s==0){
			if(n[j].y-n[i].y==2){
				ret=max(ret, solve(j, 1)+1);
			}
			
		}
		else{
			if(n[j].y-n[i].y==-2){
				ret=max(ret, solve(j, 0)+1);
			}	
		}
	}	
		
	return pd[i][s]=ret;
}
bool comp(pt a, pt b){
	if(a.x<b.x) return true;
	return false;	
}
int main()
{
	while(scanf("%d", &N) !=EOF){
		rep(i, 0, N){
			scanf("%d %d", &n[i].x, &n[i].y);
			rep(j, 0, 2) pd[i][j]=-1;
		}
		sort(n, n+N, comp);
		int out=0;
		rep(i, 0, N)
			out=max(out, max(solve(i, 0)+1, solve(i, 1)+1));
		cout << out << endl;
	}
	
return 0;
}
