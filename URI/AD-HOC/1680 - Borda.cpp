// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Borda
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1680

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<int, ii> iii;

const int INF=0x3f3f3f3f;
const int mod=1e9+7;



int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	string s;
	
	while(cin >> s){
		
		puts("300 420 moveto");
		puts("310 420 lineto");
		
		int x=310, y=420, dir=0;
		
		rep(i, 0, s.size()){
			
			if(s[i]=='A'){
				if(dir==0) y-=10, dir=3;
				else if(dir==1) x+=10, dir=0;
				else if(dir==2) y+=10, dir=1;
				else if(dir==3) x-=10, dir=2;
			}else{
				if(dir==0) y+=10, dir=1;
				else if(dir==1) x-=10, dir=2;
				else if(dir==2) y-=10, dir=3;
				else if(dir==3) x+=10, dir=0;
			}
			
			printf("%d %d lineto\n", x, y);
			
		}
		
		puts("stroke");
		puts("showpage");
		
	}
		
	return 0;
	
}
