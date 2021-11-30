// Author: Gustavo Policarpo
// Name: Enisvaldo's Hunger
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2004

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
	int Q, N, T, P, out; cin >> Q;
	while(Q--){
		scanf("%d", &N);
		map <int, int> a;
		map <int, int> ::iterator it;
		rep(i, 0, N){
			scanf("%d %d", &T, &P);
			if(a.count(T)){
				if((P>a[T] && (P<=100||a[T]<10||a[T]>100)) ||
					(P<=100 && P>=10 && a[T]>100))
					a[T]=P;	
							
			}
			else a[T]=P;
		} out=0;
		for(it=a.begin(); it!=a.end(); it++)
			out+=a[it->first];
		printf("%d\n", out);
		
	}

return 0;
}
