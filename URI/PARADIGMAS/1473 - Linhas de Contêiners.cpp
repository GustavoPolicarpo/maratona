// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Linhas de Contêiners
// Nível: 6
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1473

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

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

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

int main()
{
	
	//freopen("in.txt", "r", stdin);
//	freopen("out.txt", "w", stdout);

	int L, C;
	
	while(scanf("%d %d", &L, &C) !=EOF){
		int ans=0, p=1, mat[L][C];
		
		rep(i, 0, L)
		rep(j, 0, C)
			scanf("%d", &mat[i][j]);
		
		set <ii> visl;
		rep(i, 0, L){
			if(visl.count(mp(mat[i][0], i))) break;
			visl.insert(mp(mat[i][0], i));
			
			if((mat[i][0]-1)/C != i){
				int go=(mat[i][0]-1)/C;
				rep(j, 0, C)
					swap(mat[i][j], mat[go][j]);
				
				ans++, i--;
			}
		}
		
		set <ii> visc;
		rep(j, 0, C){
			if(visc.count(mp(mat[0][j], j))) break;
			visc.insert(mp(mat[0][j], j));
			
			if((mat[0][j]-1)%C != j){
				int go=(mat[0][j]-1)%C;
				rep(i, 0, L)
					swap(mat[i][j], mat[i][go]);
				
				ans++, j--;
			}
		}
		
		bool yep=true;
		rep(i, 0, L){
			rep(j, 0, C)
				if(mat[i][j]!=p++){
					yep=false;
					break;
				}
			if(!yep) break;
		}
		
		/*rep(i, 0, L){
			rep(j, 0, C)
				cout << mat[i][j] << " ";
			cout << '\n';
		}*/
		
		if(yep) printf("%d\n", ans);
		else puts("*");
		
	}
	
	return 0;
	
}
