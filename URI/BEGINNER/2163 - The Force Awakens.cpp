// Author: Gustavo Policarpo
// Name: The Force Awakens
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2163

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
#define error 1e-5

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int N, M, mat[1001][1001];
int dx[]={-1, -1, -1, 0, 0, 1, 1, 1},
	dy[]={-1, 0, 1, -1, 1, -1, 0, 1};
int main()
{
	vector <ii> p;
	scanf("%d %d", &N, &M);
	rep(i, 0, N)
	rep(j, 0, M){
		scanf("%d", &mat[i][j]);
		if(mat[i][j]==42){
			p.pb(mp(i, j));
		}
	}
	rep(i, 0, p.size()){
		bool yep=true;
		int x=p[i].F, y=p[i].S;
		rep(j, 0, 8){
			if(mat[x+dx[j]][y+dy[j]]!=7){
				yep=false;
				break;
			}
		}
		if(yep){
			printf("%d %d\n", x+1, y+1);
			return 0;
		}
	}
	printf("0 0\n");
	
	
return 0;
}
