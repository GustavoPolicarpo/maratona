// Author: Gustavo Policarpo
// Name: Usernames
// Level: 9
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2549

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define repi(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define pi 3.1415926535897932384626433832795028841971
#define F first
#define S second
#define MAXV 200010

typedef long long ll;
typedef pair < int, int>  ii;
typedef pair < int, pair<int,int> >  iii;

// freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main(){
	
	int n, a;
	while(scanf("%d %d ", &n, &a)!=EOF){
		
		set <string> st; int ans=0;
		char s[101];
		rep(i, 0, n){
			gets(s);
			stringstream ss; string t;
			ss << s;
			while(ss >> s) t.pb(s[0]);
			
			if(st.count(t)) ans++;
			else st.insert(t);
			
		}
		
		printf("%d\n", ans);
		
	}
	
	
	return 0;
}

