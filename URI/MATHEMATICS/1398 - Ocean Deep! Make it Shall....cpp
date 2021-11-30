// Author: Gustavo Policarpo
// Name: Ocean Deep! Make it Shall...
// Level: 6
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1398

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

#define mod 131071
int main()
{
	char in; int num;
	while(scanf(" %c", &in) !=EOF){
		num=in-'0';
		while(scanf(" %c", &in)){
			if(in=='#') break;
			num*=2;	
			num+=in-'0';
			num%=mod;
		}
		//cout << num << endl;
		if(num==0) printf("YES\n");
		else printf("NO\n");
	}
	
	

return 0;
}


