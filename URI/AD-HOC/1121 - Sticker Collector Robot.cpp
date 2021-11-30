// Author: Gustavo Policarpo
// Name: Sticker Collector Robot
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1121

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

int N, M, S;
char lab[102][102], s[50001];

bool dentro(int x, int y)
{
	if(x>=0 && x<N && y>=0 && y<M)
		return lab[x][y]!='#';
	return false;
}
ii rotate(ii aux, char c)
{
	if(c=='E'){
		if(aux.F==-1 && aux.S==0)
			return mp(0, -1);
		if(aux.F==1 && aux.S==0)
			return mp(0, 1);
		if(aux.F==0 && aux.S==-1)
			return mp(1, 0);
		if(aux.F==0 && aux.S==1)
			return mp(-1, 0);
	}
		if(aux.F==-1 && aux.S==0)
			return mp(0, 1);
		if(aux.F==1 && aux.S==0)
			return mp(0, -1);
		if(aux.F==0 && aux.S==-1)
			return mp(-1, 0);
		if(aux.F==0 && aux.S==1)
			return mp(1, 0);	
}
int out;
void go(int i, ii dir, ii u)
{	
	if(i==S+1) return;
	if(lab[u.F][u.S]=='*') lab[u.F][u.S]='.', out++;	
	if(s[i]=='F'){
		if(dentro(u.F+dir.F, u.S+dir.S))
			u.F+=dir.F, u.S+=dir.S;
	}
	else
		dir = rotate(dir, s[i]);
	go(i+1, dir, u)	;
}
int main()
{	 
	while(scanf("%d %d %d", &N, &M, &S) and N+M+S){
		ii dir, p; out=0;
		rep(i, 0, N)	
			rep(j, 0, M){
				scanf(" %c", &lab[i][j]);
				if(lab[i][j]=='N') dir=mp(-1,0), p=mp(i, j);
				else if(lab[i][j]=='S') dir=mp(1,0), p=mp(i, j);
				else if(lab[i][j]=='L') dir=mp(0,1), p=mp(i, j);
				else if(lab[i][j]=='O') dir=mp(0,-1), p=mp(i, j);
			}
		scanf("%s", &s);
		go(0, dir, p);
		printf("%d\n", out);			
	}
			
return 0;
}
