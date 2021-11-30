// Author: Gustavo Policarpo
// Name: The Dole Queue
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1119

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
using namespace std;

int main(){

    int N, M, K;
    while(scanf("%d %d %d", &N, &M, &K) and N){
    	vector <int> v;
    	rep(i, 1, N+1) v.pb(i);
    	int i=0, j=N-1, aux, yep=0;
    	while(yep<v.size()){
    		
    		aux=M-1;
    		while(v[i]==-1){
    			i++;
    			if(i==N) i=0;
			}
    		while(aux--){
    			i++;
    			if(i==N) i=0;
    			if(v[i]==-1) aux++;
			}
			if(yep) printf(",");
			printf("%3d", v[i]), yep++;
			
			while(v[j]==-1){
    			j--;
    			if(j==-1) j=N-1;
			}
    		aux=K-1;
    		while(aux--){
    			j--;
    			if(j==-1) j=N-1;
    			if(v[j]==-1) aux++;
			}
			
			if(v[j]!=v[i]) printf("%3d", v[j]), yep++;
			v[j]=-1, v[i]=-1;
		}
		printf("\n");
		
			
	}		
   
    return 0;   
}
