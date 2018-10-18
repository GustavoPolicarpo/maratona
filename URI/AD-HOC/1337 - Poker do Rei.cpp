// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Poker do Rei
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1337

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef pair<int, int> ii;
typedef pair<ii, ii> iii;

int val(int a, int b, int c){
	int ret=a+b+c;
	if(a==b) ret+=40*a;
	if(a==c) ret+=40*a;
	if(b==c) ret+=40*b;
	if(a==b && a==c) ret+=a*4000;
	return ret;
}


int main()
{
	
	int v[3];
	
	vector <iii> ve;
	rep(i, 1, 14){
		rep(j, 1, 14){
			rep(k, 1, 14){
			//	cout << i << " " << j << " " << k << " " << val(i, j, k) << '\n';
				ve.pb(mp(mp(val(i, j, k), i), mp(j, k)));
			}
		}
	}
	
	sort(ve.begin(), ve.end());
	
	while( scanf("%d %d %d", &v[0], &v[1], &v[2]) and v[0] ){
		
		sort(v, v+3);
		
		if(v[0]!=v[1] && v[1]!=v[2]){
			puts("1 1 2");
			continue;
		}
		
		int yep=0, cmp=val(v[0], v[1], v[2]);
		rep(i, 0, ve.size()){
			if(ve[i].F.F>cmp){
				yep=1;
				printf("%d %d %d\n", ve[i].F.S, ve[i].S.F, ve[i].S.S);
				break;
			}
		}
		
		if(!yep) puts("*");
		
	}
	
	return 0;
	
}
