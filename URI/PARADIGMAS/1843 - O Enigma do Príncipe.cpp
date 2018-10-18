// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Enigma do Príncipe
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1843

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, M;
set < string > vis;
vector <char> chek;
set <char> chekk;

int visz[4][5], dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0}, cnt;

struct nn{
	char mat[4][5]; int t;
};

bool dentro(int x, int y){
	return x>=0 && y>=0 && x<N && y<M;
}

void check(int x, int y, nn atual){
	
	if(visz[x][y]) return;
	cnt++;
	visz[x][y]=1;
	
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		if(!dentro(ax, ay) || visz[ax][ay]) continue;
		
		if(atual.mat[ax][ay]==atual.mat[0][0]) check(ax, ay, atual);
		else if(!chekk.count(atual.mat[ax][ay])){
			chekk.insert(atual.mat[ax][ay]);
			chek.pb(atual.mat[ax][ay]);
		}
	}
	
	return;
	
}

nn color( nn atual , char nova, char velha){
 	memset(visz, 0, sizeof visz);
	
	int x=0, y=0;
	queue <ii> q; q.push(mp(x, y)); visz[x][y]=1;
	atual.mat[0][0]=nova;
	
	while(!q.empty()){
		x=q.front().F, y=q.front().S; q.pop();
		
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			
			if(!dentro(ax, ay) || visz[ax][ay]) continue;
			
			visz[ax][ay]=1;
			
			if(atual.mat[ax][ay]==nova){
				q.push(mp(ax, ay));
			}
			else if(atual.mat[ax][ay]==velha){
				atual.mat[ax][ay]=nova;
				q.push(mp(ax, ay));
			}
		}
	}
	
	/*rep(i, 0, N){
		rep(j, 0, M)
			cout << atual.mat[i][j] << " ";
		cout << '\n';
	}*/
		
	atual.t++;
	
	return atual;
	
}

int brute_force(nn u){
	
	queue < nn > q;
	q.push(u); string aux="";
	rep(i, 0, N) rep(j, 0, M) aux+=u.mat[i][j];
	vis.insert(aux);
	
	while(!q.empty()){
		u=q.front(); q.pop();
		
		chek.clear(); chekk.clear(); cnt=0;
		memset(visz, 0, sizeof visz);
		
		check(0, 0, u);
		if(cnt==N*M){
			/*aux="";
			rep(i, 0, N) rep(j, 0, M) aux+=u.mat[i][j];
			cout << aux << '\n';*/
			return u.t;
		}
		
		rep(i, 0, 10){
			nn use=color(u, i+'0', u.mat[0][0]);
			
			aux="";
			rep(i, 0, N) rep(j, 0, M) aux+=use.mat[i][j];
			
			//cout << aux << '\n';
			if(vis.count(aux)) continue;
			vis.insert(aux);
			q.push(use);
		}
		
	}
	
	return -1;
	
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	cin >> N >> M;
	
	nn in;
	
	rep(i, 0, N)
	rep(j, 0, M)
		cin >> in.mat[i][j];
	in.t=0;
		
	printf("%d\n", brute_force(in));
	
	return 0;
	
}
