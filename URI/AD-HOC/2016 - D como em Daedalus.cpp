// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: D como em Daedalus
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2016

#include<bits/stdc++.h>
#define gc getchar_unlocked


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
#define mod 1300031
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, int > ii;
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
}*/

	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
int main(){
	int N, M, mat[55][55], atual=0, maximo=0;
	cin >> M >> N;
	rep(i, 0, N){
		int aux=0;
		rep(j, 0, M+1){
			scanf("%d", &mat[i][j]);
			if(j>0) aux+=mat[i][j];
		}
		mat[i][M+1]=aux-mat[i][1];
		if(aux<=mat[i][0]) atual+=mat[i][1];
	}

	rep(i, 0, N){
		int v=mat[i][M+1], b=mat[i][0];
		if(v>=b) continue;
		if(v+10000<=b) maximo+=10000;
		else if(v+1000<=b) maximo+=1000;
		else if(v+100<=b) maximo+=100;
		else if(v+10<=b) maximo+=10;
		else if(v+1<=b) maximo+=1;
	}
	cout << maximo-atual << endl;
		
return 0;	
}
