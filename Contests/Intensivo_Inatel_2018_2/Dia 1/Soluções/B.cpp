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
	
	string s;
	int r = 0;
	while(cin >> s){
		rep(i, 0, s.size()){
			if(s[i]=='#'){
				if(r==0) puts("YES");
				else puts("NO");
				r = 0;
			}else{
				r = r*2;
				r = r+s[i]-'0';
				r = r%131071;
			}
		}
	}
	
	return 0;
} 
