// Author: Gustavo Policarpo
// Name: Grandma's Day
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1591

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

char mat[51][51];
int main()
{
	int T; cin >> T;
	while(T--){
		int N, M; cin >> N >> M;
		map <string, int> use; string in;
		rep(i, 0, N)
		rep(j, 0, M){
			string aux="";
			cin >> mat[i][j];
			aux+=mat[i][j];
			use[aux]++;
		}
		rep(i, 0, N){
			rep(j, 0, M){
				rep(k, j+2, M+1){
					string aux="";
					rep(l, j, k){
						aux+=mat[i][l];
					}
					//cout << aux << endl;
					use[aux]++;	
				}
			}	
		}
		rep(i, 0, M){
			rep(j, 0, N){
				rep(k, j+2, N+1){
					string aux="";
					rep(l, j, k){
						aux+=mat[l][i];
					}
					//cout << aux << endl;
					use[aux]++;	
				}
			}	
		}
		int Q; cin >> Q;
		while(Q--){
			cin >> in; 
			cout << use[in] << endl;
		}
				
	}

return 0;
}
