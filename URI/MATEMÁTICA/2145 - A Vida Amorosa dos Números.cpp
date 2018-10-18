// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Vida Amorosa dos Números
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2145

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

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main()
{
	int N, M, sa, sb, fa, fb;
	while(scanf("%d %d", &N, &M) and N+M){
		sa=0, sb=0;
		fa=sqrt(N), fb=sqrt(M);
		int aa=0, bb=0;
		if(fa*fa!=N) aa=1;
		if(fb*fb!=M) bb=1;
		for(int i=1; i<=fa; i++){
			if(N%i==0){
				sa+=i;
				if(i%fa+aa!=0) sa+=N/i;//cout << fa << " " << sa << endl;
			}
		}
		sa-=N;
		//cout << sa << endl;
		for(int i=1; i<=fb; i++){
			if(M%i==0){	
				sb+=i;
				if(i%fb+bb!=0) sb+=M/i;
			}
		}
		sb-=M;
	//	cout << sb << endl;
		
		if((sa==M || M%sa==0) && (sb==N || N%sb==0))
			printf("Friends and lovers <3\n");
		else if(sa==sb) 
			printf("Almost lovers!\n");
		else if(M%sa==0)
			printf("%d friendzoned %d!\n", M, N);
		else if(N%sb==0)
			printf("%d friendzoned %d!\n", N, M);
		else
			printf("No connection.\n");
		
	}
          
return (0);	
}
