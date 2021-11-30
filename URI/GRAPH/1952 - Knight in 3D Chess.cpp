// Author: Gustavo Policarpo
// Name: Knight in 3D Chess
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1952

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef pair < int, int > ii;
typedef pair < ii, ii > iii;

int N, M, L, vis[111][111][111];

int dx[] = {-2, -2, 2, 2, -1, 1, -1, 1, -1, 1, 0, 0, -1, 1, 0, 0, -2, 2, 0, 0, -2, -2, 0, 0};
int dy[] = {-1, 1, -1, 1, -2, -2, 2, 2, 0, 0, -1, 1, 0, 0, -1, 1, 0, 0, -2, 2, 0, 0, -2, 2};
int dz[] = {0, 0, 0, 0, 0, 0, 0, 0, 2, 2, 2, 2, -2, -2, -2, -2, 1, 1, 1, 1, -1, -1, -1, -1};

bool dentro(iii u){
	return u.F.S >=1 && u.F.S <=N && u.S.F >=1 && u.S.F <=M
		&& u.S.S >=1 && u.S.S <=L && !vis[u.F.S][u.S.F][u.S.S];
}

int dijsktra(iii u, iii fim){
	queue <iii> q;
	q.push(u), vis[u.F.S][u.S.F][u.S.S]=1;
	
	while(1){
		u=q.front(); q.pop(); fim.F.F=u.F.F;
		
		if(u==fim) return u.F.F;
		
		rep(i, 0, 24){
			iii go;
			go.F.F=u.F.F+1;
			go.F.S=u.F.S+dx[i];
			go.S.F=u.S.F+dy[i];
			go.S.S=u.S.S+dz[i];
			if(!dentro(go)) continue;
			vis[go.F.S][go.S.F][go.S.S]=1;
			
			q.push(go);
		}
	}
	
}

int main()
{	
	
	scanf("%d %d %d", &N, &M, &L);
	iii ini, fim; ini.F.F=0;
	scanf("%d %d %d", &ini.F.S, &ini.S.F, &ini.S.S);
	scanf("%d %d %d", &fim.F.S, &fim.S.F, &fim.S.S);
	printf("%d\n", dijsktra(ini, fim));
	
	return 0;
	
}
