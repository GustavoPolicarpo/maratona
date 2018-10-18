// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pro Habilidade
// Nível: 1
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2337

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;

int N; ll pd[40][2][2];

ll solve(int p, int last, int yep){
	if(p==N) return yep;
	if(pd[p][last][yep]!=-1) return pd[p][last][yep];
	
	ll ret=0;
	if(last){
		ret+=solve(p+1, 0, yep) + solve(p+1, 1, 1);
	}else{
		ret+=solve(p+1, 0, yep) + solve(p+1, 1, yep);
	}
	
	
	return pd[p][last][yep]=ret;
}


int main (){
	
	//freopen("in.txt", "r", stdin);
	
	
	while(scanf("%d", &N) != EOF){
		
		memset(pd, -1, sizeof pd);
		ll proo=solve(0, 0, 0);
		ll total=pow(2, N);
		
		ll comon = __gcd(proo, total);
		proo/=comon, total/=comon;
		
		ll num=total-proo, dem=total;
		
		printf("%lld/%lld\n", num, dem);
		
	}
			
	return 0;
	
}
