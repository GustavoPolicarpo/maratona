// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Jogo Reverse
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2512

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

const ll mod = 1e9+7;
const ull MAX = mod*mod*2;
const int INF = 0x3f3f3f3f;

void scanint(ll &x){
    register ll ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}

char mat[5][5];

void read(){
	char aux; int i=0, j=0;
	while(1){
		scanf("%c", &aux);
		if(aux=='*' || aux=='-'){
			mat[i][j++]=aux;
			if(j==3){
				i++;
				j=0;
				if(i==3) break;
			}
		}
	}
}

void build(string &ret){
	ret.clear();
	rep(i, 0, 3) rep(j, 0, 3) ret.pb(mat[i][j]);
}

bool check(string u){
	char cmp=u[0];
	rep(i, 0, 9) if(u[i]!=cmp) return false;
	
	return true;
}

int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<3 && y<3;
}

void my_swap(int x, int y){
	mat[x][y]=='-' ? mat[x][y]='*' : mat[x][y]='-';
}

string change(string u, int x, int y){
	int p=0;
	rep(i, 0, 3) rep(j, 0, 3) mat[i][j]=u[p++];
	
	my_swap(x, y);
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay)) continue;
		my_swap(ax, ay);
	}
	
	build(u);
	return u;
}

int solve(){
	
	set <string> vis; string aux, u;
	build(aux); vis.insert(aux);
	queue < pair <string, int> >q;
	q.push(mp(aux, 0));
	
	while(!q.empty()){
		
		u=q.front().F; int ret=q.front().S; q.pop();
		//cout << u << '\n';
		
		if(check(u)) return ret;
		
		rep(i, 0, 3)
		rep(j, 0, 3){
			aux=change(u, i, j);
			if(vis.count(aux)) continue;
			vis.insert(aux);
			q.push(mp(aux, ret+1));
		}
		
	}
	
	return INF;
	
}
int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int R; cin >> R; int a=0, b=0, aa, bb;
	
	rep(z, 0, R){
		
		read(), aa=solve();
		read(), bb=solve();
		
		if(aa < bb) a++;
		else if(bb < aa) b++;
		
		//cout << aa << " " << bb << "\n";
		
	}
	
	if(a > b) puts("Fred wins!");
	else if(b > a) puts("Jason wins!");
	else puts("Its a draw!");
	
	return 0;
	
}
