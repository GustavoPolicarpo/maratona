#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;


int main(){
	
	int N, A, B;
	while(cin >> N >> A >> B and N){
		cout << N/A + N/B - N/(A/__gcd(A, B)*B) << '\n';
	}	

	return 0;
} 
