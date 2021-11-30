// Author: Gustavo Policarpo
// Name: Letras
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2457

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair <int, int> ii;

int main(){
	
	stringstream ss;
	char op;
	string s;
	
	cin >> op;
	getline(cin, s);
	getline(cin, s);
	
	int cnt=0, tt=0;
	ss << s;
	while(ss >> s){
		tt++;
		rep(i, 0, s.size()){
			if(s[i]==op){
				cnt++;
				break;
			}
		}
	}
	
	printf("%.1lf\n", double(cnt*100.0)/tt);
		
	
	
	return 0;
	
}
