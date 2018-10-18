// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Jaida e o Jogo Multiplica...
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1697

#include <bits/stdc++.h>
 
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
#define mod 1000000007
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 
 #define MAX 20000000
vector <ll> primos;
vector <int> eh(MAX, 1);
void crivo(){

	primos.pb(1);
	
	for(ll i=2; i<=sqrt(MAX); i++){
		if(eh[i]==1){
			primos.pb(i);
			for(int j=i+i; j<MAX; j+=i)
				eh[j]=0;
		}
	}
	
	for(ll i=sqrt(MAX)+1; i<MAX; i++)
		if(eh[i]==1)
			primos.pb(i);
	
	return;
}


int main(){
	crivo();
	int T; cin >> T;
	while(T--){
		int N; cin >> N; int n[N];
		rep(i, 0, N) scanf("%d", &n[i]);
		sort(n, n+N); int i=0, j=0, ans=0;
		
		while(1){
			while(n[i] < primos[j]) i++;
			
			if(n[i]==primos[j]) j++;
			else{
				ans=primos[j]-1;
				break;
			}
		}
		printf("%d\n", ans);
	}
	
	return 0;
	
}

