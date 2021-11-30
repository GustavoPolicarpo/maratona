// Author: Gustavo Policarpo
// Name: Tribol
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1875

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int gol(char a, char b)
{
	if(a=='B'){
		if(b=='R')
			return 2;
		return 1;				
	}
	if(a=='R'){
		if(b=='G')
			return 2;
		return 1;				
	}
	if(a=='G'){
		if(b=='B')
			return 2;
		return 1;				
	}
}
int main()
{
	
	int C; cin >> C;
	while(C--){
		int P; scanf("%d", &P);
		char f, l;
		int G=0, R=0, B=0;
		while(P--){
			scanf(" %c  %c", &f, &l);
			if(f=='G')
				G+=gol(f, l);
			else if(f=='R')
				R+=gol(f, l);
			else
				B+=gol(f, l);			
		}
		if(G==R && G==B) printf("trempate\n");
		else{
			if(G>R && G>B) printf("green\n");
			else if(B>R && B>G) printf("blue\n");
			else if(R>B && R>G) printf("red\n");
			else  printf("empate\n");	
		}	
	}
	
return 0;
}
