// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Maior Palíndromo Comum Vo...
// Nível: 8
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1503

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < ll, ii > iii;

const int INF = 0x3f3f3f3f;
const ll LINF = 1LL<<58;


const int MAX = 505000;
int gap, tam, sa[MAX], pos[MAX], lcp[MAX], tmp[MAX];
 
bool sufixCmp(int i, int j){
	if(pos[i]!=pos[j]) return pos[i]<pos[j];
	i+=gap, j+=gap;
	return (i<tam && j<tam) ? pos[i]<pos[j] : i>j;
}
void buildSA(char s[]){
	tam=strlen(s);
	for(int i=0; i<tam; i++) 
		sa[i]=i, pos[i]=s[i], tmp[i]=0;
		
	for(gap=1;;gap*=2){
		sort(sa, sa+tam, sufixCmp);
		tmp[0]=0;
		for(int i=0; i<tam-1; i++)
			tmp[i+1] = tmp[i] + sufixCmp(sa[i], sa[i+1]);
		for(int i=0; i<tam; i++)
			pos[sa[i]]=tmp[i];
		if(tmp[tam-1] == tam-1) break;
	}
}
ll buildLCP(char s[]){
	ll sum=0;
	for(int i=0, k=0; i<tam; i++){
		if(pos[i]==tam-1) continue;
		for(int j=sa[pos[i]+1]; s[i+k]==s[j+k];) k++;
		lcp[pos[i]+1] = k;
		sum+=k;
		if(k>0) k--;
	}
	return sum;
}


string preProcess(string s) {
	int n = s.length();
	if (n == 0) return "^$";
	
	string ret = "^";
	for (int i = 0; i < n; i++)
		ret += "#" + s.substr(i, 1);
	ret += "#$";
	
	return ret;
}
 
int longestPalindrome(string s){
	string T = preProcess(s);
	int n = T.length();
	int *P = new int[n];
	int C = 0, R = 0;
	
	for (int i = 1; i < n-1; i++) {
		
		int i_mirror = 2*C-i;
	
		P[i] = (R > i) ? min(R-i, P[i_mirror]) : 0;
	
		while (T[i + 1 + P[i]] == T[i - 1 - P[i]]) P[i]++;
		
		if (i + P[i] > R) {
			C = i;
			R = i + P[i];
		}
		
	}
	
	int maxLen = 0;
	int centerIndex = 0;
	
	//cout << T << '\n';
	for (int i = 1; i < n-1; i++) {
		if(!P[i]) continue;
			
		if (P[i] > maxLen) {
			maxLen = P[i];
			centerIndex = i;
		}
	}
	
	delete[] P;
	
	//cout << s.substr((centerIndex - 1 - maxLen)/2, maxLen) << '\n';
	return maxLen;
}

int ranki[MAX], sz[MAX];

void init(int n){
	rep(i, 0, n){
		sa[i]=0,
		pos[i]=0,
		tmp[i]=0,
		lcp[i]=0,
		ranki[i]=0,
		sz[i]=0;
	}
}

int tree[MAX*4+4];
void build(int no, int i, int j){
	if(i==j){
		tree[no]=lcp[i];
		return;
	}
	int mid=(i+j)/2, L=no*2, R=no*2+1;
	build(L, i, mid);
	build(R, mid+1, j);
	tree[no]=min(tree[L], tree[R]);
}
int query(int no, int i, int j, int a, int b){
	
	if(i>b || j<a || i>j) return INF;
	if(i>=a && j<=b) return tree[no];
	
	int mid=(i+j)/2, L=no*2, R=no*2+1;
	int SA=query(L, i, mid, a, b);
	int SB=query(R, mid+1, j, a, b);
	return min(SA, SB);
}


void build(){
	
}
int solve(char text[], int qt){
	int k=1, len=1;
	for(int i=tam; i>=0; i--){
		if(text[i]>=125 || text[i]<97){
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
	
	build(1, 0, tam+2);
	
	int i=0, j=0, maior=0;
	map<int, int> mapa;

	while(j<tam){
		
		while(j<tam && ranki[sa[j]]==0) j++;
		while(i<tam && ranki[sa[i]]==0) i++;
		mapa[ranki[sa[j]]]++;
		
		while(1){
			if(mapa[ranki[sa[i]]]-1>0){
				mapa[ranki[sa[i++]]]--;
			}else{
				break;
			}
		}
		
		if(mapa.size()==qt){
			int ma=query(1, 0, tam+2, i+1, j);
			if(ma>maior){
				string at;
				rep(k, sa[i], sa[i]+ma) at.pb(text[k]);
				//cout << at << '\n';
				maior=max(maior, longestPalindrome(at));
			}
		}
		j++;
	}
	
	return maior;
	
	/*cout << "\t" << text << '\n';
	printf("SA\tRK\tSZ\tLCP\tSuffix\n");
	rep(i, 0, tam)
		printf("%2d\t%2d\t%2d\t%2d\t%s\n", sa[i], ranki[sa[i]], sz[sa[i]], lcp[i+1], text + sa[i]);
		return;
	
	rep(i, 0, tam){
		if(lcp[i+1]>maior){
			int j=i+1, aux=lcp[i+1]; set<int> st; st.insert(ranki[sa[i]]), st.insert(ranki[sa[j]]);
			while(1){
				if(st.size()>=qt) break;
				if(j==tam || lcp[j+1]<=maior) break;
				aux=min(aux, lcp[j+1]);
				st.insert(ranki[sa[j+1]]);
				j++;
			}
			if(st.size()>=qt){
				string at;
				rep(j, sa[i], sa[i]+aux) at.pb(text[j]);
				aux=longestPalindrome(at);
				if(aux>maior){
					maior=aux;
				}
			}
		//	i=j-1;
		}
	}
	
	return maior;*/
	
}


char s[MAX];

int main(){
	
	int n, yep=0;
	
	while(scanf("%d", &n)!=EOF){
		
		char aux[50050]; int p=0, ca=125;
		
		rep(i, 0, n){
			scanf("%s", aux);
			int fim=strlen(aux);
			rep(j, 0, fim) s[p++]=aux[j];
			s[p++]=ca++;
			if(ca==200) ca=15;
		}	s[p]='\0';
		
		if(n==1){
			cout << longestPalindrome(s) << '\n';
			continue;
		}
		
		init(p+10);
		
		buildSA(s);
		buildLCP(s);
		cout << solve(s, n) << '\n';
		
	}
	
	return 0;
	
}
