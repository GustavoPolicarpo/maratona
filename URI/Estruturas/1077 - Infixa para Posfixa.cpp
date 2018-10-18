// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Infixa para Posfixa
// Nível: 3
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1077

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define f(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define all(c) c.begin(), c.end() 

typedef pair<char, int> ii;
typedef pair<pair<double, int>, ii> iii;
typedef unsigned long long int ll;

int prior(char c, char t){
  int pc,pt;
 
  if(c == '^')
    pc = 4;
  else if(c == '*' || c == '/')
    pc = 2;
  else if(c == '+' || c == '-')
    pc = 1;
  else if(c == '(')
    pc = 4;
 
  if(t == '^')
    pt = 3;
  else if(t == '*' || t == '/')
    pt = 2;
  else if(t == '+' || t == '-')
    pt = 1;
  else if(t == '(')
    pt = 0;
 
  return (pc > pt);
  
}


int main()
{
	int T; cin >> T;
	
	while(T--){
		
		string s; cin >> s; stack <char> st; st.push('(');
		
		rep(i, 0, s.size()+1){
			
			if(isalpha(s[i]) || isdigit(s[i])){
				cout << s[i];
				continue;
			}
			
			if(s[i]=='(') st.push('(');
			
			else if(s[i]==')' || s[i]=='\0'){
				while(st.top()!='('){
					cout << st.top();
					st.pop();
				}	st.pop();
			}
			
			else{
				while(1){
					if(prior(s[i], st.top())){
						st.push(s[i]);
						break;
					}else{
						cout << st.top();
						st.pop();
					}
				}
			}
			
		}
		
		cout << '\n';
		
	}
	
	
	return 0;
	
}
