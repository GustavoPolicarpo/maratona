// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Mercearia
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1654

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
#define error 1e-3

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < double, double > ii;
typedef pair < ii, ii > iii;


vector <iii> out;
int main()
{
	rep(i, 1, 2000){
		rep(j, i, 2000){
			if(i+j+j+j > 2000) break;
			rep(k, j, 2000){
				if(i+j+k+k > 2000) break;
				ll sum=(i + j + k) * 1e6, prod=(i*j*k) - 1e6;
				
				if(prod <=0 || sum%prod !=0) continue;
				
				int l=sum/prod;
				
				if(l<k || i+j+k+l > 2000) continue;
				out.pb(mp(mp(i/100.0, j/100.0), mp(k/100.0, l/100.0)));
			}
		}
	}
	
	rep(i, 0, out.size()){
		printf("%.2lf %.2lf %.2lf %.2lf\n", 
				out[i].F.F, out[i].F.S, 
				out[i].S.F, out[i].S.S);
	}
	
	//cout << out.size() << '\n';

	return 0;
	
}
