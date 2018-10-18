// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Parafusos e Porcas
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1520

#include <bits/stdc++.h>
using namespace std;
#define rep(i, a, b) for(int i=a; i<b; i++)

int v[100010];

int main(){
	
	
	int N;
	
	while(scanf("%d", &N) !=EOF){
		
		int a, b, cnt=0;
		rep(i, 0, N){
			scanf("%d %d", &a, &b);
			rep(j, a, b+1)
				v[cnt++]=j;
		}
		
		sort(v, v+cnt);
		
		int num; scanf("%d", &num);
		
		int ini=0, fim=cnt-1, mid, left=-1, right=-1;
		
		while(ini<=fim){
			
			mid=(ini+fim)/2;
			
			if(v[mid]>=num){
				if(v[mid]==num) left=mid;
				fim=mid-1;
			}else{
				ini=mid+1;
			}
			
		}
		
		ini=0, fim=cnt-1;
		
		while(ini<=fim){
			
			mid=(ini+fim)/2;
			
			if(v[mid]>num){
				fim=mid-1;
			}else{
				if(v[mid]==num) right=mid;
				ini=mid+1;
			}
			
		}
		
		if(left==-1) printf("%d not found\n", num);
		else printf("%d found from %d to %d\n", num, left, right);
		
	}
	
	return 0;
	
}
