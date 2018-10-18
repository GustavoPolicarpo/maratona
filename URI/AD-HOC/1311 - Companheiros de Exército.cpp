// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Companheiros de Exército
// Nível: 4
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1311

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
typedef pair < int, int > ii;
typedef pair < ii, int > iii;


int main()
{
	
	int S, B, L, R;
	
	while(scanf("%d %d", &S, &B) and S+B){
		
		set <int> st; set <int> :: iterator it;
		rep(i, 1, S+1) st.insert(i);
		
		while(B--){
			
			scanf("%d %d", &L, &R);
			
			it=st.find(L);
			if(it==st.begin()) printf("* ");
			else{
				it--;
				printf("%d ", *it);
			}
			
			it=st.find(R); it++;
			if(it==st.end()) printf("*\n");
			else{
				printf("%d\n", *it);
			}
			
			rep(i, L, R+1) st.erase(i);
			
		}
		
		printf("-\n");
		
	}
	
	return 0;
	
}
