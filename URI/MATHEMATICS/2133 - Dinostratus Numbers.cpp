// Author: Gustavo Policarpo
// Name: Dinostratus Numbers
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2133

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
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 			
#define MAX 1050000  //MAXIMO VALOR
 
vector <int> primos;
 
int bp[MAX], fat[MAX];
 
int allprimos()
{
	
	for (ll i=2; i<MAX; i++) bp[i]=1;
	ll max=sqrt(MAX);
	for(int i=2; i<max; i++)
	{
		if(bp[i]==1)
		{
			for(ll j=i*i; j<MAX; j=j+i)
				bp[j]=0;
		}
	}
	for(ll i=2; i<MAX; i++)
		if(bp[i]==1)
			primos.push_back(i);				
}


int main()
{
	allprimos();
	int N, j, resp, z=1;
	while(scanf("%d", &N)!=EOF){
		j=0, fat[0]=0, resp=1;
		while(N>1){
			if(N%primos[j]==0){
				N/=primos[j];
				fat[j]++;
			}
			else{
				j++, fat[j]=0;
			}
		}
		int m=0;
		rep(i, 0, j+1){
			resp*=(fat[i]+1);
			if(fat[i]>m) m=fat[i];		
		}
		printf("Instancia %d\n", z++);
		if(resp==10 && m==4) printf("nao\n");
		else if(resp>=9) printf("sim\n");
		else printf("nao\n");
		printf("\n");
	}
 
return (0);	
} 
