// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Digitando no Telefone Cel...
// Nível: 6
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1284

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef pair < int, int > ii;


//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
int sig[1000010][30], term[1000010], cnt, tam, tt;

inline int C( char c ){
	return c - 'a';
}

void add( string s ){
	int x = 0;
	
	rep( i, 0, s.size() ){		
		int c = C( s[i] );
		if( !sig[x][c] ){
			term[cnt] = 0; 								
			sig[x][c] = cnt++;
		}
		x = sig[x][c];
	}
	
	term[x] = 1;									
}

int ver( string s ){
	int x=0, ret=0, last=0;
	
	x=sig[x][C(s[0])];
	last = term[x];
	
	rep(i, 1, s.size()){
		int c=C(s[i]), yep=1;
		
		if(last){
			last=0;
			yep=0;
		}else{
			rep(j, 0, 26){
				if(j==c) continue;
				if(sig[x][j]){
					yep=0;
					break;
				}
			}
		}
		
		ret += yep;
		x=sig[x][c];
		//cout << s[i] << ' ' << s << " " << x <<  "\n";
		if(term[x]) last=1;
	}
	
	return ret;
	
}


int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int n;
	while(scanf("%d", &n) !=EOF){
		vector <string> vet; char s[88]; cnt=1, tt=0;
		rep(i, 0, n){
			scanf("%s", s);
			add(s);
			vet.pb(s);
		}
		
		rep(i, 0, n){
			tam=vet[i].size();
			tam-=ver(vet[i]);
			tt+=tam;
		}
		
		rep(i, 0, cnt+2){
			term[i]=0;
			rep(j, 0, 28){
				sig[i][j]=0;
			}
		}
		
		printf("%.2lf\n", double(tt)/n);
		
	}
	
	return 0;
	
}
