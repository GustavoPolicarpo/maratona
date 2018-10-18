// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: WWW
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2511

#include <bits/stdc++.h>

using namespace std;

#define rep(i, a, b) for(int i=a; i<b; i++)
#define F first
#define S second
#define pb push_back

typedef long long int ll;

const int INF = 0x3f3f3f3f;
const int MAX=1000010;

vector <int> eh(MAX+2, 1);

void build_ans(){
	
	int fim=sqrt(MAX)+2; eh[1]=eh[0]=0;
	
	for(int i=2; i<fim; i++){
		if(eh[i]){
			for(int j=i*i; j<MAX; j+=i){
				eh[j]=0;
			}
		}
	}
	
	return;
	
}

int main(){
	
	build_ans();
	
	int N;
	while(scanf("%d", &N) !=EOF){
		int yep=0, aux;
		rep(i, 0, N){
			scanf("%d", &aux);
			if(eh[aux]){
				yep ? printf(" ") : yep=1;
				printf("%d", aux);
			}
		}
		
		yep ? printf("\n") : printf("*\n");
		
	}
	return 0;
	
}
