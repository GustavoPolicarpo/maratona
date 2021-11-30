// Author: Gustavo Policarpo
// Name: Voting at Yekaterinburg
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2122

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
typedef pair < double, int > iii;

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


struct cand{
	int votos, pref[101], id;
};
cand vet[101]; int N, K, V, l, aux;
bool comp(cand a, cand b)
{
	if(a.votos>b.votos) return true;
	if(b.votos>a.votos) return false;
	
	rep(i, 0, 101){
		if(a.pref[i]>b.pref[i]) return true;
		if(b.pref[i]>a.pref[i]) return false;
	}
	
	if(a.id<b.id) return true;
	return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d %d %d", &N, &K, &V) !=EOF){
		rep(i, 0, K){
			vet[i].id=i+1; vet[i].votos=0;
			memset(vet[i].pref, 0, sizeof vet[i].pref);
		}
		rep(i, 0, N){
			//scanf("%d", &l);	
			scanint(l);
			rep(j, 0, l){
				//scanf("%d", &aux);
				scanint(aux);
				aux--;
				if(aux>=K || aux<0 || j>=V) continue;
				vet[aux].votos++;
				vet[aux].pref[j]++;
			}
		}
		sort(vet, vet+K, comp);
		
		bool test=true;
		rep(i, 0, max(K, V)){
			if(i>=V){
				if(vet[i].votos<vet[i-1].votos) break;
				rep(j, 0, V){
					if(vet[i].pref[j]<vet[i-1].pref[j]){
						test=false;
						break;
					}
				}
				if(test) printf(" %d", vet[i].id);
				else break;
			}
			else{
				if(i>0) printf(" ");
				printf("%d", vet[i].id);
			}
		}
		printf("\n");
	}
	
return 0;
}
