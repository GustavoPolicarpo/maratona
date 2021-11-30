// Author: Gustavo Policarpo
// Name: The Square Game
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2067

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;

int L, C;
int mat[201][201] , sum[201][201];

void build_sum(int l, int c)
{
	sum[0][0]=mat[0][0];
	rep(i, 1, l) sum[i][0]=sum[i-1][0]+mat[i][0];
	rep(j, 1, c) sum[0][j]=sum[0][j-1]+mat[0][j];
	rep(i, 1, l)
		rep(j, 1, c)
sum[i][j]=sum[i-1][j]+sum[i][j-1]-sum[i-1][j-1]+mat[i][j];	
}

int calculo_tamanho(int l, int c, int k, int me, int MA)
{
	int maior=0; bool achou; int temp;
	while(MA-me>1){
		int u=k-1; achou=false;
		rep(i, 0, l-u){
			rep(j, 0, c-u){
				temp=sum[i+u][j+u];
				if(i>0) temp-=sum[i-1][j+u];
				if(j>0) temp-=sum[i+u][j-1];
				if(i>0&&j>0) temp+=sum[i-1][j-1];
				if(temp==0){
					achou=true;
					maior=k;
					me=k;
					k=k+MA/2;
					break;
				}
			}
			if(achou) break;
		}
		if(!achou){
			MA=k;
			k=(k+me)/2;
		}
	}
	return maior;
}

int main()
{
	cin >> L >> C;
	ll in;
	rep(i, 0, L)
		rep(j, 0, C){
			scanf("%lld", &in);
			if(in==0)
				mat[i][j]=1;
			else
				mat[i][j]=0;	
		}
	build_sum(L, C);
	
	int ml=(L+C-abs(L-C))/2;
	int k=ml/2;
	int maior_lado=calculo_tamanho(L, C, k, 0, ml+1);
	//cout << maior_lado << endl;
	int Q; cin >> Q; int cons;
	while(Q--){
		scanf("%d", &cons);
		if(cons<=maior_lado)	cout << "yes" << endl;
		else 					cout << "no" << endl;
	}
	
return (0);
}
