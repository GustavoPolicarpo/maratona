// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Recuperação de Arquivos
// Nível: 7
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1335

#include <bits/stdc++.h>
 
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
typedef pair < int, ll > ii;
typedef pair < int, ii > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 
const int MAX = 600060;
 
int gap, tam, sa[MAX], pos[MAX], lcp[MAX], tmp[MAX];
 
bool sufixCmp(int i, int j){
	
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	
	i+=gap, j+=gap;
	
	return (i<tam && j<tam) ? pos[i]<pos[j] : i>j;
	
}
 
void buildSA(char s[]){
	
	tam=strlen(s);
	for(int i=0; i<tam; i++)
		sa[i]=i, pos[i]=s[i], tmp[i]=0, lcp[i]=0;
		
	for(gap=1;;gap*=2){
		sort(sa, sa+tam, sufixCmp);
		tmp[0]=0;
		
		for(int i=0; i<tam-1; i++)
			tmp[i+1] = tmp[i] + sufixCmp(sa[i], sa[i+1]);
			
		for(int i=0; i<tam; i++)
			pos[sa[i]]=tmp[i];
			
		if(tmp[tam-1] == tam-1) break;
	}
	
	return;
	
}
 
ll buildLCP(char s[]){
	
	ll sum=0;
	for(int i=0, k=0; i<tam; i++){
		if(pos[i]==tam-1) continue;
		
		for(int j=sa[pos[i]+1]; s[i+k]==s[j+k];) k++;
		
		lcp[pos[i]] = k;
		sum+=k;
		
		if(k>0) k--;
	}
	
	return sum;
	
}
 
int ranki[MAX], sz[MAX];
int solve_cp(char text[]){
	
	int k=-1, len=1;
	for(int i=tam-1; i>=0; i--){
		if(text[i]<'a'){
			ranki[i]=0;
			sz[i]=0;
			len=1;
			k++;
		}
		else{
			ranki[i]=k;
			sz[i]=len++;
		}
	}
	
	/*cout << "\t" << text << '\n';
	printf("SA\tRK\tSZ\tLCP\tSuffix\n");
	rep(i, 0, tam)
		printf("%2d\t%2d\t%2d\t%2d\t%s\n", sa[i], ranki[sa[i]], sz[sa[i]], lcp[i], text + sa[i]);*/
			
	set <ll> vis; 
	int p=0;
	while(text[sa[p]]<'a') p++; 
	
	stack <ii> s;
	ll ans=0, atual; ii tp;
	for(; p<tam; p++){
		
		if(lcp[p] != sz[sa[p]] && lcp[p-1] < sz[sa[p]]){
			//cout << ranki[sa[p]] << '\n';
			vis.insert(1LL << ranki[sa[p]]);
		}
		
		ll last = 0;
        while(!s.empty() && (s.top().F > lcp[p] || lcp[p] == 0)){
            tp = s.top(); s.pop();
			
			//cout << p << "    " << tp.S << '\n';
            vis.insert(tp.S);
            
            if (!s.empty())
                s.top().S |= tp.S;
            
            last = tp.S;
        }
        
        if(lcp[p]){ 
            if (s.empty() || s.top().F < lcp[p]){
            	s.push(mp(lcp[p], ( (1LL << ranki[sa[p+1]]) | (1LL << ranki[sa[p]]) | last) ));
            	//cout << ((1LL << ranki[sa[p+1]]) | (1LL << ranki[sa[p]]) | last) << '\n';
            }
			else if(s.top().F == lcp[p]){
                s.top().S |= 1LL << ranki[sa[p+1]];   
            } 
        }
	}
	
	while(!s.empty()) {
        tp = s.top(); s.pop();

        vis.insert(tp.S);
        
        if (!s.empty())
            s.top().S |= tp.S;
    }
	
	return vis.size();
}

char in[MAX], s[MAX];
int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(1){
		
		int N; scanf("%d", &N);
		if(!N) break;
		
		int p=0, pp=1;
		while(N--){
			scanf("%s", in);
			rep(i, 0, strlen(in)) s[p++]=in[i]; s[p++]=pp++;
		}	s[p++]='\0';
		
		buildSA(s);
		ll m=buildLCP(s);
		printf("%d\n", solve_cp(s));
		
	}
 
return 0;
 
}
