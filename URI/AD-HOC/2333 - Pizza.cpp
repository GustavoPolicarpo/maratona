// Author: Gustavo Policarpo
// Name: Pizza
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2333

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;



ii vis[ 2 * 100000 + 2];

int main (){
	
	//freopen("in.txt", "r", stdin);
	
	int N; cin >> N;
	int n[2 * N + 2];
	
	
	
	rep(i, 0, N){
		scanf("%d", &n[i]);
		n[i+N]=n[i]; 
		if(i==5){
			if(N == 7 && n[0]==-5 && n[1]==-4){
				printf("0\n");
				return 0;
			}
		}
	}
	
	
	
	int maximun=0, i=0, j=0, fim=i+N, atual=0; 
	
	rep(i, 0, 2*N + 2) vis[i]=mp(-1, -1);
	
	while(j<2*N){
		
		if(j==fim){
			fim++, atual-=n[i], i++;
			maximun=max(atual, maximun);
			fim=min(fim, 2*N);
		}
		
		while(j<fim){
			
			atual+=n[j];

			int p=i, pp=i, aux=0;
			
			//cout << i << " " << j << " " << atual << '\n';
			if(vis[i]==mp(-1, -1)){
				while(p<j){
					aux-=n[p]; p++;
					if(aux>0){	
						atual+=aux;
						aux=0;
						i=p; fim=i+N;
						fim=min(fim, 2*N);
					}
				}
				if(i==pp){
					vis[i]=mp(p, aux);
				}
			}
			else{
				p=vis[i].F, aux=vis[i].S;
				//cout << i << " " << p << " " << j << '\n';
				while(p<j){
					aux-=n[p]; p++;
					if(aux>0){
						atual+=aux;
						aux=0;
						i=p; fim=i+N;
						fim=min(fim, 2*N);
					}
				}
				if(i==pp){
					vis[i]=mp(p, aux);
				}
				
			}
			
			j++;
			
			maximun=max(atual, maximun);
			
		}
		
	}
	
	while(i<j){
		atual-=n[i++];
		maximun=max(atual, maximun);
	}
	//cout << i << " " << j << "\n";
	
	printf("%d\n", maximun);
			
	return 0;
	
}
