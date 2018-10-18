// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude Seu Madruga
// Nível: 1
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1912

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
#define error 0.0001

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


int N, A, n[1000001];
int main(){
    while(1){
    	scanint(N), scanint(A);
    	if(!N) break;
        int aux, st=0; 
        rep(i, 0, N){
            scanint(n[i]);
            st+=n[i];
        }
        if(st<A){
            printf("-.-\n");
            continue;
        }
        else if(st==A){
            printf(":D\n");
            continue;
        }
        sort(n, n+N);
        bool yep=false;
        double ini=0.0, fim=100001.0, atual=(ini+fim)/2.0;
        int cnt=101;
        while(cnt--){
            double at=0.0;
            int p=lower_bound(n, n+N, ceil(atual)) - n;
            rep(i, p, N){
                if(n[i]>atual){
                	at+=(n[i]-atual);
                }
            }
            if(fabs(at-A)<error){
                printf("%.4lf\n", atual);
                yep=true;
                break;
            }
            if(at<A){
                fim=atual;
                atual=(fim+ini)/2.0;
            }
            if(at>A){
                ini=atual;
                atual=(fim+ini)/2.0;
            }
        }
        if(yep) continue;
        printf("%.4lf\n", atual);
    }
    return 0;
}
