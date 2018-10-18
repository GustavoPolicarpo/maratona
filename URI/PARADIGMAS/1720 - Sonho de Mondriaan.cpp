// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Sonho de Mondriaan
// Nível: 8
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1720

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

int H, W;
ll pd[12][12][1<<12];

ll solve(int i, int j, int mask){
	
	if(i>=H) return solve(0, j+1, mask);
	if(j==W) return mask==0;
	if(pd[i][j][mask]!=-1) return pd[i][j][mask];
	
	ll ret=0;
	if(mask&(1<<i)){
		ret+=solve(i+1, j, mask^(1<<i));
	}else{
		ret+=solve(i+1, j, mask|(1<<i));
		if(i<H-1 && !(mask&(1<<(i+1)))) ret+=solve(i+2, j, mask);
	}

	return pd[i][j][mask]=ret;
	
}


int main(){
	
	while(scanf("%d %d", &H, &W) and H+W){
		
		memset(pd, -1, sizeof pd);
		cout << solve(0, 0, 0) << '\n';
		
	}

	return 0;
	
}
