// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Defendendo Alamo
// Nível: 3
// Categoria: GEOMETRIA COMPUTACIONAL
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2045

#include <bits/stdc++.h>
using namespace std;
 
#define rep(i,a,b) for(int i(a); i < (b); i++)
 
#define all(c) c.begin(), c.end()
#define UNIQUE(c) { sort(all(c); (c).resize( unique(all(c))-c.begin() ); }
#define pb push_back
 
#define D(x) if(1) cout << __LINE__ <<" "<< #x " = " << (x) << endl;
#define D2(x,y) cout << #x " = " << x << "  " << #y " = " << y << endl;
#define DVEC(v,n) {cout<<#v<<"[] ={ "; rep(i,0,n) cout<<v[i]<<" "; cout << "}\n";}
 
#define mp make_pair
#define fst first
#define snd second
 
typedef pair<int,int> ii;
typedef long long ll;
 
const int INF = 0x3f3f3f3f;
const double EPS = 1e-11;
 
 
inline int cmp( double x, double y = 0, double tol = EPS) {
    return ( (x <= y + tol) ? (x + tol < y) ? -1 : 0 : 1);
}
 
struct point{
    double x, y;
    point(double x=0, double y=0): x(x), y(y){}
    void read(){
        scanf("%lf %lf", &x, &y);
    }
    point operator +(point q){ return point(x+q.x, y+q.y); }
    point operator -(point q){ return point(x-q.x, y-q.y); }
    point operator *(double t){ return point(x*t, y*t); }
    point operator /(double t){ return point(x/t, y/t); }
     
    double operator *(point q){ return x*q.x + y*q.y; }
    double operator %(point q){ return x*q.y - y*q.x; }
     
    int cmp(point q) const{
        if(int t = ::cmp(x, q.x)) return t;
        return ::cmp(y,q.y);
    }
    bool operator == (point q) const { return cmp(q) == 0; };
    bool operator != (point q) const { return cmp(q) != 0; };
    bool operator < (point q) const { return cmp(q) < 0; };
     
    friend ostream& operator <<(ostream& o, point p) {
        return o << "(" << p.x << ", " << p.y << ")";
    }
 
};
typedef vector<point> polygon;
#define vec(a,b) (b-a)
/* modulo de um vetor = sqrt(ux*ux + uy*uy) */
double norma(point u) {
    return sqrt(u*u);
}
 
int ccw(point p, point q, point r) {
    return cmp(vec(p,q) % (vec(q,r)));
}
 
point project(point a, point b) {
    return b * ((a*b) / (b*b));
}
 
bool between(point p, point q, point r){
    return ccw(p, q, r) == 0 && cmp(vec(q, p) * vec(q, r)) <= 0;
}
 
double angle(point p, point q, point r){
    point u = vec(q, p), v = vec(q, r);
    return atan2((u % v), (u * v));
}
 
/*
    Verificando ponto em rela??o a pol?gono
    Funciona independentemente da orienta??o do pol?gono
    -1 borda, 0 fora, 1 dentro
*/
int in_poly(point p, polygon& T) {
    double a = 0; int N = T.size();
    rep(i, 0, N){
        if (between(T[i], p, T[(i + 1)%N])) return -1;
        a += angle(T[i], p, T[(i + 1)%N]);
    }
    return cmp(a) != 0;
}

int main(){
	
	int N, Q, z=1; point aux;
	
	while(scanf("%d", &N) and N){
		
		polygon T;
		
		rep(i, 0, N) aux.read(), T.pb(aux);
		aux.read();
		
		int flag = in_poly(aux, T);
		//cout << flag << '\n';
		
		printf("Instancia %d\n", z++);
		scanf("%d", &Q);
		rep(i, 1, Q+1){
			aux.read();
			int p = in_poly(aux, T);
			//cout << p << '\n';
			if(flag == 1){
				if(p==1 || p==-1) printf("soldado %d defender\n", i);
				else printf("soldado %d espanhol\n", i);
			}
			if(flag == 0){
				if(p==0 || p==-1) printf("soldado %d defender\n", i);
				else printf("soldado %d espanhol\n", i);
			}
			if(flag == -1){
				if(p==1) printf("soldado %d defender\n", i);
				else printf("soldado %d espanhol\n", i);
			}
		}
		
		printf("\n");
		
	}
	
	return 0;
}
