// Author: Gustavo Policarpo
// Name: Looking for the Risk Factor
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2914

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;


int Q;
vector <iii> qr;

bool cmp(iii a, iii b){
	if(a.F.S != b.F.S) return a.F.S > b.F.S;
	return rand()%2;
}

int ans[50050];
int bit[100010];
int mark[100010];

void update(int x){
	for(; x<=100000; x+=(x&-x)) bit[x]++;
}

int query(int x){
	int ret = 0;
	for(; x>0; x-=(x&-x)) ret += bit[x];
	return ret;
}

bool isPrime(int n){
	if(n==2) return true;
	int fim = sqrt(n);
	rep(i, 2, fim+1){
		if(n%i==0) return false;
	}
	return true;
}


int main(){
	
	scanf("%d", &Q); iii aux;
	rep(i, 0, Q){
		scanf("%d %d", &aux.F.F, &aux.F.S);
		aux.S = i;
		qr.pb(aux);
	}
	
	sort(qr.begin(), qr.end(), cmp);
	
	int f = 100001; update(1);
	rep(i, 0, Q){
		aux = qr[i];
		while(f > aux.F.S){
			if(isPrime(f)){
				for(int j=f; j<=100001; j+=f){
					if(mark[j]) continue;
					update(j);
					mark[j] = 1;
				}
			}
			f--;
		}
		ans[aux.S] = aux.F.F - query(aux.F.F);
	}
	
	rep(i, 0, Q) printf("%d\n", ans[i]);
	
	
	

	return 0;
} 
