// Author: Gustavo Policarpo
// Name: Counting Radars
// Level: 7
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2599

#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#define gc getchar
#define pc(x) putchar(x);

//LIFE IS NOT A PROBLEM TO BE SOLVED


int scanint()
{
    register int ccc = gc(); int x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    return x;
}


int pd[10010], v[1010];
int N, M;
const int mod=1000000007;

int solve(int n){
	
	if(n>=N) return 1;
	if(pd[n]!=-1) return pd[n];
	
	int ret=0, i;
	for( i=0; i<M; i++ ){
		ret+=solve(n+v[i]);
		if(ret>=mod) ret%=mod;
	}
	
	return pd[n]=ret;
	
}

int main(){
	
	int C=scanint();
	while(C--){
		
		
		N=scanint(), M=scanint(); int i;
		
		for( i=0; i<=N+2; i++ ) pd[i]=-1;
		for( i=0; i<M; i++ ) v[i]=scanint();
		
		printf("%d\n", solve(0));
		
	}
	
	return 0;
	
}
