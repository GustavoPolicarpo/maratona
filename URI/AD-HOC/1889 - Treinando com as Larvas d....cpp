// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Treinando com as Larvas d...
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1889

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
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


double area(double a, double b, double c){
	//cout << a << " " << b << " " << c << '\n';
	double sp=(a+b+c)/2.0;
	return sp*(sp-a)*(sp-b)*(sp-c);
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	
	while(T--){
		int N; cin >> N;
		double n[N];
		
		rep(i, 0, N) scanf("%lf", &n[i]);
		sort(n, n+N);
		
		double ans=INF;
		rep(i, 0, N-2){
			rep(j, i+1, N-1){
				int p=lower_bound(n+j+1,n+N, n[i]+n[j]) -n;
				if(p==N || n[p]>=n[i]+n[j]) p--;
				if(p==j) continue;
				
				double auxc=area(n[i], n[j], n[p]);
				if(auxc>10*ans) continue;
				ans=min(ans, auxc);
				
				int k=p-1;
				while(1){
					if(k==j) break;
					double aux=area(n[i], n[j], n[k]);
					//if(aux<auxc) cout << i << " " << j << " " << k << " " << aux << " " << auxc << '\n';
					if(aux>auxc) break;
					ans=min(ans, aux), k--;
				}
			}
		}
		
		if(ans>=INF-error) printf("-1\n");
		else printf("%.2lf\n", sqrt(ans));
		
	}

}
