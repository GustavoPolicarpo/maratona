// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Fechadura
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2449

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
typedef pair < int, int > ii;
typedef pair < int, ii > iii;






int main()
{
	int n, m; cin >> n >> m;
	int v[n];
	rep(i, 0, n) scanf("%d", &v[i]);
	
	int ans=0;
	rep(i, 0, n){
		if(v[i]==m) continue;
		if(v[i]<m){
			v[i+1]+=m-v[i];
			ans+=m-v[i];
			v[i]+=m-v[i];
		}else{
			v[i+1]-=v[i]-m;
			ans+=v[i]-m;
			v[i]-=v[i]-m;
		}
	}
	
	printf("%d\n", ans);
	
	return 0;
	
}
