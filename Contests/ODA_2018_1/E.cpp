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
	
	string a, b;
	cin >> a >> b;
	
	int fa[26], fb[26];
	memset(fa, 0, sizeof fa);
	memset(fb, 0, sizeof fb);
	
	rep(i, 0, a.size()) fa[tolower(a[i])-'a']++;
	rep(i, 0, b.size()) fb[tolower(b[i])-'a']++;
	
	bool yep = true;
	rep(i, 0, 26){
		if(i=='i'-'a' || i=='y'-'a') continue;
		if(fa[i]!=fb[i]) yep = false;
	}
	
	if(fb['y'-'a'] != fa['i'-'a']+fa['y'-'a'] || fb['i'-'a']) yep = false;
	
	if(yep) puts("Nomes escolhidos");
	else puts("Tentem novamente");	

	return 0;
}
