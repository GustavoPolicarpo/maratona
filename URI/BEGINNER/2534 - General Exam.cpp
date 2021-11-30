// Author: Gustavo Policarpo
// Name: General Exam
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2534

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

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;


int main(){

	int n, m;
	
	while(scanf("%d %d", &n, &m)!=EOF){
		
		vector <int> v; int aux;
		rep(i, 0, n){
			scanf("%d", &aux);
			v.pb(aux);
		}
		
		sort(v.begin(), v.end());
		reverse(v.begin(), v.end());
		
		while(m--){
			scanf("%d", &aux);
			printf("%d\n", v[aux-1]);
		}
	
	
	}


	return 0;

}
