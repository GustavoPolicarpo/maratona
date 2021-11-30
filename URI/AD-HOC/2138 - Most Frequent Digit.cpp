// Author: Gustavo Policarpo
// Name: Most Frequent Digit
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2138

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
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int main()
{
	int vet[10]; char in[10009];
	while(scanf("%s", &in) !=EOF){
		memset(vet, 0, sizeof vet);
		rep(i, 0, strlen(in))
			vet[in[i]-'0']++;
		int maior=0, ind=-1;;
		rep(i, 0, 10){
			//cout << vet[i] << endl;
			if(vet[i]>=maior)
				maior=vet[i], ind=i;
		}
			
		printf("%d\n", ind);
				
	}
	
			
return 0;
}
