// Author: Gustavo Policarpo
// Name: The Bad Vibes Walk
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2958

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define per(i,a,b) for( int i = (int) a; i > (int) b; i-- )
#define F first
#define S second
#define pb push_back
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugV(v, n) { rep( i, 0, n ) { if(i) printf(" "); printf("%d", v[i]); } printf("\n"); }
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) { if(j) printf(" "); printf("%d", mat[i][j]); } printf("\n"); }
#define all(s) s.begin(), s.end()

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

const int MAX = 2e3+3;
const int mod = 1e9+7;


bool cmp(string a, string b){
    if(a[1]!=b[1]) return a[1] > b[1];
    return a[0] > b[0];
}

int main(){

    int n, m;
    vector <string> vs;
    cin >> n >> m; string s;
    rep(i, 0, n){
        rep(j, 0, m){
            cin >> s;
            vs.pb(s);
        }
    }

    sort(all(vs), cmp);

    rep(i, 0, vs.size()) cout << vs[i] << '\n';


    return  0;
}
