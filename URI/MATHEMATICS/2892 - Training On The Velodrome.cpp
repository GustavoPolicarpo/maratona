// Author: Gustavo Policarpo
// Name: Training On The Velodrome
// Level: 10
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2892

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;


int main(){
	
	int T, A, B;
	while(scanf("%d %d %d", &T, &A, &B)and T){
		vector <int> dividers; int fim = sqrt(T);
		rep(i, 1, fim+1){
			if(T%i==0){
				dividers.pb(i);
				if(i!=T/i)
					dividers.pb(T/i);
			}
		}
		sort(dividers.begin(), dividers.end());
		int yep = 0;
		rep(i, 0, dividers.size()){
			int C = dividers[i];
			ll ABC = A*B/(__gcd(A, B));
			ABC = (ABC/__gcd(ABC, (ll)C)*C);
			if(ABC==T){
				if(yep) printf(" "); yep = 1;
				printf("%d", dividers[i]);
			}
		}	puts("");
		
	}

	return 0; 
}	
	

