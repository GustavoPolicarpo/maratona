// Author: Gustavo Policarpo
// Name: Bacilli Population Growth
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1380

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 0x3F3F3F3F3F

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

struct Matriz{
	ll mat[2][2];
};

Matriz identidade; int vet[10000001], mod;

Matriz multiplica(Matriz A, Matriz B)
{
	Matriz C;
	rep(i, 0, 2)
		rep(j, 0, 2){
			C.mat[i][j]=0;
			rep(k, 0, 2)
				C.mat[i][j]=((C.mat[i][j]%mod+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod))%mod;
		}
	return C;
			
}
Matriz fastExp(Matriz base, ll p)
{
	if(p==0) return identidade;
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

int main()
{
	identidade.mat[0][1]=0, identidade.mat[1][0]=0; 
	rep(i, 0, 2) identidade.mat[i][i]=1;
	
	int x, aux; mod=1000; 
	x=2, vet[0]=1, vet[1]=1;
	while(1){
		vet[x]=( vet[x-1]%mod + vet[x-2]%mod )%mod;
		if(vet[x]%mod==1 && vet[x-1]%mod==1) break;
		x++;
	}	aux=x-1;
		
	//cout << aux << '\n';
	
	int T; cin >> T;
	
	while(T--){
		Matriz fib;
		
		fib.mat[0][0]=1, fib.mat[0][1]=1, 
		fib.mat[1][0]=1, fib.mat[1][1]=0;
		
		string in; cin >> in;
		reverse(in.begin(), in.end());
		
		ll peso=1, num=0;
		
		for(int i=0; i<in.size(); i++){
			num+=(in[i]-'0')*peso;
			peso*=10;
			peso%=aux;
		}
		
		//cout << num << '\n';
		fib=fastExp(fib, num);
		
		printf("%03lld\n", fib.mat[0][1]);
	}
	
			
return 0;
}
