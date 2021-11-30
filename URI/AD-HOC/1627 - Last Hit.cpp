// Author: Gustavo Policarpo
// Name: Last Hit
// Level: 3
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1627

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
	int T; cin >> T;
	while(T--){
		int at, ad, bt, bd, h;
		scanf("%d %d %d %d %d", &at, &ad, &bt, &bd, &h);
		int tempo=0;
		while(h>=0){
			//cout << h << endl;
			if(tempo==0 || tempo%ad==0){
				h-=at;
			}
			if(h<=0){
				printf("Andre\n");
				break;
			}
			if(tempo==0 || tempo%bd==0){
				h-=bt;
			}
			if(h<=0){
				printf("Beto\n");
				break;
			}
			tempo++;
		}
	}

return 0;
}
