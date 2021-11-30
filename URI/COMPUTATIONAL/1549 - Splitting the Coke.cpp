// Author: Gustavo Policarpo
// Name: Splitting the Coke
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1549

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define m_pi 3.1415926535897932384626433832795028841971
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;

double N, L, r, R, H, h, A, B, C, V;

double achah(double k, double me, double MA)
{
	double v=0;
	while(1){
		v=A*k + B*k*k + C*k*k*k;
		//cout << v << "  " << V << endl;
		//cout <<fixed << setprecision(5) <<  me << " " << MA  << " " << k << endl;
		if(V-v<0.000001&&V-v>0.0) break;
		else if(v < V){
			me=k;
			k=k+MA/2.0;
		}
		else{
			MA=k;
			k=(k+me)/2.0;
		}	
	}
	return k;	
}

int main()
{
	int T; cin >> T;
	while(T--){
		
		cin >> N >> L >> r >> R >> H;
		
		V=L/N/m_pi;
		A=r*r;
		B=(r*(R-r))/H;
		C=((R-r)*(R-r))/(3.0*H*H);
		
		double k=H/2.0+0.001;
		
		h = achah(k, 0.001, H);
		
		cout << fixed << setprecision(2) << h << endl;
				
	}	
return (0);
}
