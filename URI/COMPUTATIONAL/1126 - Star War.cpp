// Author: Gustavo Policarpo
// Name: Star War
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1126

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

const double EPS=1e-9; 

inline int cmp(double a, double b = 0.0, double tol=EPS){
	return a+tol < b ? -1 : a-tol > b ? 1 : 0; 
}

struct pnt3d{
    double x, y, z;
    pnt3d(double x=0, double y=0, double z=0) : x(x), y(y), z(z){}
    pnt3d operator + (pnt3d q){ return pnt3d(x+q.x, y+q.y, z+q.z); }
    pnt3d operator - (pnt3d q){ return pnt3d(x-q.x, y-q.y, z-q.z); }
    pnt3d operator * (double d){ return pnt3d(x*d, y*d, z*d); }
    pnt3d operator / (double d){ return pnt3d(x/d, y/d, z/d); }
};
#define vec(A, B) (B - A)

double dot(pnt3d A, pnt3d B){
    return A.x*B.x + A.y*B.y + A.z*B.z;
}
pnt3d cross(pnt3d A, pnt3d B){
    return pnt3d(A.y*B.z - A.z*B.y, A.z*B.x - A.x*B.z, A.x*B.y - A.y*B.x);
}
double norma(pnt3d A){
    return sqrt(dot(A, A));
}
pnt3d project(pnt3d a, pnt3d B){ return B * dot(a, B) / dot(B, B); }

// Interseccao de segmentos (assumir que [A, B] e [C, D] sao coplanares)
bool seg_intersect(pnt3d A, pnt3d B, pnt3d C, pnt3d D){
    return cmp(dot(cross(A-B, C-B), cross(A-B, D-B))) <= 0 &&
    cmp(dot(cross(C-D, A-D), cross(C-D, B-D))) <= 0;
}

//  Distancia de ponto a segmento
double dist_point_seg(pnt3d P, pnt3d A, pnt3d B){
    pnt3d PP = A + project(P-A, B-A);
    if (cmp(norma(A-PP) + norma(PP-B), norma(A-B)) == 0) return norma(P-PP);//distance point-line!
    return min(norma(P-A), norma(P-B));
}


//  Distancia de segmento a segmento, lento*
double dist_seg_seg(pnt3d A, pnt3d B, pnt3d C, pnt3d D){
    pnt3d E = project(A-D, cross(B-A, D-C)); // distance between lines!
    if (seg_intersect(A, B, C+E, D+E)) return norma(E);
    return min(min(dist_point_seg(A, C, D), dist_point_seg(B, C, D)),
        min(dist_point_seg(C, A, B), dist_point_seg(D, A, B)));
}

#define dps dist_point_seg
//  Distancia de ponto a Triangulo, dps = dist_point_seg
double dist_point_tri(pnt3d P, pnt3d a, pnt3d B, pnt3d C){
	pnt3d N = cross(B-a, C-a);
	pnt3d PP = P - project(P-a, N);
	pnt3d R1, R2, R3;
	R1 = cross(B-a, PP-a);
	R2 = cross(C-B, PP-B);
	R3 = cross(a-C, PP-C);
    
	if (cmp(dot(R1, R2))>=0 && cmp(dot(R2, R3))>=0 && cmp(dot(R3, R1))>=0)
		return norma(P-PP);
 	else
		return min(dps(P, a, B), min(dps(P, B, C), dps(P, a, C)));
}

int main(){
	
	int T; cin >> T;
	
	while(T--){
		
		pnt3d a[4], b[4];
		
		rep(i, 0, 4) cin >> a[i].x >> a[i].y >> a[i].z;
		rep(i, 0, 4) cin >> b[i].x >> b[i].y >> b[i].z;
		
		double ans=1LL << 45;
		
		rep(i, 0, 4)
		rep(j, 0, 4){
			if(i==j) continue;
			rep(k, 0, 4)
			rep(l, 0, 4){
				if(k==l) continue;
				ans=min(ans, dist_seg_seg(a[i], a[j], b[k], b[l]));
			}
		}
		
		rep(i, 0, 4){
			ans=min(ans, dist_point_tri(a[i], b[0], b[1], b[2]));
			ans=min(ans, dist_point_tri(a[i], b[0], b[1], b[3]));
			ans=min(ans, dist_point_tri(a[i], b[0], b[2], b[3]));
			ans=min(ans, dist_point_tri(a[i], b[1], b[2], b[3]));
		}
		
		rep(i, 0, 4) swap(a[i], b[i]);
		
		rep(i, 0, 4){
			ans=min(ans, dist_point_tri(a[i], b[0], b[1], b[2]));
			ans=min(ans, dist_point_tri(a[i], b[0], b[1], b[3]));
			ans=min(ans, dist_point_tri(a[i], b[0], b[2], b[3]));
			ans=min(ans, dist_point_tri(a[i], b[1], b[2], b[3]));
		}
		
		cout << fixed << setprecision(2) << ans << '\n';
		
	}
	
	return 0;
	
}
