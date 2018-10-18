// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Números Casal-Solteirão-S...
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1535

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

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string s;
	while(getline(cin, s)){
		
		if(!s.size()) continue;
		
		stringstream ss;
		ss << s;
		
		int ct=0, op=1, yep=0; ll n1, n2, i;
		ss >> n1;
		if(ss >> n2) ct=1;		
		
		
		if(ct==1){
			ll a=0, b=0;
			if(n1>0) n1--;
			else if(n2<0) n2++;
			
			if(n1<=0) a=(n1-2)/4; else a=(n1+2)/4;
			if(n2<=0) b=(n2-2)/4; else b=(n2+2)/4;
			printf("%lld\n", b-a);
			continue;
		}
		
		
		if(n1<0) op=-1, n1=-n1;	ll aux=sqrt(n1);
		if(aux*aux==n1){
			ll a=aux, b=0;
			if(op==-1) swap(a, b);
			printf("%lld %lld\n", a, b);
			continue;
		}
		
		for(i=aux; i>=1; i--){
			if(n1%i==0 && (i+n1/i)%2==0){
				yep=1;
				ll a=(n1/i+i)/2, b=(n1/i-i)/2;
				//if(a*a - b*b!=n1) cout << "deuruim\n";
				if(op==-1) swap(a, b);
				printf("%lld %lld\n", a, b);
				break;
			}
		}
		
		if(!yep){
			if(n1&1) puts("Spinster Number.");
			else puts("Bachelor Number.");
		}
		
		
	}
	
	return 0;
	
}
