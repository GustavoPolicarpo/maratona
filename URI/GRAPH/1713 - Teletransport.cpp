// Author: Gustavo Policarpo
// Name: Teletransport
// Level: 7
// Category: GRAPH
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1713

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
#define MAXN 100001
//#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ii, int > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/
struct Matriz{
	int mat[101][101];
};

Matriz identidade; int N, L; const int mod=10000;

Matriz multiplica(Matriz A, Matriz B)
{
	Matriz C;
	rep(i, 0, N)
		rep(j, 0, N){
			C.mat[i][j]=0;
			rep(k, 0, N)
				C.mat[i][j]=((C.mat[i][j]%mod+((A.mat[i][k]%mod)*(B.mat[k][j]%mod))%mod));
		}
	return C;			
}

Matriz fastExp(Matriz base, int p)
{
	if(p==0) return identidade;	
	Matriz ret=fastExp(base, p/2);
	ret=multiplica(ret, ret);
	if(p&1) ret=multiplica(ret, base);
	return ret;
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	rep(i, 0, 101) 
	rep(j, 0, 101){
		if(i==j) identidade.mat[i][j]=1;
		else identidade.mat[i][j]=0;
	}

	while(scanf("%d %d", &N, &L) !=EOF){
		Matriz n;
		int S, D, aux; scanf("%d %d", &S, &D); S--, D--;
		
		rep(i, 0, N)
		rep(j, 0, N)
			n.mat[i][j]=0;
			
		rep(i, 0, N)
		rep(j, 0, 4){
			scanf("%d", &aux);
			n.mat[i][aux-1]++;
		}
		
		/*rep(i, 0, N){
			rep(j, 0, N)
				cout << n.mat[i][j] << " ";
			cout << endl;
		}*/
		
		n=fastExp(n, L);
		
		printf("%d\n", n.mat[S][D]%mod);
	}
	return 0;
}
