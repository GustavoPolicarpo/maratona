// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Autopotencial
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2505

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int MAX=1000010;

#define mod 1000000

ll fast_pow(int b, int e)
{			
	if(e==0) return 1;
	ll go=fast_pow(b,e/2);
	go=(go*go)%mod;
	if(e&1) go=(go*b)%mod;
	return go;	
}


int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N;
	while(scanf("%d", &N) !=EOF){
		ll aux=fast_pow(N, N), num=N, yep=1;
		while(num){
			if(aux%10 != num%10){
				puts("NAO");
				yep=0;
				break;
			}
			aux/=10, num/=10;
		}
		
		if(yep) puts("SIM");
		
	}
	
	return 0;
	
}
