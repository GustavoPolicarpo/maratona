// Author: Gustavo Policarpo
// Name: Compare Substring
// Level: 6
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1237

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
	string a, b;
	while(getline(cin, a)){
		getline(cin, b); int out=0, aux;
		rep(i, 0, a.size()){
			rep(j, 0, b.size()){
				aux=0;
				if(a[i]==b[j]){
					int u=i, v=j;
					while(a[u]==b[v]){
						aux++, u++, v++;
						if(u==a.size() || v==b.size()) break;
					}
					if(aux>out) out=aux;
				}	
			}
		}
		cout << out << endl;
	}
return 0;
}
