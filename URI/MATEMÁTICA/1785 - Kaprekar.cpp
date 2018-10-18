// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Kaprekar
// Nível: 3
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1785

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 0x3F3F3F3F3F
#define mod 10000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int solve(int atual){
	
	int cnt=0;
	while(atual!=6174){
		string n="", maior, menor;
		while(atual){
			n+=atual%10+'0';
			atual/=10;
		}	
		while(n.size()<4) n+='0';
		if(n[0]==n[1] && n[1]==n[2] && n[2]==n[3]) return -1;
		
		sort(n.begin(), n.end());
		menor=n;
		reverse(n.begin(), n.end());
		maior=n;
		int m=0, mm=0;
		rep(i, 0, menor.size()){
			m*=10; 
			m+=menor[i]-'0';
		}
		rep(i, 0, maior.size()){
			mm*=10; 
			mm+=maior[i]-'0';
		}
		atual=mm-m;
		cnt++;
		//cout << aux << " " << menor << " " << maior << endl;	
	}	
	return cnt;
}

int main()
{
	int T, N; cin >> T;
	rep(z, 1, T+1){
		cin >> N;
		int out=solve(N);
		printf("Caso #%d: %d\n", z, out);	
	}
			
return 0;
}
