// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: O Salão do Clube
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1086

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
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


int N, M, L, K, fim, aux, k[100001]; 
int main(){
	
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &N, &M) and N){
		scanf("%d %d", &L, &K);
		fim=0;
		memset(k, 0, sizeof k);
		rep(i, 0, K){
			scanf("%d", &aux);
			if(aux>fim) fim=aux;
			k[aux]++;
		}	k[0]=INF;
		
		bool y1=false, y2=false;
		
		int c1=0, c2=0, p1=0, p2=0;
		
		if(M*100%L==0){
			int i=0, j=fim, nt=M*100/L;
			
			aux=min(k[N], nt);
			p1+=aux, c1+=aux;
			
			while(j>N) j--;
			while(i+j<N) i++;
			if(i==0 && j==N) i++, j--;		
			while(i<j-1 && p1<nt){
				aux=min(nt-p1, min(k[i], k[j]));
				p1+=aux, c1+=2*aux, i++, j--;
			
			}
			if(i==j){
				aux=min(nt-p1, k[i]/2);
				p1+=aux, c1+=2*aux; 
			}
			if(p1==nt) y1=true;
		}
		if(N*100%L==0){
			int i=0, j=fim, nt=N*100/L;
			
			aux=min(k[M], nt);
			p2+=aux, c2+=aux;
			
			while(j>M) j--;
			while(i+j<M) i++;
			if(i==0 && j==M) i++, j--;
			//cout <<i << " " << j << " " << p2 << " " << c2 << endl;
			while(i<j-1 && p2<nt){
				aux=min(nt-p2, min(k[i], k[j]));
				p2+=aux, c2+=2*aux, i++, j--;
				
			}
			if(i==j){
				aux=min(nt-p2, k[i]/2);
				p2+=aux, c2+=2*aux; 
			}
			if(p2==nt) y2=true;
		}
		
		if(!y2 && !y1) printf("impossivel\n");
		else{
			if(!y1) printf("%d\n", c2);
			else if(!y2) printf("%d\n", c1);
			else printf("%d\n", min(c1, c2));
		}
	}	
}
