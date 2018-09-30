#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;

typedef long long ll;
typedef pair < ll, ll >  ii;


int control;
struct use{
	ll a, b, id; long double p;
	bool operator < ( const use o) const{
		if (control==0) {
			if(b!=o.b) return b > o.b;
			return a > o.a;
		}
		if (control==1) {
			if(p<=o.p) return true;
			return false;
		}
	}
	long double intersept(use o){
		return double(o.b-b)/(a-o.a);
	}
};

struct hux{
	set <use> st;
	
	bool cross(use a, use b, use c){
		return a.intersept(c) <= a.intersept(b);
		return (c.b-a.b)*(a.a-b.a) <= (b.b-a.b)*(a.a-c.a);
	}
	
	void add(use x){
		if(st.count(x)) return; st.insert(x); 
		set <use> :: iterator a, b, c;
		while(42){ //remove atual
			b = st.find(x); a = b, a--;
			if(b==st.begin()) break;
			if((*a).a >= (*b).a){ st.erase(b); return; }
			else break;	
		}
		while(42){ //remove posteriores
			b = st.find(x); c = b, c++;
			if(c==st.end()) break;
			if((*c).a <= (*b).a) st.erase(c);
			else break;
		}
		
		while(42){ //remove anteriores
			c = st.find(x); b = c, b--; a = b, a--;
			if(b==st.begin() || c==st.begin()) break;
			if(cross(*a, *b, *c)) st.erase(b);
			else break;
		}
		while(42){ //remove posteriores
			a = st.find(x); b = a, b++; c = b, c++;
			if(b==st.end() || c==st.end()) break;
			if(cross(*a, *b, *c)) st.erase(b);
			else break;
		}
		// concerta / (ou) remove o atual e o anterior
		b = st.find(x); c = b, c++;
		if(c==st.end()) x.p = 1e32;
		else x.p = x.intersept(*c);
		st.erase(b); st.insert(x);
		
		b = st.find(x); a = b, a--;
		if(b!=st.begin()){
			use aa = *a;
			aa.p = aa.intersept(*b);
			st.erase(a); st.insert(aa);
		}
		
		b = st.find(x); a = b, a--; c = b, c++;
		if(b==st.begin() || c==st.end()) return;
		if(cross(*a, *b, *c)){
			use aa = *a;
			aa.p = aa.intersept(*c);
			st.erase(a); st.insert(aa);
			b = st.find(x);
			st.erase(b);
		}
	}
	
	use query(long double p){
		control = 1;
		set <use> :: iterator it;
		it = st.lower_bound(use{0, 0, 0, p});
		use ret = *it;
		control = 0;
		return ret;
	}
	
	void debug(){
		set <use> :: iterator it;
		for(it = st.begin(); it!=st.end(); it++){
			use aux = *it;
			cout << aux.a << " " << aux.b <<  " " << aux.id << " " << aux.p << "\n";
		}
		puts("*******************");
	}
	
};


int main(){
	
	
}
