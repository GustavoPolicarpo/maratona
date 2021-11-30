// Author: Gustavo Policarpo
// Name: Avalon Numbers
// Level: 7
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2736

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair <int, int> ii;


int tam;
char s[22];

ull n, m, y, yy;
ull pd[22][2][10];
int mark[22][2][10], cnt = 1;

ull solve(int i, int p, int last){
	if(i==-1) return 1;
	if(mark[i][p][last]==cnt) return pd[i][p][last];
	mark[i][p][last] = cnt; ull ret = 0;
	for(int j=0; j<=(p?9:s[i]-'0'); j++){
		if(j==m || (last==y && j==yy)) continue;
		ret+=solve(i-1, p|(j<s[i]-'0'), j);
	}
	return pd[i][p][last] = ret;
}


int main(){
	
	while(scanf("%llu %llu %llu", &n, &m, &y)!=EOF){
		ull ini = 1, fim = -2, mid, ans = -1;
		yy = y%10, y = y/10;
		while(ini<=fim){
			mid=(ini/2+fim/2) + (ini&1 && fim&1);
			tam = 0; ull aux = mid;
			while(aux){
				s[tam++] = (aux%10+'0');
				aux/=10;
			}
			ull qt = solve(tam-1, 0, 0)-1; cnt++;
			if(qt>=n){
				ans = mid;
				fim = mid-1;
			}else{
				ini = mid+1;
			}
		}
		printf("%llu\n", ans);
	}
	
	return 0;
}
