// Author: Gustavo Policarpo
// Name: LED Panel
// Level: 6
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2292

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N, fim; ll qt; scanf("%d", &N); char s[60];
	
	while(N--){
		scanf("%s %lld", s, &qt); fim=strlen(s);
		
		rep(i, 0, fim){
			if(!qt) break;
			if(qt&1){
				qt/=2;
				if(s[i]=='X') s[i]='O';
				else s[i]='X', qt++;
			}else{
				qt/=2;
			}
		}
		printf("%s\n", s);
	}
	
	return 0;
	
}
