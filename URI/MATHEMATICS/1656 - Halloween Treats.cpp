// Author: Gustavo Policarpo
// Name: Halloween Treats
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1656

#include <iostream>

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
#define mod 1000000007

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int n, c;
	while(scanf("%d %d", &c, &n) and c+n){
		int v[n]; 
		rep(i, 0, n) scanf("%d", &v[i]);
		if(c==1){
			printf("1\n");
			continue;
		}
		int sum[n], id[c]; sum[0]=v[0]%c; rep(i, 0, c) id[i]=-1;
		id[sum[0]]=1;
		rep(i, 1, n){
			sum[i]=(sum[i-1]+v[i])%c;
			//cout << i << " " << sum[i] << endl;
			if(sum[i]==0){
				printf("1");
				rep(j, 1+1, i+2) printf(" %d", j);
				break;
			}
			if(id[sum[i]]!=-1){
				printf("%d", id[sum[i]]+1);
				rep(j, id[sum[i]]+1, i+1) printf(" %d", j+1);
				break;
			}
			id[sum[i]]=i+1;
		}
		
		printf("\n");
	}
	
return 0;

}
