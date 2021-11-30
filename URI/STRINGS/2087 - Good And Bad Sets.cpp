// Author: Gustavo Policarpo
// Name: Good And Bad Sets
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2087

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef pair < int, int > ii;



//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int sig[1000010][30], term[1000010], yep, cnt;

inline int C( char c ){
	return c - 'a';
}

void add( string s ){
	int x = 0, yaya=1;
	
	rep( i, 0, s.size() ){		
		int c = C( s[i] );
		if( !sig[x][c] ){
			yaya=0;
			term[cnt] = 0; 								
			sig[x][c] = cnt++;
			cnt%=100000;							
		}
		x = sig[x][c];
		if(term[x]) yep=0;
	}
	
	if(yaya) yep=0;
	term[x] = 1;									
}

int main()
{
	int n;
	while(scanf("%d", &n)){
		
		if(!n) break;
		
		cin.ignore();
		
		char s[101]; yep=1, cnt=1;
		rep(i, 0, n){
			gets(s);
			add(s);
		}
		
		yep ? puts("Conjunto Bom") : puts("Conjunto Ruim");
		
		rep(i, 0, cnt+2){
			term[i]=0;
			rep(j, 0, 28)
				sig[i][j]=0;
		}
		
	}

	return 0;
	
}
