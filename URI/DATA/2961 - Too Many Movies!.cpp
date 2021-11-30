// Author: Gustavo Policarpo
// Name: Too Many Movies!
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2961

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


int main(){

    int N; cin >> N;

    string s; getline(cin, s);
    int pts[4]; memset(pts, 0, sizeof pts);
    rep(z, 0, N){
        vector <string> vs;
        getline(cin, s);
        rep(i, 0, 4){
            getline(cin, s);
            vs.pb(s);
        }
        getline(cin, s);
        rep(i, 0, 4){
            getline(cin, s);
            if(vs[i]==s)
                pts[i]++;
        }
    }
    int mn = 0x3f3f3f3f;
    rep(i, 0, 4) mn = min(mn, pts[i]);
    int yep = 0;
    rep(i, 0, 4){
        if(mn==pts[i]){
            if(yep) printf(" ");
            printf("%d", i+1);
            yep = 1;
        }
    } printf("\n");



    return  0;
}
