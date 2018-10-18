// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Arqueologia Congelante
// Nível: 7
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1859

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
typedef pair < int, ll > ii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 
const int MAX = 10000*2*60;
 
int gap, tam, sa[MAX], pos[MAX], lcp[MAX], tmp[MAX];
int ranki[MAX], sz[MAX], N, P, g[55][55];
 
bool sufixCmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	i+=gap, j+=gap;
	return (i<tam && j<tam) ? pos[i]<pos[j] : i>j;
}
	    
void buildSA(char s[]){
	tam=strlen(s);
	for(int i=0; i<tam; i++) 
		sa[i]=i, pos[i]=s[i], tmp[i]=0;
	for(gap=1;tmp[tam-1]!=tam-1;gap*=2){
		sort(sa, sa+tam, sufixCmp);
		for(int i=0; i<tam-1; i++)
			tmp[i+1] = tmp[i] + sufixCmp(sa[i], sa[i+1]);
		for(int i=0; i<tam; i++)
			pos[sa[i]]=tmp[i];
	}
}

void buildLCP(char s[]){
	for(int i=0, k=0; i<tam; i++){
		if(pos[i]==tam-1) continue;
		for(int j=sa[pos[i]+1]; s[i+k]==s[j+k];) k++;
		lcp[pos[i]] = k;
		if(k) --k;
	}
}

void buildRS(char s[]){
	int k=-1, len=1;
	for(int i=tam-1; i>=0; i--){
		if(s[i]<'A'){
			ranki[i]=-1; sz[i]=-1;
			len=1; k++;
		}else{
			ranki[i]=k;
			sz[i]=len++;
		}
	}
}
 
void printal(char text[]){
	cout << "\t" << text << '\n';
	printf("I \tSA\tRK\tSZ\tLCP\tSuffix\n");
	rep(i, 0, tam)
		printf("%2d\t%2d\t%2d\t%2d\t%2d\t%s\n", i, sa[i], ranki[sa[i]], sz[sa[i]], lcp[i], text + sa[i]);
}

int v[MAXV], w[MAXV];
bool a[MAXV];

int stoer_wagner(){
	
	int n = N;
	
	rep(i, 0, n) v[i]=i;
	
	int best=0x3f3f3f3f;
	
	while(n>1){
		a[v[0]] = true;
		rep(i, 1, n){
			a[v[i]]=false;
			w[i]=g[v[0]][v[i]];
		}
		
		int prev = v[0];
		rep(i, 1, n){
			int zj=-1;
			rep(j, 1, n)
				if(!a[v[j]] && (zj<0 || w[j] > w[zj]))
					zj=j;
			
			a[v[zj]] = true;
			
			if(i==n-1){
				best=min(best, w[zj]);
				
				rep(j, 0, n)
					g[v[j]][prev]=g[prev][v[j]]+=g[v[zj]][v[j]];
				v[zj]=v[--n];
				break;
			}
			prev = v[zj];
			
			rep(j, 1, n)
				if(!a[v[j]])
					w[j]+=g[v[zj]][v[j]];
		}
	}
	
	return best;
	
}

void solve(char text[], int xuaca){
	
	//printal(text);
	
	int i = 0;
	while(text[sa[i]]<'A') i++;
	
	stack <ii> st;
	for(; i<tam; i++){
		if(lcp[i]*100>=xuaca*P && (!st.size() || lcp[i]>=lcp[st.top().F]))
			st.push(ii(i, 1LL<<ranki[sa[i]]));
		else{
			ll mask = 1LL<<ranki[sa[i]];
			while(st.size() && lcp[st.top().F] > lcp[i]){
				rep(j, 0, N){
					if(mask&(1LL<<j)) continue;
					if(st.top().S&(1LL<<j)){
						rep(k, 0, N){
							if(mask&(1LL<<k)){
								g[j][k] = g[k][j] = 1;
							}
						}
					}
				}
				mask|=st.top().S;
				st.pop();
			}
			if(lcp[i]*100>=xuaca*P) st.push(ii(i, mask));
		}
	}
	
	ll mask = 0;
	while(st.size()){
		rep(j, 0, N){
			if(mask&(1LL<<j)) continue;
			if(st.top().S&(1LL<<j)){
				rep(k, 0, N){
					if(mask&(1LL<<k)){
						g[j][k] = g[k][j] = 1;
					}
				}
			}
		}
		mask|=st.top().S;
	}
	
	/*rep(i, 0, N){
		rep(j, 0, N){
			cout << g[i][j] << " ";
		}
		cout << '\n';
	}*/
	
	printf("%d\n", stoer_wagner());
}

char text[MAX], s[MAX];

int main()
{
	
	scanf("%d %d", &N, &P);
	int aux = -1, cnt = 1;
	rep(i, 0, N){
		scanf("%s", s);
		if(i==0) aux = strlen(s);
		rep(j, 0, aux) text[tam++] = s[j];
		rep(j, 0, aux) text[tam++] = s[j];
		text[tam++] = cnt++;
	}	text[tam] = '\0';
	
	buildSA(text);
	buildLCP(text);
	buildRS(text);
	solve(text, aux);
	
	return 0;
}
