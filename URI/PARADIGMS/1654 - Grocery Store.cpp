// Author: Gustavo Policarpo
// Name: Grocery Store
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1654

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
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < double, double > ii;
typedef pair < ii, ii > iii;


vector <iii> out;
int main()
{
	for(double i=0.1; i<20.0; i+=0.01){
		for(double j=i; j<20.0; j+=0.1){
			if(i+j>20.0 || i*j>20.0) break;
			for(double k=j; k<20.0; k+=0.1){
				if(i+j+k>20.0 || i*j*k>20.0) break;
				for(double l=k; l<20.0; l+=0.1){
					if(i+j+k+l>20.0 || i*j*k*l>20.0) break;
					if( fabs(i+j+k+l - i*j*k*l) < error)
						out.pb(mp(mp(i, j), mp(k, l)));
				}
			}
		}
	}
	
	rep(i, 0, out.size()){
		printf("%.2lf %.2lf %.2lf %.2lf\n", 
				out[i].F.F, out[i].F.S, 
				out[i].S.F, out[i].S.S);
	}
	
    return 0;
}
