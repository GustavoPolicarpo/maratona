// Author: Gustavo Policarpo
// Name: Coming Input and Output
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2765

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define pb push_back
#define F first
#define S second

using namespace std;

typedef pair<int, int> ii;



int main(){
	
	string s; getline(cin, s);
	rep(i, 0, s.size()){
	    if(s[i]==',') cout << '\n';
	    else{
	        cout << s[i];
	    }
	}   cout << '\n';
	
    return 0;
}
