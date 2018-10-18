// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Crepúsculo em Portland
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2168

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int sum[105][105], mat[105][105];
int N, M;
void build_sum()
{
	sum[0][0]=mat[0][0];
	rep(i, 1, N) sum[i][0]=sum[i-1][0]+mat[i][0];
	rep(j, 1, M) sum[0][j]=sum[0][j-1]+mat[0][j];
	rep(i, 1, N)
	rep(j, 1, M)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];
}

int main()
{
	cin >> N; N++; M=N;
	rep(i, 0, N)
	rep(j, 0, N)
		scanf("%d", &mat[i][j]);
	build_sum();
	rep(i, 1, N){
		rep(j, 1, N){
			int query=sum[i][j];
			if(i>1) query-=sum[i-2][j];
			if(j>1) query-=sum[i][j-2];
			if(i>1 && j>1) query+=sum[i-2][j-2];
			//cout << query << endl;
			if(query>=2) printf("S");
			else printf("U");
		}
		printf("\n");
			
	}
	
return 0;
}
