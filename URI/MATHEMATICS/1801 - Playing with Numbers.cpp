// Author: Gustavo Policarpo
// Name: Playing with Numbers
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1801

#define gc getchar
#define pc(x) putchar(x);
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
typedef pair < int, char > ii;
typedef pair < int, ii > iii;




//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	
	ll in, ini, fim, cnt=0, aux; int n[10]; 
	memset(n, 0, sizeof n);
	scanf("%lld", &in);
	ini=sqrt(in), fim=sqrt(11*in);
	
	aux=in;
	while(aux){
		n[aux%10]++;
		aux/=10;
	}
	
	rep(i, ini, fim+1){
		aux=i; aux=aux*aux-in;
		//cout << aux << endl;
		int cmp[10]; memset(cmp, 0, sizeof cmp);
		while(aux>0){
			cmp[aux%10]++;
			aux/=10;
		}
		bool yep=true;
		rep(j, 0, 10){
			if(cmp[j]!=n[j]){
				yep=false;
				break;
			}
		}
		if(yep) cnt++;
	}
	
	printf("%lld\n", cnt);
	
	
	
	




return 0;
}



