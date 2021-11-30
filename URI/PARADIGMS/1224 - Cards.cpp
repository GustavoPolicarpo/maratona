// Author: Gustavo Policarpo
// Name: Cards
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1224

#define gc getchar_unlocked
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
#define MAXN 100001
#define mod 1000000007
#define error 1e-7

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/


//
//

ll mat[10010][3], aux[10010][3], pd[10010];
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; 
	while(scanf("%d", &N)!=EOF){
		rep(i, 0, N){
			scanf("%lld", &pd[i]);
		}

		if(N==2){
			printf("%lld\n", max(pd[0], pd[1]));
			continue;
		}
		
		mat[0][0]=pd[0];
		mat[1][1]=pd[1];
		mat[0][1]=max(pd[0], pd[1]);
			
		for(int j=2; j<N; j++){
			mat[j][2]=pd[j];
			mat[j-1][2]=max(pd[j-1], pd[j]);

			for(int i=j-2; i>=0; i--){	
				aux[i][2]=pd[j]+min(mat[i][0], mat[i+1][1]);
				mat[i][2]=pd[i]+min(mat[i+2][2], mat[i+1][1]);
				mat[i][2]=max(mat[i][2], aux[i][2]);
			}

			rep(i, 0, N){
				mat[i][0]=mat[i][1];
				mat[i][1]=mat[i][2];
			}
			
		}
		
		printf("%lld\n", mat[0][2]);		
	}	
	
	return 0;	
}
