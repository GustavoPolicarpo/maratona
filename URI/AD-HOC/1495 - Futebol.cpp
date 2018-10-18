// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Futebol
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1495

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

int N, g;

int main()
{
	while(cin >> N >> g){
		int gm[N], gs[N], s[N];
		rep(i, 0, N){
			scanf("%d %d", &gm[i], &gs[i]);
			s[i]=gm[i]-gs[i];
		}
		ll p = 0;
		sort(s, s+N);
		reo(i, N-1, -1){
			if(s[i]>0) p+=3;
			else if(s[i]==0){ 
				if(g>0)
					g--, p+=3;
				else
					p++;	
			}
			else if(s[i]<0){
				if(g>0){
					if(g+s[i]>0)
						g+=s[i]-1, p+=3;
					else if(g+s[i]==0)
						g+=s[i], p++;	
				}
				else
					break;	
			}
		}
		cout << p << endl;
	}
	
return (0);	
}
