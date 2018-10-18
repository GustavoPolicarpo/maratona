// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Go--
// Nível: 5
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2241

#define gc getchar_unlocked
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
const int mod = 1e9 + 7;
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

int N, P, mat[2][505][505], sum[2][505][505];

void build_sum(){
	
	sum[0][0][0]=mat[0][0][0], sum[1][0][0]=mat[1][0][0];
	
	rep(i, 1, N){
		sum[0][i][0]=sum[0][i-1][0]+mat[0][i][0];
		sum[0][0][i]=sum[0][0][i-1]+mat[0][0][i];
		
		sum[1][i][0]=sum[1][i-1][0]+mat[1][i][0];
		sum[1][0][i]=sum[1][0][i-1]+mat[1][0][i];
	}
	
	rep(i, 1, N)
	rep(j, 1, N)
		sum[0][i][j]=mat[0][i][j]+sum[0][i-1][j]+sum[0][i][j-1]-sum[0][i-1][j-1],
		sum[1][i][j]=mat[1][i][j]+sum[1][i-1][j]+sum[1][i][j-1]-sum[1][i-1][j-1];
}

int Q(int i, int j, int k, int id){
	int ret=sum[id][i+k][j+k];
	if(i) ret-=sum[id][i-1][j+k];
	if(j) ret-=sum[id][i+k][j-1];
	if(i && j) ret+=sum[id][i-1][j-1];
	return ret;
}

int lower(int i, int j, int id){
	int ini=-1, fim=N-max(i, j) , use=(ini+fim)/2;
	
	while(fim-ini>1){
		if(Q(i, j, use, id)){
			fim=use, use=(ini+fim + 1)/2;
		}
		else{
			ini=use, use=(ini+fim + 1)/2;
		}
	}
	return use;
}

int upper(int i, int j, int id, int aa){
	int ini=aa-1, fim=N-max(i, j), use=(ini+fim)/2 ;

	while(fim-ini>1){
		if(Q(i, j, use, id) && !Q(i, j, use, !id)){
			ini=use, use=(ini+fim + 1)/2;
		}
		else{
			fim=use, use=(ini+fim + 1)/2;
		}
	}
	return use;
}


int main()
{

	scanint(N), scanint(P);
	int l, c;
	
	
	rep(i, 0, P){
		scanint(l), scanint(c); l--, c--;
		mat[0][l][c]=1;
	}
	
	rep(i, 0, P){
		scanint(l), scanint(c); l--, c--;
		mat[1][l][c]=1;
	}
	
	build_sum();

	int b=0, p=0;
	rep(i, 0, N)
	rep(j, 0, N){
		int aa=lower(i, j, 0), bb=upper(i, j, 0, aa);
		if(bb>aa) b+=bb-aa;
		
		aa=lower(i, j, 1), bb=upper(i, j, 1, aa);
		if(bb>aa) p+=bb-aa;
	}
	
	printf("%d %d\n", b, p);

return 0;
}
