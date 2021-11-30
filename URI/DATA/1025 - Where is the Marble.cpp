// Author: Gustavo Policarpo
// Name: Where is the Marble?
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1025

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


int main()
{
	//freopen("out.txt", "w", stdout);
	int N, M, z=1;
	while(cin >> N >> M && N+M){
		int Q[N];
		rep(i, 0, N)
			cin >> Q[i];
		
		sort(Q, Q+N);
		
		bool mark=true;
		while(M--){
			int k, found=-1;
			cin >> k;
			int ini=-1, fim=N, meio=fim/2;
			while(fim-ini>1){
				//cout << ini << " " << fim << " " << meio << " " << Q[meio] << endl;
				if(Q[meio]==k){
					found=meio;
					while(meio--){
						if(Q[meio]==k) found=meio;
						else break;
					}
				}
				if(found!=-1) break;
				if(Q[meio]>k)
					fim=meio, meio=(ini+meio)/2;
				else 
					ini=meio, meio=(fim+meio)/2;	
			}
			if(mark) printf("CASE# %d:\n", z++), mark=false;
			if(found==-1) printf("%d not found\n", k);
			else printf("%d found at %d\n", k, found+1);
		}
		
		
	}
return 0;
}
