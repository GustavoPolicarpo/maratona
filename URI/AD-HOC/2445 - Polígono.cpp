// Author: Gustavo Policarpo
// Name: Polígono
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2445

#include <bits/stdc++.h>
 
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
//freopen("out.txt", "w", stdout);
 


int main()
{
	int N; cin >> N;
	ll sum=0; int n[N];
	
	rep(i, 0, N){
		scanf("%d", &n[i]);
		sum+=n[i];
	}	sort(n, n+N);
	
	int cnt=N, j=N-1;
	
	while(n[j] >= (sum+1)/2 && j){
		cnt--, sum-=n[j], j--;
	}
	
	if(cnt <= 2) cnt=0;
	
	cout << cnt << '\n';
	
	
	return 0;
	
}
