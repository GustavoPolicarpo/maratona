// Author: Gustavo Policarpo
// Name: Olympic Games
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2244

#define gc getchar
#define pc(x) putchar(x);
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
#define EPS 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < double, ll > ii;
typedef pair < double, double > iii;

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

const ll LINF = 1LL << 55;

struct hux{
	int a, b;
	int id;
};
int n;
iii rh[100010], rc[100010];
vector <hux> h, c;
set <ii> H, C;
set <ii> :: iterator it;

double intersept(hux a, hux b){
	a.a-=b.a, b.b-=a.b;
	return double(b.b)/a.a;
}

int build_hux(){
	
	rep(i, 0, n+1) rh[i]=rc[i]=mp(-1.0, -1.0);
	
	H.insert(mp(-1.0, 0));
	rh[h[0].id].F=0.0,
	rh[h[0].id].S=LINF;
	
	rep(i, 1, n){
		it=H.end(), it--;
		ii au = *it;
		hux aux=h[au.S];
		if(h[i].a <= aux.a) continue;
		
		it=H.end(), it--;
		au = *it;
		aux=h[au.S];
		double cross = intersept(h[i], aux);
		while(cross <= au.F+EPS && cross>=-EPS){
			rh[h[au.S].id]=mp(-1, -1);
			H.erase(it); 
			it=H.end(), it--;
			au = *it, aux=h[au.S];
			cross = intersept(h[i], aux);
		}
		
		H.insert(mp(cross, i)),
		rh[h[au.S].id].S=cross,
		rh[h[i].id].F=cross,
		rh[h[i].id].S=LINF;
			
	}
	
	/*rep(i, 0, n){
		cout << rh[i].F << " " << rh[i].S << "\n";
	}*/
	
	C.insert(mp(-1.0, 0));
	rc[c[0].id].F=0.0,
	rc[c[0].id].S=LINF;
	
	rep(i, 1, n){
		it=C.end(), it--;
		ii au = *it;
		hux aux=c[au.S];
		if(c[i].a <= aux.a) continue;
		
		it=C.end(), it--;
		au = *it;
		aux=c[au.S];
		double cross = intersept(c[i], aux);
		while(cross <= au.F+EPS && cross>=-EPS){
			rc[c[au.S].id]=mp(-1, -1);
			C.erase(it); 
			it=C.end(), it--;
			au = *it, aux=c[au.S];
			cross = intersept(c[i], aux);
		}
		
		C.insert(mp(cross, i)),
		rc[c[au.S].id].S=cross,
		rc[c[i].id].F=cross,
		rc[c[i].id].S=LINF;
			
	}
	
	/*cout << "*--------------------*\n";
	
	rep(i, 0, n){
		cout << rc[i].F << " " << rc[i].S << "\n";
	}*/
	
	int ans=0;
	rep(i, 0, n){
		if(rc[i].F == -1 || rh[i].F == -1) continue;
		if(rc[i].S < rh[i].F + EPS || rc[i].F > rh[i].S - EPS) continue;
		if(rh[i].S < rc[i].F + EPS || rh[i].F > rc[i].S - EPS) continue;
		ans++;
	}
	
	return ans;
}


bool my_comp(hux a, hux b){
	return a.b!=b.b ? a.b>b.b : a.a>b.a;
}

int main()
{
	//freopen("in.txt", "r", stdin);
	
	scanint(n);
	
	hux hh, cc;
	
	rep(i, 0, n){
		scanint(hh.b),
		scanint(hh.a),
		scanint(cc.b),
		scanint(cc.a);
		cc.a*=-1, cc.b*=-1;
		
		hh.id=i;
		cc.id=i;
		h.pb(hh),
		c.pb(cc);
	}
	
	sort(h.begin(), h.end(), my_comp);
	sort(c.begin(), c.end(), my_comp);
	
	printf("%d\n", build_hux());

	return 0;
	
}
