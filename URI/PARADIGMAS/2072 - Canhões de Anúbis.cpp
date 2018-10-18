// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Canhões de Anúbis
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2072

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

struct PT{ 
	double x, y, z; 
	PT(){x = y = z = 0;} 
	PT(double x,double y, double z):x(x), y(y), z(z){} 
	PT operator + (PT q){return PT(x+q.x,y+q.y,z+q.z);} 
	PT operator - (PT q){return PT(x-q.x,y-q.y,z-q.z);} 
	PT operator * (double d){ return PT(x*d, y*d, z*d); } 
	PT operator / (double d){ return PT(x/d, y/d, z/d); } 
	double dist2() const { return x*x+y*y+z*z; }
	double dist() const{ return sqrt(dist2()); }
	bool operator == (const PT& a) const{ 
		return fabs(x - a.x) < EPS && fabs(y - a.y) < EPS && fabs(z - a.z) < EPS; 
	}
	bool operator < (PT q) const{
		if(x!=q.x) return x<q.x;
		if(y!=q.y) return y<q.y;
		return z<q.z;
	};
	
};

double dot(PT A, PT B){ // produto escalar
	return A.x*B.x + A.y*B.y + A.z*B.z;
}

PT cross(PT A, PT B){ // produto vetorial 
	return PT (A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x ); 
}

void planeFromPts(PT p1, PT p2, PT p3, double& a, double& b, double& c, double& d){ 
	PT normal = cross(p2-p1, p3-p1);
	a = normal.x; b = normal.y; c = normal.z; 
	d = -a*p1.x-b*p1.y-c*p1.z; 
}

bool collinear(PT A, PT B, PT C){
	PT AB = A-B, BC = B-C;
	if(AB.x*BC.y==AB.y*BC.x && AB.x*BC.z==AB.z*BC.x && AB.y*BC.z==AB.z*BC.y) return true;
	return false;
}

int main()
{
	
	srand(time(NULL));
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	
	while(T--){
		
		int N; cin >> N;
		PT aux; vector <PT> v;
		
		rep(i, 0, N){
			cin >> aux.x >> aux.y >> aux.z;
			v.pb(aux);
		}
		
		if(v.size()<=3){
			cout << N << '\n';
			continue;
		}
		
		
		int ans = 0;
		rep(i, 0, v.size()){
			rep(j, i+1, v.size()){
				if(v[i]==v[j]) continue;
				PT B = v[i], C = v[j];
				while(1){
					aux.x = rand(), aux.y = rand(), aux.z = rand();
					if(collinear(v[i], v[j], aux)) continue;
					v.pb(aux);
					break;
				}
				rep(k, j+1, v.size()){
					if(v[k]==v[i] || v[k]==v[j]) continue;
					double a, b, c, d;
					if(collinear(v[i], v[j], v[k])) continue;
					planeFromPts(v[i], v[j], v[k], a, b, c, d);
					int aux = 0;
					rep(l, 0, v.size()-1){
						double xx = a*v[l].x + b*v[l].y + c*v[l].z + d;
						if(fabs(xx)<EPS)
							aux++;
					}
					ans = max(ans, aux);
				}
				v.pop_back();
			}
		}
		
		cout << ans << '\n';
		
	}


	return 0;
}

