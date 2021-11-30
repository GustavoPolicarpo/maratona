// Author: Gustavo Policarpo
// Name: Hello Galaxy
// Level: 1
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1515

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;




int main()
{
	int N, ano, tempo, mt; string in, out;
	while(scanf("%d", &N) && N){
		mt=INF;
		while(N--){
			cin >> in; scanf("%d %d", &ano, &tempo);
			if(ano-tempo<mt)
				out=in, mt=ano-tempo;	
		}
		cout << out << endl;
	}
	
return 0;
}
