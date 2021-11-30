// Author: Gustavo Policarpo
// Name: The Wrath of Khan
// Level: 10
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1964

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;
#define INF 0x3f3f3f3f



int main(){
	
	int c, va, vb, t, d;
	cin >> c >> va >> vb >> t >> d;
	
	c*=100, d*=100, t*=60;
	
	int pa=(va*t)%c;
	int pb=(vb*t)%c;
	
	int da=d-pa; if(da<0) da+=c;
	int db=d-pb; if(db<0) db+=c;
	
	double ta=double(da)/va;
	double tb=double(db)/vb;
	
	if(ta<=tb) puts("Ana");
	else puts("Bia");
	
	return 0;
	
}
