// Author: Gustavo Policarpo
// Name: I Can Guess the Data Stru...
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1340

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
#define error 1e-8

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


int main()
{
	int N;
	while(cin >> N){
		queue <int> q; bool eq=true;
		stack <int> s; bool es=true;
		priority_queue <int> pq; bool epq=true;
		int op, aux;
		rep(i, 0, N){
			scanf("%d %d", &op, &aux);
			if(op==1)
				q.push(aux), s.push(aux), pq.push(aux);
			else{
				if(!q.empty() && q.front()!=aux) eq=false;
				else if(eq==true) q.pop();
				if(!s.empty() && s.top()!=aux) es=false;
				else if(es==true) s.pop();
				if(!pq.empty() && pq.top()!=aux) epq=false;
				else if(epq==true) pq.pop();
			}		
		}
		if(eq&&es || eq&&epq ||	es&&epq 
			|| eq&&es&&epq)
			printf("not sure\n");
		else if(eq)
			printf("queue\n");
		else if(es)
			printf("stack\n");
		else if(epq)
			printf("priority queue\n");
		else
			printf("impossible\n");
	}
	
	
return 0;
}
