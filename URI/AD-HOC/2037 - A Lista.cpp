// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: A Lista
// Nível: 1
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2037

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

queue <int> q[10];
bool ver(int n)
{
	bool did=true;
	rep(i, 2, n+1){
		if(!q[i].empty()){
			did=false;
			break;
		}
	}
	return did;
}
	

int main()
{
	int N; 
	while(cin >> N && N+1){
		
		int u;
		rep(i, 2, N+1){
			string aux; cin >> aux;
			rep(j, 0, aux.size()){
				q[i].push(aux[j]-'0');
			}
		}
		int i=1;
		while(1){	
			if(ver(N)) break;
			i++;
			if(i==N+1) i=2;
			//cout << i << " " << q[i].front() << endl;
			//system("pause");
			if(q[i].empty())continue;
			if(q[i].front()==1){ cout << i; q[i].pop(); continue; }
			//cout << i << " " <<  q[i].front() << " " << q[q[i].front()].front() << " " << q[i].size() <<  endl;
			if(i==q[q[i].front()].front())  q[q[i].front()].pop(), q[i].pop();
					
		}
		cout << endl;
	}		
return 0;
}
