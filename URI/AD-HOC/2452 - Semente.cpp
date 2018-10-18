// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Semente
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2452

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



int F, R;
int n[100010];

int main()
{
	scanf("%d %d", &F, &R);
	queue <ii> q;
	int aux, t, ans;
	rep(i, 0, R){
		scanf("%d", &aux);
		n[aux]=1;
		q.push(mp(aux, 1));
	}
	
	while(!q.empty()){
		aux=q.front().F, t=q.front().S; q.pop();
		
		ans=max(ans, t);
		
		if(aux-1 && !n[aux-1]){
			q.push(mp(aux-1, t+1));
			n[aux-1]=t+1;
		}
		
		if(aux+1<=F && !n[aux+1]){
			q.push(mp(aux+1, t+1));
			n[aux+1]=t+1;
		}
		
	}

	printf("%d\n", ans-1);
	
	return 0;
	
}
