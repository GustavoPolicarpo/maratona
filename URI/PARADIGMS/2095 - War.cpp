// Author: Gustavo Policarpo
// Name: War
// Level: 4
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2095

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
#define error 1e-3

typedef long long int ll;
typedef unsigned long long int ull;
typedef unsigned long long int ull;
typedef pair < double, double > ii;
typedef pair < ii, ii > iii;

bool cmp(int a, int b){
	return a>b;
}

int main()
{
	
	int S, aux; cin >> S;
	vector <int> s, n;
	
	rep(i, 0, S){
		scanf("%d", &aux);
		s.pb(aux);
	}
	
	rep(i, 0, S){
		scanf("%d", &aux);
		n.pb(aux);
	}
	
	sort(s.begin(), s.end(), cmp);
	sort(n.begin(), n.end(), cmp);
	
	int ans=0, p=0;
	
	rep(i, 0, s.size()){
		//cout << s[i] << " " << n[p] << '\n';
		if(s[i]<n[p]){
			ans++;
			p++;
		}
	}
	
	printf("%d\n", ans);

	return 0;
	
}
