// Author: Gustavo Policarpo
// Name: Guga and the String
// Level: 8
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1781

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
#define mod 1000000007
#define error 0.0001

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

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


int main(){
	//freopen("out.txt", "w", stdout);
    char s[1000001], use; int v, ov, c, oc, t, q, tam, aux;
    scanf("%d ", &t);
    rep(z, 1, t+1){
    	scanf("%s", &s); tam=strlen(s);
    	v=0, ov=0, c=0, oc=0; 
    	queue <char> vo, co;
    	while(!vo.empty()) vo.pop();
    	while(!co.empty()) co.pop();
    	rep(i, 0, tam){
    		if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u') v++, vo.push(s[i]);
    		else c++, co.push(s[i]);
		}
		printf("Caso #%d:\n", z);
    	scanf("%d", &q);
    	while(q--){
    		scanf("%d", &aux);
    		if(aux==0){
    			scanf("%d", &aux);
    			ov+=aux;
			}
			else if(aux==1){
				scanf("%d", &aux);
				oc+=aux;
			}
			else{	
				if(v==0) ov=0;
				else ov%=v;
				
				if(c==0) oc=0;
				else oc%=c;
				
				ov=v-ov, oc=c-oc;
				
				while(!vo.empty() && ov--){
					use=vo.front();
					vo.pop();
					vo.push(use);
				}
				while(!co.empty() &&  oc--){
					use=co.front();
					co.pop();
					co.push(use);
				}
				rep(i, 0, tam){
					if(s[i]=='a'||s[i]=='e'||s[i]=='i'||s[i]=='o'||s[i]=='u'){
						use=vo.front(); vo.pop();
						printf("%c", use);
						vo.push(use);
					}
					else{
						use=co.front(); co.pop();
						printf("%c", use);
						co.push(use);
					}					
				}	
				ov=v, oc=c;
				printf("\n");
			}
		}
    	
	}
    
}

