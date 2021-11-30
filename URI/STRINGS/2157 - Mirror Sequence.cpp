// Author: Gustavo Policarpo
// Name: Mirror Sequence
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2157

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
	int T, a, b; cin >> T; string out, temp;
	while(T--){
		scanf("%d %d", &a, &b); out="";
		rep(i, a, b+1){
			int aux=i; temp="";
			while(aux>=1){
				temp+=aux%10 + '0';
				aux/=10;
			}
			reverse(temp.begin(), temp.end());
			out+=temp;
		}		
		cout << out;
		reverse(out.begin(), out.end());
		cout << out;
		printf("\n");
	}


return 0;
}


