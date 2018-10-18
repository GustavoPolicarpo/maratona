// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Procurando Assentos
// Nível: 6
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1365

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
typedef pair < char, ii > iii;


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int r, c, k;
	while(scanf("%d %d %d", &r, &c, &k) and r){
		int mat[r][c], sum[r+2][c+2]; char s[c];
		rep(i, 0, r){
			scanf("%s", s);
			rep(j, 0, c){
				s[j]=='.'  ? mat[i][j]=1 : mat[i][j]=0;
			}
		}	memset(sum, 0, sizeof sum);
		
		sum[1][1]=mat[0][0];
		rep(i, 1, c) sum[1][i+1]=sum[1][i]+mat[0][i];
		rep(i, 1, r) sum[i+1][1]=sum[i][1]+mat[i][0];
		rep(i, 2, r+1) rep(j, 2, c+1) sum[i][j]=sum[i-1][j]+sum[i][j-1]+mat[i-1][j-1]-sum[i-1][j-1];
		
		/*rep(i, 1, r+1){
			rep(j, 1, c+1)
				cout << sum[i][j] << " ";
			cout << '\n';
		}*/
		
		int ans=INF;
		
		rep(c1, 0, c){
			rep(c2, c1, c){
				for(int r1=0, r2=0; r2<r; r2++){
					while( r1<r2 && sum[r2+1][c2+1]-sum[r1+1][c2+1]-sum[r2+1][c1] + sum[r1+1][c1] >=k ) r1++;
					
					if( sum[r2+1][c2+1]-sum[r1][c2+1]-sum[r2+1][c1] + sum[r1][c1] >=k ){
						ans=min(ans, (c2-c1+1)*(r2-r1+1));
					}
				}
			}
		}
		
		printf("%d\n", ans);
		
	}
	
	return 0;
	
}
