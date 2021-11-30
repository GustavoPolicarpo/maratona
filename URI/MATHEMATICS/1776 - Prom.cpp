// Author: Gustavo Policarpo
// Name: Prom
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1776

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
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}
*/

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

#define MAX 100001  //MAXIMO VALOR

vector <int> primos;

int ehprimo[MAX+1], divisores[MAX];

void allprimos(){
	
	for (int i=2; i<MAX; i++) ehprimo[i]=1;
	int max=sqrt(MAX);
	for(int i=2; i<max; i++)
	{
		if(ehprimo[i]==1)
		{
			for(int j=i*i; j<MAX; j=j+i)
				ehprimo[j]=0;
		}
	}
	
	for(int i=2; i<MAX; i++)
		if(ehprimo[i]==1)
			primos.push_back(i);	
}

int main()
{

	allprimos();
	
	int T, N; cin >> T;
	rep(z, 1, T+1){
		scanf("%d", &N); ll out=N;
		int j=0;
		while(N>1 && j<primos.size()){
			//cout << N << " " << j << " " << primos[j] << endl;
			if(N%primos[j]==0){
				N/=primos[j];
				divisores[j]++;
			}
			else j++;
		}
		//cout << N << " " << j << endl;
		if(j==primos.size()) out=out*N;
		rep(i, 0, j+1){
			//cout << div[i] << endl;
			if(divisores[i]!=0 && divisores[i]&1) out*=primos[i];
			divisores[i]=0;
		}
		
				
		printf("Caso #%d: %lld\n", z, out);
	}
}


