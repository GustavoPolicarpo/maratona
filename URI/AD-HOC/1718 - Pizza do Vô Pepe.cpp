// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Pizza do Vô Pepe
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1718

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define pb push_back

typedef long long int ll;
typedef pair<int, int> ii;

const int INF = 0x3f3f3f3f;
const int MAX=1000010;

int n[200020], sum[200020], N, C, dst;

bool check(int ini){
	
	int has=n[ini], yep=1, aux;
	
	for(int i=ini; i<ini+C; i+=dst){
		
		aux=sum[i+dst-1]-sum[i];
		
		if(has && aux){
			yep=0;
			break;
		}
		if(!has && (aux==0 || aux>1)){
			yep=0;
			break;
		}
		
		if(has && n[i+dst]==1) has=1;
		else if(!has && aux+n[i+dst]==2) has=1;
		else has=0;
		
	}
	
	if(yep) return true;
	
	yep=1;
	for(int i=ini; i<ini+C; i+=dst){
		
		aux=sum[i+dst]-sum[i];
		
		if((aux==0 || aux>1)){
			yep=0;
			break;
		}
		
	}
	
	return ( yep ? true : false);
		
}

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	cin >> C >> N; dst=C/N;
	
	int aux;
	
	rep(i, 0, N) scanf("%d", &aux), n[aux]=1, n[aux+C]=1;
	sum[0]=n[0]; rep(i, 1, C+C) sum[i]=sum[i-1]+n[i];
	
	int p=0; while(!n[p]) p++;
	
	bool yep=check(p++);
	if(yep){
		puts("S");
		return 0;
	}
	
	while(1){
		yep=check(p++);
		if(yep){
			puts("S");
			return 0;
		}
		if(n[p]) break;
	}
	
	puts("N");
	
	return 0;
	
}
