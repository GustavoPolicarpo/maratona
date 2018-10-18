// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Picos e Vales
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2162

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int N, n[101];
int main()
{
    scanf("%d", &N);
    rep(i, 0, N){
    	scanf("%d", &n[i]);
	}
	
	int op;
	if(N==1){
		printf("1\n");
		return 0;
	}
	if(n[1]>n[0]) op=1;
	else if(n[1]<n[0]) op=-1;
	else{
		printf("0\n");
		return 0;
	}
	bool yep=true;
	rep(i, 2, N){
		if(op==1 && n[i]>=n[i-1]){
			yep=false;
			break;
		}
		else if(op==-1 && n[i]<=n[i-1]){
			yep=false;
			break;
		}
		op*=-1;
	}
	if(yep) printf("1\n");
	else printf("0\n");

    
return 0;
}

