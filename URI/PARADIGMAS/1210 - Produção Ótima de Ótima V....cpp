// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Produção Ótima de Ótima V...
// Nível: 5
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1210

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

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}




int N, I, M, P;
int custo[2002], valor[2002], pd[2002][2002], memo[2002][2002];

int solve(int p, int i){
	
	if(p==N) return 0;
	if(pd[p][i]!=-1) return pd[p][i];
	
	int ret=INF, aux=INF;
	
	ret=solve(p+1, 1)+custo[0]-valor[i]+P;
	memo[p][i]=1;
	
	if(i<M)	aux=solve(p+1, i+1)+custo[i];
	
	/*cout << p << "  " << i << "    ";
	cout << ret << " ";
	cout << aux << '\n';*/
	
	if(aux<ret) ret=aux, memo[p][i]=0;
	
	return pd[p][i]=ret;
	
}

void recovery(){
	int per=0, ia=I, yep=0;
	
	while(per<N){
		if(memo[per][ia]){
			if(yep) printf(" ");
			else yep=1;
			printf("%d", per+1);
			ia=1;
		}else{
			ia++;
		}
		per++;
	}
	if(!yep) printf("0");
	printf("\n");
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d %d %d %d", &N, &I, &M, &P) !=EOF){
		
		rep(i, 0, N+1)
		rep(j, 0, M+1) pd[i][j]=-1;
		
		rep(i, 0, M) scanf("%d", &custo[i]); custo[M]=INF;
		rep(i, 1, M+1) scanf("%d", &valor[i]);
		
		int out=min(solve(0, I), INF);
		
		printf("%d\n", out);
		recovery();
		
	}
	
	return 0;
	
}
