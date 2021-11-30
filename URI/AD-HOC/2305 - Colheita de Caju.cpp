// Author: Gustavo Policarpo
// Name: Colheita de Caju
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2305

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


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, M, l, c, mat[1001][1001], sum[1001][1001];


void build_sum(){
	
	sum[0][0]=mat[0][0];
	
	rep(i, 1, N) sum[i][0]=sum[i-1][0]+mat[i][0];
	rep(j, 1, M) sum[0][j]=sum[0][j-1]+mat[0][j];
	
	rep(i, 1, N)
	rep(j, 1, M)
		sum[i][j]=sum[i-1][j]+sum[i][j-1]+mat[i][j]-sum[i-1][j-1];
		
	/*rep(i, 0, N){
		rep(j, 0, M)
			cout << sum[i][j] << " ";
		cout << '\n';
	}*/
	
}
int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	scanint(N), scanint(M), 
	scanint(l), scanint(c);
	
	rep(i, 0, N)
	rep(j, 0, M)
		scanint(mat[i][j]);
	
	//cout << "\n";
	build_sum();
	
	int ans=0;
	rep(i, 0, N-l+1)
	rep(j, 0, M-c+1){
		int aux=sum[i+l-1][j+c-1];
		
		if(i>0) aux-=sum[i-1][j+c-1];
		if(j>0) aux-=sum[i+l-1][j-1];
		if(i>0 && j>0) aux+=sum[i-1][j-1];
		
		//cout << i << " " << j << " " << aux << endl;
		if(aux>ans) ans=aux;
	}
	
	printf("%d\n", ans);
	
	return 0;
}

