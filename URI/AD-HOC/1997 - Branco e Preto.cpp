// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Branco e Preto
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1997

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

string a, b; int pd[501][2], tam;

int solve(int i, int z)
{
	if(i==tam) return 0;
	int &p=pd[i][z];
	if(p!=-1) return p;
	int ret=INF;
	if(z==0){
		if(a[i]==b[i]){
			ret=min(ret, solve(i+1, 0));
			//ret=min(ret, solve(i+1, 1));
		}
		else{
			ret=min(ret, solve(i+1, 0)+1);
			ret=min(ret, solve(i+1, 1)+1);
		}
	}
	else{
		if(a[i]!=b[i]){
			ret=min(ret, solve(i+1, 0));
			ret=min(ret, solve(i+1, 1));
		}
		else{
			ret=min(ret, solve(i+1, 0)+1);
			ret=min(ret, solve(i+1, 1)+1);
		}
	}
	return p=ret;
}

int main()
{
	while(cin >> a >> b){
		if(a=="*" && b=="*") break;
		tam=a.size();
		memset(pd, -1, sizeof pd);
		int out=solve(0, 0);
		cout << out << endl;
	}
	
	
return 0;
}
