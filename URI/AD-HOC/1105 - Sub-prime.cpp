// Author: Gustavo Policarpo
// Name: Sub-prime
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1105

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int main()
{
	int B, N;
	while(cin >> B >> N and B+N){
		int b[B];
		memset(b, 0, sizeof(b));
		rep(i, 0, B)
			cin >> b[i];
		int d, c, v;
		rep(i, 0, N){
			scanf("%d %d %d", &d, &c, &v);
			b[c-1]+=v;
			b[d-1]-=v;		
		}
		
		bool yep=true;
		rep(i, 0, B){
			if(b[i]<0){
				yep=false;
				break;
			}
		}
		if(yep) cout << 'S' << endl;
		else	cout << 'N' << endl;
	}
	
return 0;
}
