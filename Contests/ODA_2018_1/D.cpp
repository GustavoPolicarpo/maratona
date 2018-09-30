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
	
	int n;
    ll m[100010], d[100010], g;
    scanf("%d", &n);
    rep(i, 0, n) scanf("%lld", &m[i]);
    rep(i, 0, n) scanf("%lld", &d[i]);
    scanf("%lld", &g);
 
    ll ans = 0, ini = 0, mid, fim = 100001, aux;
    while(ini<=fim){
        mid = (ini+fim)/2, aux = 0;
        rep(i, 0, n) aux+= m[i]*(min(mid, d[i]));
        if(aux>g) fim = mid-1;
        else ini = mid+1, ans = mid;
    }
 
    if(ans==100001) ans = -1;
    printf("%lld\n", ans);

	return 0;
}
