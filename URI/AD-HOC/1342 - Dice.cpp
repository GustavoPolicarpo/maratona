// Author: Gustavo Policarpo
// Name: Dice
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1342

#define gc getchar_unlocked
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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

//freopen("in.txt", "r", stdin);
//


int main()
{
//freopen("out.txt", "w", stdout);
	int P, S, Q;
	while(scanf("%d %d", &P, &S) and P+S){
		int t1, t2, t3;
		scanf("%d %d %d", &t1, &t2, &t3);
		int trapped[P], place[P];
		rep(i, 0, P){
			trapped[i]=0, place[i]=0;
		}
		scanf("%d", &Q); int d1, d2, mov, p=0;
		while(Q--){
			scanf("%d %d", &d1, &d2);
			//cout << p << "     " << place[p] << endl;
			mov=d1+d2;
			while(trapped[p]){
				trapped[p++]--;
				if(p==P) p=0;
			}
			place[p]+=mov;
			if(place[p]==t1 || place[p]==t2 || place[p]==t3) trapped[p]=1; 
			//cout << p << "     " << place[p] << endl;
			if(place[p]>S) printf("%d\n", p+1);
			p++;
			if(p==P) p=0;
		}
	}
	
return 0;
}
