// Author: Gustavo Policarpo
// Name: Album of the Cup
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2779

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second

typedef long long int ll;
typedef pair < int, int > ii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main(){
	
	int N; cin >> N;
	set <int> st; int aux;
	int Q; cin >> Q;
	while(Q--){
		cin >> aux;
		st.insert(aux);
	}
	
	cout << N - st.size() << '\n';
	
	return 0;
}
