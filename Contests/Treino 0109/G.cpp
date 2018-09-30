#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;



int main(){
	
	string s; cin >> s;
	vector <int> p[2];
	rep(i, 0, s.size()){
		if(s[i]=='A') p[0].pb(i);
		else p[1].pb(i);
	}
	
	int pa=0, pb=0, yep = 1;
	while(pa!=p[0].size() && pb!=p[1].size()){
		if(p[1][pb]<p[0][pa]){
			yep = 0;
			break;
		}
		pa++, pb++;
	}
	
	if(yep && pa==p[0].size() && pb==p[1].size()){
		puts("Sim");
	}else{
		puts("Nao");
	}
	
	

	return 0;
} 
