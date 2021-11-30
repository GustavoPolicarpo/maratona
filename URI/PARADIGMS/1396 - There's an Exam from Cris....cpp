// Author: Gustavo Policarpo
// Name: There's an Exam from Cris...
// Level: 6
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1396

#include <bits/stdc++.h>
#define gc getchar
#define pc(x) putchar(x);
#include <ext/pb_ds/assoc_container.hpp>
#include <ext/pb_ds/tree_policy.hpp>
#include <ext/rope>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;
using namespace __gnu_pbds;
using namespace __gnu_cxx;

typedef tree <int, null_type, less<int>, rb_tree_tag, tree_order_statistics_node_update> ordered_set;

void scanint(int &x){
    register int ccc = gc(); x = 0; int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

typedef long long int ll;
typedef pair<int,int> ii;
typedef pair<int,ii> iii;
typedef pair<ii,ii> iiii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main(){
	
	int N, K, z=1;
	
	while(cin >> N >> K){
		
		if(!N && !K) break;
		
		vector <string> vin, vor; string s;
		
		rep(i, 0, N){
			cin >> s;
			vin.pb(s);
			vor.pb(s);
		}
		
		sort(vor.begin(), vor.end());
		
		rep(i, 0, vin.size()){
			rep(j, 0, vor.size()){
				int yep=1;
				rep(k, i, vin.size()){
					if(vin[k]==vor[j]){
						if(K >= k-i){
							K-=(k-i);
							while(k>i) swap(vin[k], vin[k-1]), k--;
							vor.erase(vor.begin()+j);
							break;
						}else{
							yep=0;
							break;
						}
					}
				}
				if(yep) break;
			}
		}
		
		printf("Instancia %d\n", z++);
		rep(i, 0, vin.size()){
			cout << vin[i] << " ";
		}	cout << "\n\n";
		
	}
	
}

