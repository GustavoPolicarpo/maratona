// Author: Gustavo Policarpo
// Name: Shortest Path
// Level: 
// Category: COMPUTATIONAL
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2773

#include <bits/stdc++.h>

#define rep(i, a, b) for (int i = int(a); i < int(b); i++)
#define pb push_back

// freopen("in.txt", "r", stdin);
// freopen("out.txt", "w", stdout);

using namespace std;

typedef long long ll;
typedef pair < int, int >  ii;

int main(){
	
	ll xi, yi, xf, yf, v, xl, yl, xr, yr;    
    while(cin>>xi>>yi>>xf>>yf>>v>>xl>>yl>>xr>>yr){
    	double ini1 = sqrt((xl-xi)*(xl-xi)+(yl-yi)*(yl-yi));
    	double ini2 = sqrt((xl-xi)*(xl-xi)+(yr-yi)*(yr-yi));
    	double meio = xr-xl;
    	double fim1 = sqrt((xr-xf)*(xr-xf)+(yl-yf)*(yl-yf));
    	double fim2 = sqrt((xr-xf)*(xr-xf)+(yr-yf)*(yr-yf));
    	double ans = min(ini1+meio+fim1, ini2+meio+fim2);
    	printf("%.1lf\n", ans/v);
    	
	}
	
}

