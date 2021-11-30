// Author: Gustavo Policarpo
// Name: Marianne and The Twin Cou...
// Level: 8
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1926

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

#define limite 10000

#define MAX 10000005  //MAXIMO VALOR

int bp[MAX], sum[MAX];
vector <int> primos;
int allprimos()
{
	for (ll i=2; i<MAX; i++) bp[i]=1;
	int max=sqrt(MAX);
	for(ll i=2; i<max; i++)
	{
		if(bp[i]==1)
		{
			for(ll j=i*i; j<MAX; j=j+i)
				bp[j]=0;
		}
	}
	for(ll i=2; i<MAX; i++)
		if(bp[i]==1)
			primos.push_back(i);
	
	
	for(ll i=1; i<primos.size()-1; i++){
		if(primos[i]-primos[i-1]==2 || primos[i+1]-primos[i]==2){
			sum[primos[i]]++;
			//cout << primos[i] << endl;
		}
			
	}
		
}

int main()
{
	allprimos();
	for (ll i=2; i<MAX; i++) sum[i]=sum[i-1]+sum[i];

	int T; cin >> T;
	while(T--){
		int x, y;
		scanf("%d %d", &x, &y);
		if(x>y) swap(x, y);
		printf("%d\n", sum[y]-sum[x-1]);
	}
	
	
return 0;
}
