// Author: Gustavo Policarpo
// Name: Bora Bora
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1439

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

ii build(int c, char t){
	if(t=='C') return (mp(c, 0));
	else if(t=='D') return (mp(c, 1));
	else if(t=='H') return (mp(c, 2));
	else return (mp(c, 3));
}
int what(ii aux){
	if(aux.F == 12) return 1;
	if(aux.F == 7) return 2;
	if(aux.F == 1) return 3;
	if(aux.F == 11) return 4;
	return 0;
}
bool ver(ii a, ii b){
	return a.F == b.F || a.S == b.S;	
}

int p, m, n;
priority_queue <ii> pq[12];
stack <ii> descarte;
queue <ii> deck;

void doplay(int &player, int op, int &dir, int first_play){
	if(op==1){
		dir*=-1;
	}
	if(!first_play) player=(player+dir+p)%p;
	if(op==2){
		pq[player].push(deck.front()); deck.pop();
		pq[player].push(deck.front()); deck.pop();
		player=(player+dir+p)%p;
	}
	else if(op==3){
		pq[player].push(deck.front()); deck.pop();
		player=(player+dir+p)%p;
	}
	else if(op==4){
		player=(player+dir+p)%p;
	}
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(scanf("%d %d %d", &p, &m, &n) and p){
		
		while(!descarte.empty()) descarte.pop();
		while(!deck.empty()) deck.pop();
		int c; char t;
		
		ii aux;
		rep(i, 0, p){
			while(!pq[i].empty()) pq[i].pop();
			rep(j, 0, m){
				scanf("%d %c", &c, &t);
				pq[i].push(build(c, t));
			}
		}
		
		scanf("%d %c", &c, &t);
		descarte.push(build(c, t));
		
		rep(i, p*m+1, n){
			scanf("%d %c", &c, &t);
			deck.push(build(c, t));
		}
		
		int player=0, dir=1, op;
		op=what(descarte.top());
		doplay(player, op, dir, 1);
		
		while(1){
			int yep=0;
			vector <ii> hand;
			while(!pq[player].empty()){
				if(ver(pq[player].top(), descarte.top())){
					descarte.push(pq[player].top()); pq[player].pop();
					yep=1;
					break;
				}
				hand.pb(pq[player].top()); pq[player].pop();
			}
			rep(i, 0, hand.size()) pq[player].push(hand[i]);
			
			if(yep){
				if(pq[player].empty()){
					printf("%d\n", player+1);
					break;
				}
				op=what(descarte.top());
				doplay(player, op, dir, 0);
			}else{
				if(ver(deck.front(), descarte.top())){
					descarte.push(deck.front()); deck.pop();
					op=what(descarte.top());
					doplay(player, op, dir, 0);
				}else{
					pq[player].push(deck.front()); deck.pop();
					player=(player+dir+p)%p;
				}
			}
			
		}
		
	}

	return 0;
	
}
