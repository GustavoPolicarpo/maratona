// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Números Divinos
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2291

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


#define MAX  1010  
#define MAX2 1000001

int bp[MAX2], primos[MAX], fim;
ll sum[MAX2], divinos[MAX2+1];

void allprimos(){
	
	memset(bp, 1, sizeof bp);
	int max=sqrt(MAX2); bp[1]=0;
	for(int i=2; i<max; i++)
	{
		if(bp[i])
		{
			for(int j=i*i; j<MAX2; j=j+i)
				bp[j]=0;
		}
	}
	
	int j=0;
	for(int i=2; i<MAX; i++)
		if(bp[i])
			primos[j++]=i;
	
	fim=j;
	
	//for(int i=0; i<fim; i++)
	//	cout << primos[i] << endl;
	
	return;
	
}

inline void build_divinos(){
	sum[1]=1; int p=1; ll ss=sum[1]; divinos[p++]=ss;
	rep(i, 2, MAX2){
		
		sum[i]=1;
		int j=0, aux=i, last=0;
		while(aux>1 && j<fim){
			if(bp[aux])	break;
			
			while(aux%primos[j]==0){
				last++;
				aux/=primos[j];
			}
			
			if(last) sum[i]*=(pow(primos[j], last+1)-1)/(primos[j]-1);
			last=0;
			j++;
			
		}
		
		if(last) sum[i]*=(pow(primos[j], last+1)-1)/(primos[j]-1);
		if(aux>1) sum[i]*=(pow(aux, 2)-1)/(aux-1);
		

		ss+=sum[i];
		divinos[p++]=ss;
	}
	
	return;	
}

int main(){
	
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	allprimos();
	build_divinos();
	
	int N;
	while(1){
		scanint(N);
		if(!N) break;
		printf("%lld\n", divinos[N]);
	}
	
	return 0;
}

