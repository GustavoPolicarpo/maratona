// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Será Que Indiana Jones Ch...
// Nível: 6
// Categoria: GRAFOS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1402

#define gc getchar_unlocked
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
typedef pair < int, double > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/

const double EPS = 1e-9;

inline int cmp( double x, double y = 0, double tol = EPS) 
{ 
	return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1); 
}

struct ponto
{
	double x, y, disO;
	ponto() {}
	ponto(double x, double y) :x(x), y(y) {}
	ponto (ponto a, ponto b){
		x=(b.x-a.x); y=(b.y-a.y);
	}
	ponto operator +(ponto q){ return ponto(x+q.x, y+q.y); }
	ponto operator -(ponto q){ return ponto(x-q.x, y-q.y); }
	ponto operator *(double t){ return ponto(x*t, y*t); }
	ponto operator /(double t){ return ponto(x/t, y/t); }
	
	int cmp(ponto q) const{
		if(int t = ::cmp(x, q.x)) return t;
		return ::cmp(y,q.y);
	}
	bool operator == (ponto q) const { return cmp(q) == 0; };
	bool operator != (ponto q) const { return cmp(q) != 0; };
	bool operator < (ponto q) const { return cmp(q) < 0; };
	
	double operator *(ponto q){ return x*q.x + y*q.y; }
	double operator %(ponto q){ return x*q.y - y*q.x; }
};

typedef ponto vec;

double norma(vec u) 
{
	return sqrt(u*u); 
}
	
int ccw(ponto p, ponto q, ponto r)
{
	return cmp( vec(p,q) % vec(p,r) );
}
vec projecao(vec a, vec b)
{
	return b * ((a*b) / (b*b));
}

bool entre(ponto r, ponto p, ponto s)
{
	return cmp(vec(p,s)%vec(p,r))==0 &&
	cmp(vec(p,r)*vec(p,s)) <=0;
}

double PTSeg(ponto p, ponto a, ponto b)
{
	ponto pp= a + projecao(vec(a,p),vec(a,b));
	if(entre(a,pp,b)) return norma(p-pp);
	else return min(norma(a-p), norma(b-p));
}

bool intersect_seg(ponto a, ponto b, ponto c, ponto d)
{
	int d1, d2, d3, d4;
	d1 = ccw(a, c, d);		d2 = ccw(b, c, d);
	d3 = ccw(c, a, b);		d4 = ccw(d, a, b);
	
	if(d1*d2==-1 && d3*d4==-1) return true;
	if(d1==0 && entre(c,a,d)) return true;
	if(d2==0 && entre(c,b,d)) return true;
	if(d3==0 && entre(a,c,b)) return true;
	if(d4==0 && entre(a,d,b)) return true;
	
	return false;	
}

int N;
double dist[1001];
vector <ii> adj[1001];

double dij(int ini, int fim){
	priority_queue <iii> pq;
	pq.push(mp(0.0, ini)); dist[ini]=0.0;
	while(!pq.empty()){
		int u=pq.top().S; double w=-pq.top().F; pq.pop();
		//cout << u  << " " << w << endl;
		if(u==fim){
			return w;
			continue;
		}
		rep(i, 0, adj[u].size()){
			int v=adj[u][i].F;
			double c=adj[u][i].S;
			if(dist[v]<=max(dist[u], c)) continue;
			dist[v]=max(dist[u], c);
			pq.push(mp(-dist[v], v));
		}
	}
	return dist[fim];
}

typedef pair < ponto, ponto > seg;
int main()
{
	while(scanf("%d", &N) and N){
		rep(i, 0, N+1){
			dist[i]=INF;
			adj[i].clear();
		}
		vector <seg> in; ponto a, b;
		int u, v, l;
		rep(i, 0, N){
			scanf("%d %d %d", &u, &v, &l);
			a.x=u, a.y=v;
			if(l<0) b.x=u, b.y=v+abs(l);
			else 	b.x=u+l, b.y=v;
			in.pb(mp(a, b));
		} double dst;
		
		rep(i, 0, N)
		rep(j, i+1, N){
			if(intersect_seg(in[i].F, in[i].S, in[j].F, in[j].S)){
					dst=0.0;
				adj[i].pb(mp(j, dst)), adj[j].pb(mp(i, dst));
				continue;
			}
				dst=PTSeg(in[i].F, in[j].F, in[j].S);	
			adj[i].pb(mp(j, dst)), adj[j].pb(mp(i, dst));
				dst=PTSeg(in[i].S, in[j].F, in[j].S);
			adj[i].pb(mp(j, dst)), adj[j].pb(mp(i, dst));		
				dst=PTSeg(in[j].F, in[i].F, in[i].S);
			adj[i].pb(mp(j, dst)), adj[j].pb(mp(i, dst));
				dst=PTSeg(in[j].S, in[i].F, in[i].S);
			adj[i].pb(mp(j, dst)), adj[j].pb(mp(i, dst));
		}
		
		double out=dij(0, 1);
		
		printf("%.2lf\n", out);
	}
	
	
	        
return (0);	
}
