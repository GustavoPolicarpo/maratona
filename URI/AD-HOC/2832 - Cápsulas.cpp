// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Cápsulas
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2832

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
 


int C[100010];

int main(){
	
	int N, F; scanf("%d %d", &N, &F);
	rep(i, 0, N) scanf("%d", &C[i]);
	
	int ini = 1, fim = 100000000, mid, ans;
	while(ini<=fim){
		mid = (ini+fim)/2;
		ll sum = 0;
		rep(i, 0, N) sum+=mid/C[i];
		if(sum>=F){
			ans = mid;
			fim = mid-1;
		}else{
			ini = mid+1;
		}
	}
	
	printf("%d\n", ans);
	
	
	
	return 0;
}  
