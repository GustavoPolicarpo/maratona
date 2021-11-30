// Author: Gustavo Policarpo
// Name: Eearliest Deadline First
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2823

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back

using namespace std;

typedef long long int ll;
typedef pair<int, int> ii;
typedef pair<ii, int> iii;

int main(){
	
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);

	int N; cin >> N;
	int mark[N]; memset(mark, 0, sizeof mark);
	
	vector <ii> in;
	rep(i, 0, N){
		int C, P;
		cin >> C >> P;
		in.pb(ii(C, P));
	}
	
	priority_queue <iii> pq;
	rep(i, 0, N) pq.push(iii(ii(-in[i].S, in[i].F), i));
	
	int ta = 0;
	while(42){
		int finish = true;
		rep(i, 0, N){
			if(mark[i]<10){
				finish = false;
				break;
			}
		}
		if(finish){
			puts("OK");
			return 0;
		}
		iii aux = pq.top(); pq.pop();
		if(ta>=-aux.F.F){
			puts("FAIL");
			return 0;
		}
		if(aux.F.S==1){
			ta++;
			mark[aux.S]++;
			pq.push(iii(ii(-(-aux.F.F+in[aux.S].S), in[aux.S].F), aux.S));
		}else{
			ta++;
			aux.F.S--;
			pq.push(aux);
		}
		
	}
	
	
	return 0;
} 
