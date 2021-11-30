// Author: Gustavo Policarpo
// Name: Square Root of 10
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2161

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

double num[101], dem[101];
int main()
{
	double p=1.0, q=1.0;
	num[0]=p, dem[0]=q;
	num[1]=1, dem[1]=6;
	rep(i, 2, 101){
		dem[i]=dem[i-1]*6+dem[i-2];
		num[i]=dem[i-1];
		//cout << num[i] << " / " << dem[i] << endl; 
	}
	int N; scanf("%d", &N);
	double out=3.0+num[N]/dem[N];
	if(N==0) out-=1.0;
	printf("%.10lf\n",out);

return 0;
}


