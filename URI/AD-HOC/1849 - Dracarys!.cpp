// Author: Gustavo Policarpo
// Name: Dracarys!
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1849

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
	int l1, c1, l2, c2, out, a1, a2;
	scanf("%d %d %d %d", &l1, &c1, &l2, &c2);
	a1=min(max(l1, c1), max(l2, c2));
	a2=min(a1, min(l1, c1)+min(l2, c2));
	out=a2*a2;
	printf("%d\n", out);

return 0;
}
