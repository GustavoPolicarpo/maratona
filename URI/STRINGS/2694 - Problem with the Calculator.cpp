// Author: Gustavo Policarpo
// Name: Problem with the Calculator
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2694

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;


int main(){
	
	int T; scanf("%d", &T);
	char s[20];
	
	while(T--){
		scanf("%s", s);
		ll ans = 0, num = 0;
		rep(i, 0, 14){
			if(isdigit(s[i])) num*=10, num+=s[i]-'0';
			else{
				ans+=num;
				num=0;
			}
		}	ans+=num;
		printf("%lld\n", ans);
	}
	
		
	return 0;
}
