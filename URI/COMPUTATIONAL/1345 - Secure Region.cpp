// Author: Gustavo Policarpo
// Name: Secure Region
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1345

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair < int, int > ii;
typedef pair < ii, int > iii;

const int INF = 0x3f3f3f3f;

ii ponto[305];

inline bool my_comp1(ii a, ii b){
	return a.F!=b.F ? a.F<b.F : a.S<b.S;
}
inline bool my_comp2(ii a, ii b){
	return a.F!=b.F ? a.F<b.F : a.S>b.S;
}

int a, b, N;
ii li, ls;

void solve(){
	
	rep(i, 0, N){
			
		ii ref=ponto[i]; 
		int ls1, ls2, ls3, ls4, li1, li2, li3, li4;
		ls1=ls2=ls3=ls4=ls.S, li1=li2=li3=li4=li.S;
		
		rep(j, i+1, N){
			
			ii at=ponto[j];
			
			int aa=at.F-ref.F, bb=ls1-li1;
			if(aa>bb) swap(aa, bb);
			if(aa>a) a=aa, b=bb;
			else if(aa==a) b=max(b, bb);
			
			if(at.F>ref.F){
				if(at.S<ls1){
					ls1=at.S;
				}
			}
		
			aa=at.F-ref.F, bb=ls2-li2;
			if(aa>bb) swap(aa, bb);
			if(aa>a) a=aa, b=bb;
			else if(aa==a) b=max(b, bb);
			
			if(at.F>ref.F){
				if(at.S<ref.S && at.S>li2){
					li2=at.S;
				}else if(at.S>ref.S && at.S<ls2){
					ls2=at.S;
				}else if(at.S==ref.S){
					if(at.S>li2) li2=at.S;
					if(at.S<ls3) ls3=at.S;
				}
			}
			
			aa=at.F-ref.F, bb=ls3-li3;
			if(aa>bb) swap(aa, bb);
			if(aa>a) a=aa, b=bb;
			else if(aa==a) b=max(b, bb);
			
			if(at.F>ref.F){
				if(at.S<ref.S && at.S>li3){
					li3=at.S;
				}else if(at.S>ref.S && at.S<ls3){
					ls3=at.S;
				}else if(at.S==ref.S){
					if(at.S>li2) li2=at.S;
					if(at.S<ls3) ls3=at.S;
				}
			}
			
			aa=at.F-ref.F, bb=ls4-li4;
			if(aa>bb) swap(aa, bb);
			if(aa>a) a=aa, b=bb;
			else if(aa==a) b=max(b, bb);
		
			if(at.F>ref.F){
				if(at.S>li4){
					li4=at.S;
				}
			}
			
		}
		
	}
	
	return;
	
}

int main(){
	
	while(scanf("%d %d %d %d", &ponto[0].F, &ponto[0].S, &ponto[1].F, &ponto[1].S)){
		if(ponto[0].F==0 && ponto[0].S==0 && ponto[1].F==0 && ponto[1].S==0) break;
		
		a=0, b=0, N; cin >> N; N+=2; li=ponto[0], ls=ponto[1];
		rep(i, 2, N) scanf("%d %d", &ponto[i].F, &ponto[i].S);
		
		
		sort(ponto, ponto+N, my_comp1); solve();
		sort(ponto, ponto+N, my_comp2); solve();
		
		rep(i, 0, N) swap(ponto[i].F, ponto[i].S); swap(li.F, li.S), swap(ls.F, ls.S);
		
		sort(ponto, ponto+N, my_comp1); solve();
		sort(ponto, ponto+N, my_comp2); solve();
		
		printf("%d %d\n", a, b);
		
	}
	
	return 0;
	
}
