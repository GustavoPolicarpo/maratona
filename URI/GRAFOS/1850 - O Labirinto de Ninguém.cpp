// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Labirinto de Ninguém
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1850

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

char lab[150][150];
int L=0, C=0;
int vis[150][150][260];
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};
set <char> gate;
set <char> key;

struct pt{
	int x, y, k, d;
};

bool dentro(int x, int y)
{
	if(lab[x][y]=='#') return false;
	return x>=0&&y>=0&&x<L&&y<C;
}

void bfs(pt u)
{
	queue <pt> q;
	q.push(u);
	int x, y, k, d, ax, ay;
	while(!q.empty()){
		x=q.front().x;	y=q.front().y;
		k=q.front().k;	d=q.front().d;
		q.pop();
		rep(i, 0, 4){
			ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay)) continue;
			if(vis[ax][ay][k]==1) continue;
			char aux=lab[ax][ay];
				//cout << aux << endl;
			if(aux=='.'){
				u.x=ax, u.y=ay, u.d=d+1, u.k=k;
				vis[u.x][u.y][u.k]=1;
				q.push(u);
			}
			else if(aux=='@'){
				u.x=ax, u.y=ay, u.d=d+1, u.k=k;
				vis[u.x][u.y][u.k]=1;
				q.push(u);
			}
			else if(key.count(aux)){
				u.x=ax, u.y=ay, u.d=d+1, u.k=k|(1<<(aux-'a'));
				vis[u.x][u.y][u.k]=1;
				q.push(u);
			}
			else if(gate.count(aux)){
				if(k&(1<<(aux-'A'))){	
					u.x=ax, u.y=ay, u.d=d+1, u.k=k;
					vis[u.x][u.y][u.k]=1;
					q.push(u);
				}
			}
			else if(lab[ax][ay]=='*'){
				cout << d+1 << endl;
				return;
			}
		}
		
	}
	
	cout << "--" << endl;
	return;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	
	rep(i, 'a', 'h'+1)
		key.insert(i);
	rep(i, 'A', 'H'+1)
		gate.insert(i);
		
	char ina, inb; pt ini; string in;
	while(cin >> in){
		C=0;
		rep(i, 0, in.size()){
			if(in[i]=='@')
				ini.x=L, ini.y=C;
			lab[L][C++]=in[i];		
		}
		L++;
	}
	
	memset(vis, 0, sizeof(vis));
	
	ini.k=0, ini.d=0;
	
	/*cout << L << " " << C << endl;
	rep(i, 0, L){
		rep(j, 0, C)
			cout << lab[i][j] << " ";
		cout << endl;
	}*/
	
	bfs(ini);
		
return 0;
}

