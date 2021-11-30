// Author: Gustavo Policarpo
// Name: Penalidade Mínima
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2319

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>
#define _CRT_DISABLE_PERFCRIT_LOCKS

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
typedef pair < int, ii > iii;
typedef pair < iii, ii > iiii;

const ll mod = 1e9;
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

int N, vis[1010][1010][2]; ii mat[1010][1010];
vector <ii> vz[1010][1010];
int dx[]={0, 1}, dy[]={1, 0};

bool dentro(int x, int y){
	return x>=0 && x<N && y>=0 && y<N && mat[x][y]!=mp(-1, -1);
}
int solve(){
	priority_queue <iiii> pq;
	memset(vis, INF, sizeof vis);
	int aux=min(mat[0][0].F, mat[0][0].S);
	pq.push(mp(mp(-aux, mp(-mat[0][0].F+aux, -mat[0][0].S+aux)), mp(0, 0)));
	
	while(!pq.empty()){
		int x=pq.top().S.F, y=pq.top().S.S,
			cnt=-pq.top().F.F, a=-pq.top().F.S.F, b=-pq.top().F.S.S; pq.pop();
		
		//cout << x << " " << y << " " << cnt << " " << a << " " << b << '\n';
		if(x==N-1 && y==N-1) return cnt;
		
		int yep=1;
		rep(i, 0, vz[x][y].size()){
			if(vz[x][y][i].F <= a && vz[x][y][i].S <= b){
				yep=0;
				break;
			}
		}
		
		if(!yep) continue;
		vz[x][y].pb(mp(a, b));
		
		rep(i, 0, 2){
			int ax=x+dx[i], ay=y+dy[i];
			if(!dentro(ax, ay))	continue;
			int aa=mat[ax][ay].F+a, bb=mat[ax][ay].S+b;
			int ct=min(aa, bb);
			aa-=ct, bb-=ct;
			if(vis[ax][ay][(aa ? 0 : 1)]<ct+cnt) continue;
			vis[ax][ay][(aa ? 0 : 1)]=ct+cnt; 
			pq.push(mp(mp(-vis[ax][ay][(aa ? 0 : 1)], mp(-aa, -bb)), mp(ax, ay)));
		}
	}
	return 0;
}

ii build_cont(int n){
	if(n==0) return mp(-1, -1);
	int a=0, b=0;
	while(n%2==0) n/=2, a++;
	while(n%5==0) n/=5, b++;
	return mp(a, b);
}
int main()
{	
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
	int aux;
	scanint(N);
	rep(i, 0, N)
	rep(j, 0, N){
		scanint(aux);
		mat[i][j]=build_cont(aux);
	}
	
	printf("%d\n", solve());
	
	return 0;
	
}
