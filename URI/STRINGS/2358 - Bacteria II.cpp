// Author: Gustavo Policarpo
// Name: Bacteria II
// Level: 10
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2358

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
typedef pair < int, int > ii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);
 
const int MAX = 10000*22;
 
int gap, tam, sa[MAX], pos[MAX], lcp[MAX], tmp[MAX];
int ranki[MAX], sz[MAX], N;
 
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

void solve_cp(char text[]){
	
	//printal(text);
	
	int ans=0, pos=0, i = 0;
	while(text[sa[i]]<'A') i++;
	
	stack <ii> st;
	for(; i<tam; i++){
		if(!st.size() || lcp[i]>=lcp[st.top().F]) st.push(ii(i, 1<<ranki[sa[i]]));
		else{
			int mask = 1<<ranki[sa[i]];
			while(st.size() && lcp[st.top().F] > lcp[i]){
				mask|=st.top().S;
				if(mask == (1<<N)-1){
					if(ans<lcp[st.top().F]){
						ans = lcp[st.top().F];
						pos = st.top().F;
					}
					else if(ans==lcp[st.top().F]) pos = min(pos, st.top().F);
				}
				st.pop();
			}
			if(lcp[i]) st.push(ii(i, mask));
		}
	}
	
	int mask = 0;
	while(st.size()){
		mask |= st.top().S;
		if(mask == (1<<N)-1){
			if(ans<lcp[st.top().F]){
				ans = lcp[st.top().F];
				pos = st.top().F;
			}
			else if(ans==lcp[st.top().F]) pos = min(pos, st.top().F);
		}
		st.pop();
	}
	
	rep(i, sa[pos], sa[pos]+ans) cout << text[i]; cout << '\n';
	//cout << ans << " " << pos << '\n';
}

char tex[MAX];
int main()
{
	while(scanf("%d", &N)!=EOF){
		vector <string> in; string s, p;
		
		rep(i, 0, N){
			cin >> s;
			in.pb(s);
		}
		cin >> p;
		
		int t = 0, cnt = 1;
		rep(i, 0, N){
			s = in[i];
			while(42){
				int pos = s.find(p);
				if(pos>=0 && pos<s.size())
					s.erase(s.begin()+pos, s.begin()+pos+p.size());
				else
					break;
			}
			rep(j, 0, s.size()) 
				tex[t++] = s[j];
			tex[t++] = cnt++;
		}	tex[t++] = '\0';
		
		if(N==1){
			rep(i, 0, t-2) cout << tex[i]; cout << '\n';
			continue;
		}
		buildSA(tex);
		buildLCP(tex);
		buildRS(tex);
		solve_cp(tex);
	}
	
	return 0;
}
