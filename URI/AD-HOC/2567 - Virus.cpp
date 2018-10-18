// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Virus
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2567

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;


const int MAXV = 100010;
int in[MAXV], BIT[MAXV], n, cv[MAXV];

void update(int x, int v){ 
    while(x <= n){ 
        BIT[x] += v; 
        x += x&-x; 
    } 
} 
  
int query(int x){ 
    int ans = 0; 
    while(x > 0){ 
        ans += BIT[x]; 
        x -= x&-x; 
    } 
    return ans; 
}


int main(){
	
	int n;
	while(scanf("%d", &n)!=EOF){
		int v[n];
		rep(i, 0, n) scanf("%d", &v[i]);
		sort(v, v+n);
		
		int i=0, j=n-1, ans=0;
		while(i<j){
			ans+=v[j--]-v[i++];
		}
		
		printf("%d\n", ans);
		
	}
	
	
	return 0;
	
}
