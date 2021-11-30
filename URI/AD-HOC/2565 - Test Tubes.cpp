// Author: Gustavo Policarpo
// Name: Test Tubes
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2565

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

#define EPS 1e-4

int main()
{

	int n;
	while(scanf("%d", &n)!=EOF){
		
		double v[101]; rep(i, 0, n) scanf("%lf", &v[i]);
		
		double ans=INF, ini=0.0, fim=101.0; int cnt=100;
		
		while(cnt--){
			
			double l=(ini*2+fim)/3;
			double r=(ini+fim*2)/3;
			
			double m1=0.0, m2=0.0;
			rep(i, 0, n) m1+=fabs(v[i]-l);
			rep(i, 0, n) m2+=fabs(v[i]-r);
			
			if(m1<=m2) ans=m1, fim=r;
			else ans=m2, ini=l;
			
		}
		
		printf("%.2lf\n", ans);
		
		
	}

	return 0;
	
}
