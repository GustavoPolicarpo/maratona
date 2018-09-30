#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int __mmc(int a, int b){
	return a/__gcd(a, b)*b;
}

int main(){
	
	int N, T;
	while(cin >> N >> T and N){
		set <int> st; int aux, mmc = 0;
		rep(i, 0, N){
			cin >> aux;
			if(i==0) mmc = aux;
			else mmc = __mmc(mmc, aux);
			st.insert(aux);
		}
		aux = -1;
		rep(i, 2, T+1){
			if(st.count(i)) continue;
			if(__mmc(mmc, i)==T){
				aux = i;
				break;
			}
		}
		if(aux==-1) puts("impossivel");
		else printf("%d\n", aux);
	}
		
	
	return 0;
} 
