// Author: Gustavo Policarpo
// Name: The Ekaterinburg Pyramids
// Level: 5
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2107

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
int sgn(double x){ 
	return (x > EPS) - (x < -EPS); 
}

#define vec(ini, fim) (fim - ini) 
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
};
		
double dot(PT A, PT B){ // produto escalar 
	return A.x*B.x + A.y*B.y + A.z*B.z; 
}

PT cross(PT A, PT B){ // produto vetorial 
	return PT (A.y*B.z-A.z*B.y, A.z*B.x-A.x*B.z, A.x*B.y-A.y*B.x ); 
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	PT A, B, C, D, X, u, v, w, p, q;
	double pw, qw;
	
	while(cin >> A.x >> A.y >> A.z){
		cin >> B.x >> B.y >> B.z;
		cin >> C.x >> C.y >> C.z;
		cin >> D.x >> D.y >> D.z;
		cin >> X.x >> X.y >> X.z;
		
		string s;
		
		u = C-B, v = D-B;
		w = cross(u, v);
		p = X-B, q = A-B;
		
		pw = dot(p, w);
		if(pw==0.0) s.pb('N');
		else{
			pw/=fabs(pw);
			qw = dot(q, w);
			qw/=fabs(qw);
			if(pw==qw) s.pb('N');
			else s.pb('S');
		}
		
		/****************/
		
		u = D-C, v = A-C;
		w = cross(u, v);
		p = X-C, q = B-C;
		
		pw = dot(p, w);
		if(pw==0.0) s.pb('N');
		else{
			pw/=fabs(pw);
			qw = dot(q, w);
			qw/=fabs(qw);
			if(pw==qw) s.pb('N');
			else s.pb('S');
		}
		
		/****************/
		
		u = A-D, v = B-D;
		w = cross(u, v);
		p = X-D, q = C-D;
		
		pw = dot(p, w);
		if(pw==0.0) s.pb('N');
		else{
			pw/=fabs(pw);
			qw = dot(q, w);
			qw/=fabs(qw);
			if(pw==qw) s.pb('N');
			else s.pb('S');
		}
		
		/****************/
		
		u = B-A, v = C-A;
		w = cross(u, v);
		p = X-A, q = D-A;
		
		pw = dot(p, w);
		if(pw==0.0) s.pb('N');
		else{
			pw/=fabs(pw);
			qw = dot(q, w);
			qw/=fabs(qw);
			if(pw==qw) s.pb('N');
			else s.pb('S');
		}
		
		cout << s << '\n';
		
		
	}
	
	
	return 0;
}

