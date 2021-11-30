// Author: Gustavo Policarpo
// Name: Variations
// Level: 1
// Category: STRINGS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1632

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
//

int main()
{
//freopen("out.txt", "w", stdout);
	int T; cin >> T;
	set <char> let;
	let.insert('A'), let.insert('E'), let.insert('I'),
	let.insert('O'), let.insert('S'), let.insert('a'),
	let.insert('e'), let.insert('i'), let.insert('o'),
	let.insert('s');
	while(T--){
		char in[20];
		scanf("%s", &in); int tam=strlen(in);
		ll out=1;
		rep(i, 0, tam){
			if(let.count(in[i])) out*=3;
			else out*=2;
		}
		printf("%lld\n", out);
	}

return 0;
}


