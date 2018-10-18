// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Chegando Junto
// Nível: 7
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1057

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

char lab[12][12];
int vis[112][112][112];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
int N;

struct dvd{
	int x, y;
	bool operator == (dvd k) {
		return x==k.x && y==k.y;
	}
};

struct cd{
	dvd A, B, C;
	int tempo;
	
};

dvd A, B, C;
dvd a, b, c;

bool chegou()
{
	return lab[a.x][a.y]=='X' && lab[b.x][b.y]=='X' && lab[c.x][c.y]=='X';
}

bool podeir(dvd aux)
{
	return
	    (aux.x>=0  &&   aux.x<N) &&
	    (aux.y>=0  &&   aux.y<N) &&
	    (lab[aux.x][aux.y]!='#');	
}

void solve(int t)
{
	queue <cd> q; cd atual; int tempo;
	atual.A=A, atual.B=B, atual.C=C, atual.tempo=0;
	q.push(atual);
	
	while(!q.empty()){
		
		atual=q.front();
		a=atual.A, b=atual.B, c=atual.C, tempo=atual.tempo;
		q.pop();
		
		if(chegou()){
			cout << "Case " << t << ": " << tempo << endl;
			return;
		}		
		rep(i, 0, 4){
			dvd aa, bb, cc;
				aa.x=a.x+dx[i], bb.x=b.x+dx[i], cc.x=c.x+dx[i], 
				aa.y=a.y+dy[i], bb.y=b.y+dy[i], cc.y=c.y+dy[i];	
			
			if(podeir(aa))
				atual.A=aa;	
			else
				atual.A=a;
			
			if(podeir(bb))
				atual.B=bb;	
			else
				atual.B=b;
				
			if(podeir(cc))
				atual.C=cc;	
			else
				atual.C=c;
			
			if(atual.A==atual.B)
				atual.A=a, atual.B=b;
			
			if(atual.A==atual.C)
				atual.A=a, atual.C=c;
			
			if(atual.B==atual.C)
				atual.B=b, atual.C=c;
				
			if(atual.A==atual.B)
				atual.A=a, atual.B=b;
			
			if(atual.A==atual.C)
				atual.A=a, atual.C=c;
			
			if(atual.B==atual.C)
				atual.B=b, atual.C=c;
				
			atual.tempo=tempo+1;
			
			if(vis[atual.A.x*N+atual.A.y][atual.B.x*N+atual.B.y][atual.C.x*N+atual.C.y]==1) continue;
			vis[atual.A.x*N+atual.A.y][atual.B.x*N+atual.B.y][atual.C.x*N+atual.C.y]=1;	
			q.push(atual);				
		}	
	}	
	
	cout << "Case " << t << ": trapped" << endl;
}
int main()
{
	int T; cin >> T;
	rep(i, 0, T){
		cin >> N; int aux=0;
		memset(vis, 0, sizeof(vis));
		rep(i, 0, N)
			rep(j, 0, N){
				scanf(" %c", &lab[i][j]);
				if(lab[i][j]=='A')
					A.x=i, A.y=j;
				if(lab[i][j]=='B')
					B.x=i, B.y=j;
				if(lab[i][j]=='C')
					C.x=i, C.y=j;					
			}
		solve(i+1);			
	}

return 0;
}
