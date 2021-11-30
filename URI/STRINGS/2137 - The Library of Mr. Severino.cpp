// Author: Gustavo Policarpo
// Name: The Library of Mr. Severino
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2137

#include<bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
using namespace std;
 
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second
 
#define INF 0x3F3F3F3F
#define MAXV 100001
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	int N; string in;
	while(scanf("%d", &N) !=EOF){
		vector <string> out;
		rep(i, 0, N){
			cin >> in;
			out.pb(in);
		}
		sort(out.begin(), out.end());
		rep(i, 0, out.size()){
			cout << out[i] << '\n';
		}
	}
	
	

	
	
return 0;
}
