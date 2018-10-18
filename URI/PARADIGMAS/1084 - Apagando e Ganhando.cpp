// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Apagando e Ganhando
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1084

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F

typedef pair < int, int > ii;
typedef long long int ll;


int main ()
{
	int N, D;
	while(cin>>N>>D and N+D){
		char n[N]; cin >> n;
		stack <char> q;
		rep(i, 0, N){
			while(D&&!q.empty()&&n[i]>q.top()){
				D--;
				q.pop();
			}
			q.push(n[i]);
		}
		while(D--)
			q.pop();
		string out;
		while(!q.empty()){
			out+=q.top();
			q.pop();
		}
		reverse(out.begin(), out.end());
		cout << out << endl;
			
	}
	
   
return 0;
}
