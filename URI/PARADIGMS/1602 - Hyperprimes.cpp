// Author: Gustavo Policarpo
// Name: Hyperprimes
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1602

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
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

#define MAX 2000001  //MAXIMO VALOR

vector <int> primos;

int ehprimo[MAX];

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
}
int div(int x){
	
	int aux=sqrt(x), ret=0;
	
	rep(i, 2, aux) if(x%i==0) ret++;
	ret++; ret*=2; ret++;
	
	return ret;
}
int ehiper[MAX];
void hyperprimos(){
	
	for(int i=2; i<MAX; i++)
	{
		if(ehprimo[i]) ehiper[i]=1;
		else{
			int aux=sqrt(i);
			if(aux*aux==i){
				int ndiv=div(i);
				if(ehprimo[ndiv]) ehiper[i]=1;
				else ehiper[i]=0;
			}
		}
	}
}

int sum[MAX];
int main()
{
	allprimos();
	hyperprimos(); sum[2]=1;
	rep(i, 3, MAX) sum[i]=sum[i-1]+ehiper[i];
	int N;
	while(scanf("%d", &N) !=EOF){
		printf("%d\n", sum[N]);
	}
	
return 0;
}
