// Author: Gustavo Policarpo
// Name: Golnaldinho
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2792

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

int N, aux, bit[500050];

void update(int x){
	for(; x<=N+2; x+=(x&-x)) bit[x]++;
}
int query(int x){
	int ret = 0;
	for(; x>0; x-=(x&-x)) ret+=bit[x];
	return ret;
}

int main(){
	
	scanf("%d", &N);
	rep(i, 1, N+1){
		scanf("%d", &aux);
		if(i-1) printf(" ");
		printf("%d", aux-query(aux));
		update(aux);
	}	printf("\n");
	
	
	return 0;
}
