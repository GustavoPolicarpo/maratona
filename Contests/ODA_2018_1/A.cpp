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
	
	int N, M; cin >> N >> M;
	int a[N]; rep(i, 0, N) cin >> a[i];
	int qt = 1, bonus = 0, i = 0, power = M;
	
	while(42){
		if(i==N) break;
		if(a[i]>=power+bonus){
			if(i==N-1 && a[i]==power+bonus) break;
			if(a[i]==power+bonus) bonus++;
			qt++; i = 0; power = M;
		}else{
			power-=a[i]; bonus++; i++;
		}
	}
	
	cout << qt << '\n';
	
	return 0;
}
