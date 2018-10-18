// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cash Roial
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2595

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


char mat[1010][1010];
int dx[]={-1, -1, -1, 0, 0, 1, 1, 1}, dy[]={-1, 0, 1, -1, 1, -1, 0, 1};

int main(){
	
	int C=scanint();
	while(C--){
		
		int N=scanint(), M=scanint(), P=scanint(), i;
		
		for( i=0; i<N; i++ ) gets(mat[i]);
		
		while(P--){
			int x=scanint(), y=scanint(), cnt=0; x--, y--;
			for( i=0; i<8; i++ ){
				int ax=x+dx[i], ay=y+dy[i];
				if(ax>=0 && ay>=0 && ax<N && ay<M && mat[ax][ay]=='T') cnt++;
			}
			
			if(cnt>=5) puts("GRRR");
			else puts("GG IZI");
		}
		
	}
}
