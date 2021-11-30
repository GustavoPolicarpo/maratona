// Author: Gustavo Policarpo
// Name: The Mathematician
// Level: 3
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2691

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F

typedef long long int ll;
typedef pair < int, int > ii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int N; cin >> N;
	while(N--){
		int a, b;
		scanf("%dx%d", &a, &b);
		if(a==b){
			rep(i, 5, 11){
				printf("%d x %d = %d\n", a, i, a*i);
			}
		}else{
			rep(i, 5, 11){
				printf("%d x %d = %d && %d x %d = %d\n", a, i, a*i, b, i, b*i);
			}
		}
	}
	

	return 0;
	
}
