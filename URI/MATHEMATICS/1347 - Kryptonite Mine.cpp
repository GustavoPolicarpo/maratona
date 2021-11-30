// Author: Gustavo Policarpo
// Name: Kryptonite Mine
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1347

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
/*#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>*/

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
//using namespace __gnu_pbds;
//using namespace __gnu_cxx;

//typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;




#define EPS 1e-9

inline int cmp( double x, double y = 0, double tol = EPS){
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}
int sgn(ll x) { return x < 0 ? -1 : x > 0; }

struct point{
	double x, y;
	void read(){ scanf("%lf %lf", &x, &y); }
	point(double x=0, double y=0): x(x), y(y){}
	point operator +(point q){ return point(x+q.x, y+q.y);}
	point operator -(point q){ return point(x-q.x, y-q.y);}
	point operator *(double t){ return point(x*t, y*t); }
	point operator /(double t){ return point(x/t, y/t); }
	point operator /(point q){ // divisao de num complexos
		return point(x*q.x+y*q.y, y*q.x-x*q.y)/q.norma2();
	}
	double norma2(){ return (*this)*(*this); } // |u|^2
	double operator *(point q){ return x*q.x+y*q.y; }
	double operator %(point q){ return x*q.y-y*q.x; }
	int cmp(point q) const{
	if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y, q.y);
	}
	bool operator == (point q) const{return cmp(q) == 0;};
	bool operator != (point q) const{return cmp(q) != 0;};
	bool operator < (point q) const{return cmp(q) < 0;};
};

ostream &operator<<(ostream &os, const point &p){
	os << "(" << p.x << "," << p.y << ")";
}

#define vec(a, b) (b-a)

int ccw(point p, point q, point r){
	return cmp(vec(p, q)%(vec(p, r)));
}

bool between(point p, point q, point r){
	return ccw(p, q, r)==0 && cmp((p-q)*(r-q))<=0;
}

bool seg_intersect(point a, point b, point c, point d){
	int d1, d2, d3, d4;
	d1 = ccw(c, a, d);    d2 = ccw(c, b, d);
	d3 = ccw(a, c, b);    d4 = ccw(a, d, b);
	if (d1*d2 == -1 && d3*d4 == -1) return true;
	if (d1 == 0 && between(c, a, d)) return true;
	if (d2 == 0 && between(c, b, d)) return true;
	if (d3 == 0 && between(a, c, b)) return true;
	if (d4 == 0 && between(a, d, b)) return true;
	return false;
}

int N, M, L, cnt;
vector <pair<int, double> > adj[250];
double dist[250][55];
bool istp[250];

double distance(point a, point b){
	return sqrt((a.x-b.x)*(a.x-b.x)+(a.y-b.y)*(a.y-b.y));
}

double dijkstra(int ini, int fim){
	priority_queue <pair<double, pair<int, int> > > pq;
	pq.push(mp(0, mp(ini, N))); dist[0][N] = 0;
	
	while(!pq.empty()){
		int u = pq.top().S.F, qt = pq.top().S.S; double c = -pq.top().F; pq.pop();
		
		if(u==fim) return c;
		
		rep(i, 0, adj[u].size()){
			int v = adj[u][i].F;
			double cc = adj[u][i].S;
			if(istp[u] && istp[v]){
				if(qt && dist[v][qt-1]>c){
					dist[v][qt-1] = c;
					pq.push(mp(-c, mp(v, qt-1)));
				}
			}else{
				if(dist[v][qt]>c+cc){
					dist[v][qt] = c+cc;
					pq.push(mp(-dist[v][qt], mp(v, qt)));
				}
			}
		}
	}
	
	return -1;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	
	while(scanf("%d %d %d", &N, &M, &L) and N+M+L){
		
		rep(i, 0, M*2+L+15){
			adj[i].clear();
			istp[i] = false;
			rep(j, 0, N+2)
				dist[i][j]=0x3f3f3f3f;
		}
		
		vector <pair<point, point> > wall; point a, b, ini, fim;
		vector <point> tele;
		
		rep(i, 0, M){
			a.read(), b.read();
			wall.pb(mp(a, b));
		}
		
		rep(i, 0, L){
			a.read();
			tele.pb(a);
		}
		
		ini.read(), fim.read();
		
		//ini para todas paredes
		rep(i, 0, M){
			bool y1 = true, y2 = true;
			rep(j, i+1, M){
				if(y1 && seg_intersect(ini, wall[i].F, wall[j].F, wall[j].S)) y1 = false;
				if(y2 && seg_intersect(ini, wall[i].S, wall[j].F, wall[j].S)) y2 = false;
				if(!y1 && !y2) break;
			}
			if(y1) adj[0].pb(mp(i*2+1, distance(ini, wall[i].F))), 
					adj[i*2+1].pb(mp(0, distance(ini, wall[i].F)));
			if(y2) adj[0].pb(mp(i*2+2, distance(ini, wall[i].S))),
					adj[i*2+2].pb(mp(0, distance(ini, wall[i].S)));
		}
		
		//ini para todos tp
		rep(i, 0, L){
			bool y = true;
			
			rep(j, 0, M){
				if(seg_intersect(ini, tele[i], wall[j].S, wall[j].F)){
					y = false;
					break;
				}
			}
			
			if(y) adj[0].pb(mp(i+1+M*2, distance(ini, tele[i]))),
					adj[i+1+M*2].pb(mp(0, distance(ini, tele[i])));
		}
		
		//paredes para todas paredes e todos tp
		rep(i, 0, M){
			rep(j, i+1, M){
				bool y1 = true, y2 = true, y3 = true, y4 = true;
				rep(k, 0, M){
					if(i==k || j==k) continue;
					if(y1 && seg_intersect(wall[i].F, wall[j].F, wall[k].F, wall[k].S)) y1 = false;
					if(y2 && seg_intersect(wall[i].F, wall[j].S, wall[k].F, wall[k].S)) y2 = false;
					if(y3 && seg_intersect(wall[i].S, wall[j].F, wall[k].F, wall[k].S)) y3 = false;
					if(y4 && seg_intersect(wall[i].S, wall[j].S, wall[k].F, wall[k].S)) y4 = false;
					if(!y1 && !y2 && !y3 && !y4) break;
				}
				if(y1) adj[i*2+1].pb(mp(j*2+1, distance(wall[i].F, wall[j].F))),
						adj[j*2+1].pb(mp(i*2+1, distance(wall[i].F, wall[j].F)));
				if(y2) adj[i*2+1].pb(mp(j*2+2, distance(wall[i].F, wall[j].S))),
						adj[j*2+2].pb(mp(i*2+1, distance(wall[i].F, wall[j].S)));
				if(y3) adj[i*2+2].pb(mp(j*2+1, distance(wall[i].S, wall[j].F))),
						adj[j*2+1].pb(mp(i*2+2, distance(wall[i].S, wall[j].F)));
				if(y4) adj[i*2+2].pb(mp(j*2+2, distance(wall[i].S, wall[j].S))),
						adj[j*2+2].pb(mp(i*2+2, distance(wall[i].S, wall[j].S)));
			}
			
			rep(j, 0, L){
				bool y1 = true, y2 = true;
				rep(k, 0, M){
					if(i==k) continue;
					if(y1 && seg_intersect(wall[i].F, tele[j], wall[k].F, wall[k].S)) y1=false;
					if(y2 && seg_intersect(wall[i].S, tele[j], wall[k].F, wall[k].S)) y2=false;
					if(!y1 && !y2) break;
				}
				if(y1) adj[i*2+1].pb(mp(j+1+M*2, distance(wall[i].F, tele[j]))),
						adj[j+1+M*2].pb(mp(i*2+1, distance(wall[i].F, tele[j])));
				if(y2) adj[i*2+2].pb(mp(j+1+M*2, distance(wall[i].S, tele[j]))),
						adj[j+1+M*2].pb(mp(i*2+2, distance(wall[i].S, tele[j])));
			}
			
		}
		
		//todos tp para todos tp
		rep(i, 0, L){
			rep(j, i+1, L){
				bool y = true;
				rep(k, 0, M){
					if(seg_intersect(tele[i], tele[j], wall[k].F, wall[k].S)){
						y = false;
						break;
					}
				}
				if(y) adj[i+1+M*2].pb(mp(j+1+M*2, 0.0)),
						adj[j+1+M*2].pb(mp(i+1+M*2, 0.0)),
							istp[i+1+M*2] = true,
							istp[j+1+M*2] = true;
			}
		}
		
		//fim para todas paredes
		rep(i, 0, M){
			bool y1 = true, y2 = true;
			rep(j, i+1, M){
				if(y1 && seg_intersect(fim, wall[i].F, wall[j].F, wall[j].S)) y1 = false;
				if(y2 && seg_intersect(fim, wall[i].S, wall[j].F, wall[j].S)) y2 = false;
				if(!y1 && !y2) break;
			}
			if(y1) adj[M*2+L+10].pb(mp(i*2+1, distance(fim, wall[i].F))), 
					adj[i*2+1].pb(mp(M*2+L+10, distance(fim, wall[i].F)));
			if(y2) adj[M*2+L+10].pb(mp(i*2+2, distance(fim, wall[i].S))),
					adj[i*2+2].pb(mp(M*2+L+10, distance(fim, wall[i].S)));
		}
		
		//fim para todos tp
		rep(i, 0, L){
			bool y = true;
			rep(j, 0, M){
				if(seg_intersect(fim, tele[i], wall[j].F, wall[j].S)){
					y = false;
					break;
				}
			}
			if(y) adj[M*2+L+10].pb(mp(i+1+M*2, distance(fim, tele[i]))),
					adj[i+1+M*2].pb(mp(M*2+L+10, distance(fim, tele[i])));
		}
		
		//ini para fim
		bool y = true;
		rep(i, 0, M){
			if(seg_intersect(ini, fim, wall[i].F, wall[i].S)){
				y = false;
				break;
			}
		}
		
		if(y) adj[0].pb(mp(M*2+L+10, distance(ini, fim)));
		
		double ans = dijkstra(0, M*2+L+10);
		int resp = round(ans);

		cout << resp << '\n';
		
	}
	
	return 0;
}

