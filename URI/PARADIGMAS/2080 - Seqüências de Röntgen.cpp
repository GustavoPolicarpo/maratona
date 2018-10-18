// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Seqüências de Röntgen
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2080

#define gc getchar
#define pc(x) putchar(x);
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

char s[2000200], ss[2000200];

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	int T; cin >> T;
	while(T--){
		int k, p, fim, cnt; char let;
		scanf("%s %d", s, &k);
		
		printf("%s\n", s); fim=strlen(s);
		while(k--){
			
			p=0, cnt=1, let=s[0];
			
			rep(i, 1, fim){
				if(s[i]!=let){
					printf("%d%c", cnt, let);
					if(cnt>9){
						string sss;
						while(cnt){
							sss+=cnt%10 + '0';
							cnt/=10;
						}	reverse(sss.begin(), sss.end());
						rep(j, 0, sss.size()) ss[p++] = sss[j];
					}
					else ss[p++]=cnt+'0';
					
					ss[p++]=let;
					cnt=1, let=s[i];
				}
				else cnt++;
			}
			
			printf("%d%c", cnt, let);
			if(cnt>9){
				string sss;
				while(cnt){
					sss+=cnt%10 + '0';
					cnt/=10;
				}	reverse(sss.begin(), sss.end());
				rep(j, 0, sss.size()) ss[p++] = sss[j];
			}
			else ss[p++]=cnt+'0';
			ss[p++]=let;
			
			printf("\n");
			s[p]='\0';
			
			rep(i, 0, p) s[i]=ss[i];
			fim=p;
		}
		
		if(T) printf("\n");
	}

	return 0;
	
}
