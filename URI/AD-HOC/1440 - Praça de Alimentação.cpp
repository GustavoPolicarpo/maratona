// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Praça de Alimentação
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1440

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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;



int main()
{
    //freopen("in.txt", "r", stdin);
    //freopen("out.txt", "w", stdout);
    int N;
    while(scanf("%d", &N) and N){
    	int cnt=0;
    	vector <ii> time;
    	int h, m, s, op, tt; char n;
    	rep(i, 0, N){
    		scanf("%d:%d:%d %c", &h, &m, &s, &n);
    		tt=s+60*m+h*3600;
    		if(n=='E') op=1, cnt++;
    		else if(n=='X') op=2;
    		else op=3;
    		time.pb(mp(tt, op));
		}
		cnt=N/2-cnt; int out=1, aux=0;
		sort(time.begin(), time.end());
		rep(i, 0, N){
			tt=time[i].F, op=time[i].S;
			if(op==1){
				aux++;
			}
			else if(op==2){
				aux--;
			}
			else{
				if(cnt){
					aux++;
					cnt--;
				}
				else aux--;
			}
			out=max(out, aux);
		}
		printf("%d\n", out);
	}
    
    
return 0;
}


