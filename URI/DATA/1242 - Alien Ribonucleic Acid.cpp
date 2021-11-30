// Author: Gustavo Policarpo
// Name: Alien Ribonucleic Acid
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1242

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define f(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(c) c.begin(), c.end() 

typedef pair<int, int> ii;
typedef pair<pair<double, int>, ii> iii;
typedef unsigned long long int ll;

bool go(char a, char b){
	if( (a=='B' && b=='S') || (b=='B' && a=='S') ) return true;	
	if( (a=='C' && b=='F') || (b=='C' && a=='F') ) return true;
	return false;
}

int main()
{
	
	string s;
	while(cin >> s){
		
		stack<char> st; int ans=0;
		
		rep(i, 0, s.size()){
			if(!st.empty() && go(st.top(), s[i])){
				ans++;
				st.pop();
			}else{
				st.push(s[i]);
			}
		}
		
		cout << ans << '\n';
		
	}

	return 0;
	
}
