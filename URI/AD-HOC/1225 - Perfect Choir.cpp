// Author: Gustavo Policarpo
// Name: Perfect Choir
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1225

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
#define MAXV 100001
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N;
	while(scanf("%d", &N)!=EOF){
		int n[N], i=0, j=N-1, sum=0;
		rep(i, 0, N){
			scanint(n[i]);
			sum+=n[i];
		} 
		if(sum%N!=0){
			printf("-1\n");
			continue;
		}
		int media=sum/N, l, r, aux, out=1;
		while(i<j){
			if(n[i]<media){
				aux=media-n[i];
				n[i]+=aux;
				out+=aux;
			}
			i++;
			while(aux>0){
				n[j]-=aux;
				if(n[j]>media){
					aux=0;
				}
				else{
					aux=n[j]-media, j--;
				}	
			}
		}
		printf("%d\n", out)	;
	}
						
return 0;
}
