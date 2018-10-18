// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jogos Olímpicos
// Nível: 7
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2244

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair < ll, ll >  ii;


struct use{
	ll a, b, id;
	bool operator < ( const use o) const{
		if(b!=o.b) return b > o.b;
		return a > o.a;
	}
	double intersept(use o){
		return double(o.b-b)/(a-o.a);
	}
};

struct hux{
	set <use> st;
	
	bool cross(use a, use b, use c){
		return (c.b-a.b)*(a.a-b.a) <= (b.b-a.b)*(a.a-c.a);
	}
	
	
	void add(use x){
		if(st.count(x)) return;
		st.insert(x); 
		set <use> :: iterator a, b, c;
		while(42){
			b = st.find(x);	
			a = b, a--;
			if(b==st.begin()) break;
			if((*a).a >= (*b).a){
				st.erase(b);
				return;
			}
			break;
		}
		while(42){
			b = st.find(x);
			c = b, c++;
			if(c==st.end()) break;
			if((*c).a <= (*b).a){
				st.erase(c);
			}else{
				break;
			}
		}
		while(42){
			c = st.find(x);
			b = c, b--;
			a = b, a--;
			if(b==st.begin() || c==st.begin()) break;
			if(cross(*a, *b, *c)) st.erase(b);
			else break;
		}
		while(42){
			a = st.find(x);
			b = a, b++;
			c = b, c++;
			if(a==st.end() || b==st.end() || c==st.end()) break;
			if(cross(*a, *b, *c)) st.erase(b);
			else break;
		}
		b = st.find(x);
		a = b, a--;
		c = b, c++;
		if(b==st.begin() || b==st.end() || c==st.end()) return;
		if(cross(*a, *b, *c)) st.erase(b);
	}
	void debug(){
		set <use> :: iterator it;
		for(it = st.begin(); it!=st.end(); it++){
			use aux = *it;
			cout << aux.a << " " << aux.b <<  " " << aux.id << "\n";
		}
		puts("*******************");
	}
	
};

hux h, c;
pair<double, double>  rh[100010], rc[100010];

int main(){
	
	/*
	4 
	-9 -5 -6 3
	-2 -6 7 4 
	-10 10 4 1
	1 -6 6 -3
	*/
	
	int N; scanf("%d", &N);
	use hi, ci;
	
	rep(i, 0, N){
		hi.id = ci.id = i;
		scanf("%lld %lld %lld %lld", &hi.b, &hi.a, &ci.b, &ci.a);
		ci.b*=-1, ci.a*=-1;
		h.add(hi), c.add(ci);
		rh[i] = rc[i] = make_pair(-1, -1);
	}
	
	double last = 0;
	set <use> :: iterator it, ti;
	
	for(it=h.st.begin(); it!=h.st.end(); it++){
		ti = it; ti++;
		use a = *it, b = *ti;
		rh[a.id].F = last, rh[a.id].S = 1LL<<56;
		if(ti==h.st.end()) break;
		rh[a.id].F = last;
		last = a.intersept(b);
		rh[a.id].S = last;
		rh[b.id].F = last;
		rh[b.id].S = 1LL<<56;
	}
	
	last = 0;
	for(it=c.st.begin(); it!=c.st.end(); it++){
		ti = it; ti++;
		use a = *it, b = *ti;
		rc[a.id].F = last, rc[a.id].S = 1LL<<56;
		if(ti==c.st.end()) break;
		rc[a.id].F = last;
		last = a.intersept(b);
		rc[a.id].S = last;
		rc[b.id].F = last;
		rc[b.id].S = 1LL<<56;
	}
	
	int ans=0; double EPS = 1e-9;
	rep(i, 0, N){
		//cout << rh[i].F << " " << rh[i].S << " " << rc[i].F << " " << rc[i].S << "\n";
		if(rc[i].F == -1 || rh[i].F == -1) continue;
		if(rc[i].S < rh[i].F + EPS || rc[i].F > rh[i].S - EPS) continue;
		if(rh[i].S < rc[i].F + EPS || rh[i].F > rc[i].S - EPS) continue;
		ans++;
	}
	
	cout << ans << "\n";
	
	//h.debug();
	//c.debug();
	
	
}
