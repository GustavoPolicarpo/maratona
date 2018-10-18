// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Estrela
// Nível: 6
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1233

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
#define mod 1000000007

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

#define MAX 55000  
vector <int> primos;
int bp[MAX];

int crivo()
{	
	for (int i=2; i<MAX; i++) bp[i]=1;
	int max=sqrt(MAX);
	for(int i=2; i<max; i++)
	{
		if(bp[i]==1)
		{
			for(int j=i*i; j<MAX; j=j+i)
				bp[j]=0;
		}
	}
	for(int i=2; i<MAX; i++)
		if(bp[i]==1)
			primos.push_back(i);
			
	/*for(int i=0; i<primos.size(); i++)
		cout << primos[i] << endl;*/	
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	crivo();
	int N;
	while(scanf("%d", &N) !=EOF ){
		int aux=N, j=0, fim=primos.size();
		while(aux>1 && j<fim){
			if(aux%primos[j]==0){
				N=N/primos[j]*(primos[j]-1);
				while(aux%primos[j]==0) 
					aux/=primos[j];
			}
			else j++;
		}
		if(aux>1) N=N/aux*(aux-1);
		printf("%d\n", N/2);
	}
			

return 0;

}
