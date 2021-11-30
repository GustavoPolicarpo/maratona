// Author: Gustavo Policarpo
// Name: Xing Tzen Zu’s Movie Theater
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2100

#include<bits/stdc++.h>

using namespace std;

typedef long long int ll;
#define mod 1300031
ll fat[40001];

ll fastExp(ll num,int base)
{
	ll x;
	
	if(base==0) return 1;	
	if(base==1) return num;

	if(base%2==0){
		x = fastExp(num,base/2)%mod;
		return (x*x)%mod;
	}
	else{
		return (num*fastExp(num,base-1))%mod;
	}
}

ll inverso(ll a)
{
  return fastExp(a,mod-2);
  //funciona para mod primo
}

ll combina_completa(ll n, ll k)
{   // de quantos modos pode comprar 11 sorvetes em 
	// uma loja que oferece 4 sabores diferentes. R 364
   ll num, den, ret;
   num = fat[n+k-1];
   
   den = (fat[k] * fat[n - 1]) % mod;
   den = inverso(den);
   
   ret = (num * den) % mod;

   return ret;
}

ll combina_simples(ll n, ll k)
{	//A megassena consiste em uma cartela de 60
	//numeros dentre os quais devemos acertar 6
	ll num, den, ret;
	num = fat[n];
	
	den= (fat[k] * fat[n - k]) % mod;
	
	den = inverso(den);
   
	ret = (num * den) % mod;

	return ret;
}

int main()
{
	fat[0]=1;
	for(int i=1; i<=4000; i++)
		fat[i]=(fat[i-1]*i)%mod;
	
	int T, n, k; cin >> T;
	while(T--){
		cin >> n >> k;
		ll out=(((combina_simples(n-k, k)*fat[k])%mod)*fastExp(2, k))%mod;
		cout << out << endl;
	}	

return 0;
}
