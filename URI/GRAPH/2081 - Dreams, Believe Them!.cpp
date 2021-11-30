// Author: Gustavo Policarpo
// Name: Dreams, Believe Them!
// Level: 10
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2081

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

struct pt{
	int x, y;
};

struct robo{
	pt A, B;
	int mov;
};
int dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

int vis[51][51][51][51];
char m1[51][51];
char m2[51][51];
int N, M;

bool isvalido(pt a, pt b)
{
	return a.x>=0&&a.y>=0 && a.x<N&&a.y<M &&
		   b.x>=0&&b.y>=0 && b.x<N&&b.y<M &&
		   			m1[a.x][a.y]!='B'	  &&
		   			m2[b.x][b.y]!='B'
		   					;
					   		   							   		
}
pt ra, rb, a, b; robo R, aux; int mov;
void solve()
{
	rep(i, 0, N)
		rep(j, 0, M)
			rep(k, 0, N)
				rep(l, 0, M)
					vis[i][j][k][l]=0;
					
	queue <robo> qr;
	R.A=ra, R.B=rb, R.mov=0;
	qr.push(R);
	
	while(!qr.empty()){
		aux = qr.front(); qr.pop();
		ra=aux.A, rb=aux.B, mov=aux.mov;
		if(m1[ra.x][ra.y]=='F' && m2[rb.x][rb.y]=='F'){
			cout << mov << endl;
			return;
		}
		if(mov>50) break;
		rep(i, 0, 4){
			a.x=ra.x+dx[i], b.x=rb.x+dx[i];
			a.y=ra.y+dy[i], b.y=rb.y+dy[i];
				
			if(!isvalido(a, b)) continue;
			
			
			if(m1[a.x][a.y]!='#')
				R.A=a;
			else
				R.A=ra;
			
			if(m2[b.x][b.y]!='#')
				R.B=b;
			else
				R.B=rb;
			
			R.mov=mov+1;
			
			if(vis[R.A.x][R.A.y][R.B.x][R.B.y]==1) continue;
			vis[R.A.x][R.A.y][R.B.x][R.B.y]=1;
				qr.push(R);
			
		}
	}
	cout << "impossivel" << endl;
	return;		
}

int main()
{
	int T; cin >> T;
	while(T--){
		cin >> N >> M;
		rep(i, 0, N)
			rep(j, 0, M){
				scanf(" %c", &m1[i][j]);
				if(m1[i][j]=='R')
					ra.x=i, ra.y=j;
			}
		rep(i, 0, N)
			rep(j, 0, M){
				scanf(" %c", &m2[i][j]);
				if(m2[i][j]=='R')
					rb.x=i, rb.y=j;
			}
		solve();
	}
		
return 0;
}
