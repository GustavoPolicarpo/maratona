// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Codifique a Árvore
// Nível: 6
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1735

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef pair < int, int > ii;

int grau[105], edg[105][105], vet[105];

int main()
{
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	string s;
	
	while(getline(cin, s)){
		
		if(s.empty()) break;
		//cout << s << '\n';
		
		memset(grau, 0, sizeof grau);
		memset(edg, 0, sizeof edg);
		
		int p=0, i=0, n=0; 
		while(i<s.size()){
			
			if(isdigit(s[i])){
				vet[p]=0;
			    while(isdigit(s[i])) vet[p]*=10, vet[p]+=s[i++]-'0';
			    edg[vet[p]][vet[p-1]]=edg[vet[p-1]][vet[p]]=1;
			    grau[vet[p-1]]++, grau[vet[p]]++;
			    n=max(n, vet[p]);
			}
			
			while(s[i]==' ') i++;
			
			if(s[i]=='('){
				p++, i++;
				continue;
			}
			
			if(s[i]==')'){
				p--, i++;
				continue;
			}
			
		}	grau[vet[1]]--;
		
		if(n==1){
			puts("");
			continue;
		}
		
		/*rep(i, 1, 10){
			rep(j, 1, 10) cout << edg[i][j] << " ";
			cout << '\n';
		}*/
		//rep(i, 1, n+1) cout << grau[i] << " ";
		
		vector <int> out;
		while(out.size()<n-2){
			
			int yep=0;
			rep(i, 1, n+1){
				if(grau[i]==1){
					rep(j, 1, n+1){
						if(edg[j][i]){
							out.pb(j);
							edg[i][j]=edg[j][i]=0, grau[j]--, grau[i]=-1;
							//cout << i << " " << j << " " << grau[j] << '\n';
							break;
						}
					}
					yep=1;
					break;
				}
			}
			
			if(!yep) break;
			
		}
		
		rep(i, 0, out.size()) printf("%d ", out[i]); printf("%d\n", n);
		
	}
	
	
	return 0;
	
}
