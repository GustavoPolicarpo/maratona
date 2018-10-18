// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Marianne e os Primos Gêmeos
// Nível: 4
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1926

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;

const int MAXS = 1000010;
const int MAXSS = sqrt(MAXS)+10;
vector <int> primos;
int eh[MAXS];

void crivo(){
	memset(eh, 1, sizeof eh);
	eh[0] = eh[1] = 0;
	for(int i=2; i<MAXSS; i++){
		if(eh[i]){
			for(int j=i*i; j<MAXS; j+=i)
				eh[j] = 0;
		}
	}
	for(int i=2; i<MAXS; i++){
		if(eh[i])
			primos.pb(i);
	}
}

int sum[MAXS];
void buildSum(){
	for(int i=2; i<MAXS; i++){
		sum[i] = sum[i-1];
		if(eh[i] && (eh[i-2] || eh[i+2]))
			sum[i]++;
	}
}

int main(){
	
	crivo();
	buildSum();
	int Q; cin >> Q;
	while(Q--){
		int X, Y; cin >> X >> Y;
		if(X>Y) swap(X, Y);
		cout << sum[Y] - sum[X-1] << '\n';
	}
		
	return 0;
} 
