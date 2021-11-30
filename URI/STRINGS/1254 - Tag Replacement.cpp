// Author: Gustavo Policarpo
// Name: Tag Replacement
// Level: 4
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1254

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

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;

void scanint(ll &x)
{
    register ll ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);





int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	char comp[15], change[5], in[1010], out[2000]; 
	while(scanf("%s", comp)!=EOF){
		scanf("%s ", change);
		gets(in);
		//cout << comp << endl << change << endl << in << endl;
		int open=0, fim=strlen(in), ff=strlen(comp), cc=strlen(change), cnt=0;
		rep(i, 0, ff) comp[i]=tolower(comp[i]);
		rep(i, 0, fim){
			if(in[i]=='<') open++, out[cnt++]='<';
			else if(in[i]=='>') open--, out[cnt++]='>';
			else{
				if(isalpha(in[i])){
					if(!open){
						out[cnt++]=in[i];
						continue;
					}
					int j=0, yep=0;
					while(tolower(in[i+j])==comp[j]){
						j++;
						if(j==ff){
							yep=1;
							rep(k, 0, cc) out[cnt++]=change[k];
							i=i+ff-1;
							break;
						}
						if(j+i==fim) break;
					}
					if(!yep) out[cnt++]=in[i];
				}
				else out[cnt++]=in[i];
			}
		}
		rep(i, 0, cnt) cout << out[i];
		cout << '\n';
	}
	
return 0;

}
