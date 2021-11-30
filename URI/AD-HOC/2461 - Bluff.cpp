// Author: Gustavo Policarpo
// Name: Bluff
// Level: 9
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2461

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
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int n, m, aux; cin >> n >> m;
	set <int> a, b;
	set <int> :: iterator l, r;
	rep(i, 0, n) scanf("%d", &aux), a.insert(aux);
	
	rep(i, 0, m){
		scanf("%d", &aux);
		if(a.count(aux)){
			b.insert(aux);
			continue;
		}
		int yep=0;
		l=b.begin(), r=b.end(), r--;
		while(l!=r){
			int sum=*l + *r;
			if( sum == aux ){
				yep=1;
				b.insert(aux);
				break;
			}
			if(sum > aux) r--;
			else l++;
		}
		
		if(!yep){
			if( *l + *l == aux ){
				b.insert(aux);
				continue;
			}
			printf("%d\n", aux);
			return 0;
		}
		
	}
	
	puts("sim");
	
	return 0;
	
}
