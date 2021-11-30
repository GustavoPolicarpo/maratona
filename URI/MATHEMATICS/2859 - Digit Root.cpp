// Author: Gustavo Policarpo
// Name: Digit Root
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2859

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;




int fs(string t){
	int s = 0;
	rep(i, 0, t.size()) s+=t[i]-'0';
	if(s<10) return s;
	t.clear();
	while(s){
		t.pb(s%10+'0');
		s/=10;
	}
	return fs(t);
}


int vis[10];
int main(){
	
	string B, E;
	cin >> B >> E;
	
	memset(vis, -1, sizeof vis);
	int ans = 1, b = fs(B), t = 1, r = 0;
	while(42){
		if(vis[ans]!=-1){
			r = t-1;
			t = t-vis[ans];
			break;
		}
		vis[ans] = t++;
		ans = ans*b; string s;
		while(ans) s.pb(ans%10+'0'), ans/=10;
		ans = fs(s);
	}
	
	int e = 0;
	if(E.size()>3){
		rep(i, 0, E.size()){
			e = (e*10)%t;
			e = (e+E[i]-'0')%t;
		}
		e = (e - r%t);
		while(e<0) e+=t;
		e = (e+r);
	}else{
		rep(i, 0, E.size()){
			e = (e*10);
			e = (e+E[i]-'0');
		}
	}
	
	
	//cout << e << " " << b << " " << r << " " << t << "\n";
	
	ans = 1;
	rep(i, 0, e){
		ans = ans*b;
		string s;
		while(ans) s.pb(ans%10+'0'), ans/=10;
		ans = fs(s);
	}
	
	cout << ans << '\n';
	
	
	
	return 0;
}  
