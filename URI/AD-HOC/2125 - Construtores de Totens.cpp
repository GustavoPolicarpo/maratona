// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Construtores de Totens
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2125

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

int N, M, resp[1010][1010];
vector<int> T(62+2);
vector <ll> text(1010+2), pattern(62+2);
char tx[1010][1010], pt[66][66];

void KMP(int line){
	
    int k = 0;
    int began=0;
    if(line) began=M-1;
    
    rep(i, 0, N)
    {
    	text[i]/=2;
    	rep(j, began, M){
    		if(tx[line+j][i]=='|'){
				text[i]+=(1LL<<j);
			}
		} 	
		
        while( ~k && text[i] != pattern[k] ) k = T[k];
        ++k;
        if( k == M ) k = T[k], resp[line][i-M+1]=1;
        
    }
    
    return;
    
}

void preprocess(){
	
	rep(i, 0, M) pattern[i]=0;
	rep(i, 0, N){
		text[i]=0;
		rep(j, 0, N) resp[i][j]=0;
	}
	
	int kk = T[0] = -1;
    rep(i, 0, M)
    {
		rep(j, 0, M){
			if(pt[j][i]=='|'){
				pattern[i]+=(1LL<<j);
			}
		}
		
        while( ~kk && pattern[i] != pattern[kk] ) kk = T[kk];
        T[i + 1] = ++kk;
    }
    
    return;
    
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int z=1;
	
	while(scanf("%d %d ", &N, &M) !=EOF){
		
		rep(i, 0, N) scanf("%s", tx[i]);
		rep(i, 0, M) scanf("%s", pt[i]);
		
		preprocess();
		rep(i, 0, N-M+1) KMP(i);
		
		int yep=0;		
		printf("Instancia %d\n", z++);
		rep(j, 0, N) rep(i, 0, N) if(resp[i][j]) printf("%d %d\n", i, j), yep=1;
		if(!yep) printf("nenhuma ocorrencia\n");
		printf("\n");
		
	}
    
    return 0;
    
}
