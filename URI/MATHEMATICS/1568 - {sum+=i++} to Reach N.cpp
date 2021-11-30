// Author: Gustavo Policarpo
// Name: {sum+=i++} to Reach N
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1568

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
typedef pair < double, int > iii;

#define MAX 30000000  //MAXIMO VALOR

vector <ull> primos;

bool isprime[30000005];
ll prime[30000005];
ull lim = MAX;

int main()
{
	primos.pb(2);
	memset(isprime, true, sizeof(isprime));
	for(ull i=3; i<=lim; i+=2) if(isprime[i]) {
		primos.pb(i);
		
		for(ull j=i*i; j<=lim; j+=i){
			isprime[j] = false;
		}
	}
	
	ull N;
	while(cin >> N){
		ull aux=N, out=1;
		int j=0, cont=0;
		while(aux>1){
			cont=0;
			while(aux%primos[j]==0){
				aux/=primos[j];
				cont++;
			}
			j++;
			if(j!=1)
				out*=(cont+1);
			if(j==primos.size()){
				out*=2;
				break;
			}
		}
		cout << out << endl;
	}
	
return 0;
}


