// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Eleições
// Nível: 2
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2084

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
	int N; cin >> N;
	double c[N]; double m=0, total=0;
	rep(i, 0, N){
		cin >> c[i];
		total+=c[i];
		if(c[i]>m) m=c[i];
	}
	double pm=m*100.0/total;
	if(pm>=45){
		cout << 1 << endl;
		return 0;
	}
	if(pm<40){
		cout << 2 << endl;
		return 0;
	}

	rep(i, 0, N){
		if(m==c[i]) continue;
		
		if(pm<c[i]*100.0/total+10){
			cout << 2 << endl;
			return 0;
		}
	}
	cout << 1 << endl;
	
return 0;
}
