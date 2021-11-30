// Author: Gustavo Policarpo
// Name: Drought
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1023

//SPOJ submission 17268823 (C++ 5) plaintext list. Status: WA, problem MINIMO, contest SPOJBR. By policarpo (LzPolicarpo), 2016-07-12 13:31:05.
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
typedef pair < int, ii > iii;
 

 
int main()
{
	int N, z=1, cons[201], total, qt, x, y;
	while(scanf("%d", &N) and N){
		total=0, qt=0; memset(cons, 0, sizeof cons);
		
		while(N--){
			scanf("%d %d", &x, &y);
			cons[y/x]+=x, qt+=x, total+=y;
		}
		
		if(z>1) printf("\n");
		printf("Cidade# %d:\n", z++);
		bool mark=false;
		rep(i, 0, 201){
			if(cons[i]>0){
				if(mark) printf(" ");
				else mark=true;
				printf("%d-%d", cons[i], i);
			}
		}
		double out=double(total)/double(qt);
		int aux=floor(out*100);
		out=aux/100.0;
		printf("\nConsumo medio: %.2lf m3.\n", out);
	}
				
return 0;
} 
