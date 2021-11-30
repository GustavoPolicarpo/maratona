// Author: Gustavo Policarpo
// Name: Noel Bet
// Level: 5
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2027

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
	int a, b, c; stack <int> q;
	while(scanf("%d %d", &a, &b) !=EOF){
		c=__gcd(a, b); q.push(c);
		if(c>5) printf("Noel\n");
		else printf("Gnomos\n");
	}
	while(!q.empty()){
		printf("%d ", q.top());
		q.pop();
	}
	cout << endl;
			
return 0;
}
