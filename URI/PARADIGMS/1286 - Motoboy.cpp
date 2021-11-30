// Author: Gustavo Policarpo
// Name: Motoboy
// Level: 5
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1286

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define MAXN 31

int C,N,peso[MAXN], valor[MAXN], pd[MAXN][MAXN];

int mochila(int i, int c)
{
	if(i == N) return 0;
	if(pd[i][c] != -1) return pd[i][c];
	int ret = mochila(i+1,c);
	if(c-peso[i] >= 0) ret = max(ret, mochila(i+1,c-peso[i])+valor[i]);
	return pd[i][c] = ret;
}

int main()
{
	while(cin >> N and N){
		
		int c; cin >> c;
		rep(i, 0, N){
				int v, p;
				cin >> v >> p;
				peso[i]=p;
				valor[i]=v;
				
			}

			rep(i, 0, MAXN)
				rep(j, 0, MAXN)
					pd[i][j]=-1;
					
			int tempo=mochila(0,c);
			cout << tempo << " min." << endl;		
		}
		
return 0;						
}
	

