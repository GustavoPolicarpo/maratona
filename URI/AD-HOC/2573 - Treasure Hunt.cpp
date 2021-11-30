// Author: Gustavo Policarpo
// Name: Treasure Hunt
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2573

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;

 
#define EPS 1e-9
 
inline int cmp(double x, double y=0, double tol=EPS){
    return ( ( x<=y+tol ) ? (x+tol<y) ? -1 : 0 : 1);
}
 
struct ponto{
     
    double x, y;
    ponto () {}
     
    ponto(double x, double y) : x(x), y(y) {}
    ponto(ponto a, ponto b){
        x=(b.x-a.x);
        y=(b.y-a.y);
    }
     
    ponto operator +(ponto q) { return ponto(x+q.x, y+q.y); }
    ponto operator -(ponto q) { return ponto(x-q.x, y-q.y); }
    ponto operator *(double t) { return ponto(x*t, y*t); }
    ponto operator /(double t) { return ponto(x/t, y/t); }
     
    int cmp(ponto q) const{
        if(int t= ::cmp(x, q.x)) return t;
        return ::cmp(y, q.y);
    }
         
    bool operator == (ponto q) const { return cmp(q)==0; };
    bool operator < (ponto q) const { return cmp(q)<0; };
     
    double operator *(ponto q) { return x*q.x + y*q.y; }
    double operator %(ponto q) { return x*q.y - y*q.x; }
 
};
 
typedef ponto vec;
typedef vector<ponto> poligono;
 
double Area(poligono T){
    double ret=0.0;
    T.pb(T[0]);
    rep(i, 0, T.size()-1){
        ret+=(T[i]%T[i+1]);
    }
    return fabs(ret)/2.0;
}
 
int ccw(ponto p, ponto q, ponto r){
    return cmp( vec(p, q) % vec(p, r) );
}
 
 
ponto li(ponto p, ponto q, ponto r, ponto s){
    ponto a=q-p, b=s-r, c=ponto(p%q, r%s);
    if(a%b==0) return ponto(INF, INF);
    return ponto(ponto(a.x, b.x)%c, ponto(a.y, b.y)%c)/(a%b);
}
 
 
ponto l0, l1, l2, l3, A, B, center, p1;
 
bool dentro(ponto a, ponto b){
    return a.x>=0 && a.y>=0 && a.x<=b.x && a.y<=b.y;
}
 
 
ponto pivot;
bool radial_lt(ponto a, ponto b){
    int r=ccw(pivot, a, b);
    if(r==0) return (pivot-a)*(pivot-a)<(pivot-b)*(pivot-b);
    else return r==1;
}
poligono resp, la, lb;
 
int main(){
 
    cin >> l3.x >> l3.y;
    l0.x=l0.y=0.0;
    l1.x=l3.x, l1.y=0.0;
    l2.x=0.0, l2.y=l3.y;
 
    cin >> A.x >> A.y;
    cin >> B.x >> B.y;
 
    center=ponto( (A.x+B.x)/2.0, (A.y+B.y)/2.0 );
 
    double a=0.0;
     
    if(A.x==B.x){
        p1.x=center.x+10.0;
        p1.y=center.y;
    }else if(A.y==B.y){
        p1.x=center.x;
        p1.y=center.y+10.0;
    }
    else{
        a=(A.y-B.y)/(A.x-B.x);
        a=-1.0/a;
        p1.x=center.x+10;
        p1.y=center.y+10*a;
    }
     
    double At=(l3.x*l3.y);
    ponto aux;
     
    aux=li(center, p1, l0, l1);
    if(dentro(aux, l3)) resp.pb(aux), la.pb(aux), lb.pb(aux);
     
    aux=li(center, p1, l0, l2);
    if(dentro(aux, l3)) resp.pb(aux), la.pb(aux), lb.pb(aux);
     
    aux=li(center, p1, l1, l3);
    if(dentro(aux, l3)) resp.pb(aux), la.pb(aux), lb.pb(aux);
     
    aux=li(center, p1, l2, l3);
    if(dentro(aux, l3)) resp.pb(aux), la.pb(aux), lb.pb(aux);
     
    if(ccw(center, p1, l0)==-1){
        la.pb(l0);
    }else if(ccw(center, p1, l0)==1){
        lb.pb(l0);
    }else{
    	la.pb(l0), lb.pb(l0);
    }
    
    if(ccw(center, p1, l1)==-1){
        la.pb(l1);
    }else if(ccw(center, p1, l1)==1){
        lb.pb(l1);
    }else{
    	la.pb(l1), lb.pb(l1);
    }
    
    if(ccw(center, p1, l2)==-1){
        la.pb(l2);
    }else if(ccw(center, p1, l2)==1){
        lb.pb(l2);
    }else{
    	la.pb(l2), lb.pb(l2);
    }
    
    if(ccw(center, p1, l3)==-1){
        la.pb(l3);
    }else if(ccw(center, p1, l3)==1){
        lb.pb(l3);
    }else{
    	la.pb(l3), lb.pb(l3);
    }
     
    sort(la.begin(), la.end());
        pivot=la[0];
        sort(++la.begin(), la.end(), radial_lt);
    sort(lb.begin(), lb.end());
        pivot=lb[0];
        sort(++lb.begin(), lb.end(), radial_lt);
     
    /*rep(i, 0, la.size()){
        debugP(la[i]);
    }
     
    rep(i, 0, lb.size()){
        debugP(lb[i]);
    }*/
    
    if(ccw(center, p1, A)==1) swap(la, lb);
    cout << fixed << setprecision(6);
    cout << Area(la)/At << " " << Area(lb)/At << '\n';
     
     
    return 0;
     
     
}
