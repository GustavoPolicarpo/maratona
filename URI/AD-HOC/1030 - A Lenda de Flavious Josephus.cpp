// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Lenda de Flavious Josephus
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1030

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
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

int josephus(int n, int k){
	
	if(n==1) return 1;
	int v=(josephus(n-1,k)+k-1)%n+1;
	
	return v;	
}

int main()
{
	
    int n, k, t;
    
    cin >> t;
    rep(z, 1, t+1)
    {
	    cin >> n >> k;
	    cout << "Case " << z << ": " << josephus(n, k) << endl;
	    
	}
    
    return 0;
    
}
