// Author: Gustavo Policarpo
// Name: Hard Day At Work
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1831

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

#define MAXV 100001
#define mod 1000000007
#define INF 0x3f3f3f3f


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, int > iii;


struct Triple{
	int d, x, y;
	Triple (int q, int w, int e):d(q), x(w), y(e){}
};
Triple egcd (int a, int b){
	if (!b) return Triple(a, 1, 0);
	Triple q = egcd(b, a%b);
	return Triple(q.d, q.y, q.x-a/b*q.y);
}
ll invMod (int a, int n){
	Triple t = egcd (a, n);
	if (t.d > 1) return 0;
	return (t.x%n+n)%n;
}

const int MAXN = 3;
int a[MAXN], m[MAXN];
ll crt(){
	ll M = 1, x = 0;
	for(int i = 0; i < MAXN; ++i)  M *= m[i];
	for(int i = 0; i < MAXN; ++i)
		x += a[i]*invMod(M/m[i], m[i])*(M/m[i]);
	return (((x%M)+M)%M);
}

int main(){
	
	int z=1;
	while(scanf("%d %d", &a[0], &m[0]) !=EOF){
		rep(i, 1, 3) scanf("%d %d", &a[i], &m[i]);
		
		ll ans=crt();
		if(ans==0) ans=m[0]*m[1]*m[2];
		
		printf("Caso #%d: %lld laranja(s)\n", z++, ans);
	}
	
	return 0;
	
}
