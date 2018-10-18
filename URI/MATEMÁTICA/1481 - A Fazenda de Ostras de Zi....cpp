// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Fazenda de Ostras de Zi...
// Nível: 7
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1481

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;

void scanint(ull &x){
    register ull ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

struct ina{
	int x1, y1, x2, y2, h;
};

int mat[2222][2222];

int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<2222 && y<2222 && !mat[x][y];
}

int bfs(int x, int y){
	
	queue <ii> q; q.push(mp(x, y)); mat[x][y]=1; int ret=1;
	
	while(!q.empty()){
		x=q.front().F, y=q.front().S; q.pop();
		
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			ret++, mat[ax][ay]=1;
			q.push(mp(ax, ay));
		}
	}
	
	return ret;
	
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N;
	
	while(scanf("%d", &N) and N){
		
		vector <ina> v; ina in;
		rep(i, 0, N){
			scanf("%d %d %d %d %d", &in.x1, &in.y1, &in.x2, &in.y2, &in.h);
			in.x1+=501, in.y1+=501, in.x2+=501, in.y2+=501;
			in.x1*=2, in.y1*=2, in.x2*=2, in.y2*=2;
			v.pb(in);
		}
		
		int mare; scanf("%d", &mare);
		memset(mat, 0, sizeof mat);
		
		rep(i, 0, N){
			in=v[i];
			if(in.h < mare) continue;
			rep(i, in.x1, in.x2+1) mat[i][in.y1]=1;
			rep(i, in.x2, in.x1+1) mat[i][in.y1]=1;
			rep(i, in.y1, in.y2+1) mat[in.x1][i]=1;
			rep(i, in.y2, in.y1+1) mat[in.x1][i]=1;
		}
		
		bfs(0, 0);
		
		for(int i=0; i<2222; i+=2){
			for(int j=0; j<2222; j++)
				mat[i][j]=1;
		}
		
		for(int i=0; i<2222; i+=2){
			for(int j=0; j<2222; j++)
				mat[j][i]=1;
		}
		
		/*rep(i, (-25+501)*2, (25+501)*2){
			cout << '\n';
			rep(j, (-25+501)*2, (25+501)*2)
				cout << mat[i][j];
		}*/
		
		int ans=0;
		rep(i, 0, 2222){
			rep(j, 0, 2222){
				if(!mat[i][j]){
					ans++;
				}
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
