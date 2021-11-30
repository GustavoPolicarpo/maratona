// Author: Gustavo Policarpo
// Name: LEXSIM - Sintatic and Lex...
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1083

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
		pc = 7;
	else if(c == '*' || c == '/')
		pc = 5;
	else if(c == '+' || c == '-')
		pc = 4;
	else if(c == '>' || c == '<' || c == '=' || c == '#')
		pc=3;
	else if(c == '.')
		pc = 2;
	else if(c == '|')
		pc = 1;
	else if(c == '(')
		pc = 7;
	
	if(t == '^')
		pt = 6;
	else if(t == '*' || t == '/')
		pt = 5;
	else if(t == '+' || t == '-')
		pt = 4;
	else if(t == '>' || t == '<' || t == '=' || t == '#')
		pt=3;
	else if(t == '.')
		pt = 2;
	else if(t == '|')
		pt=1;
	else if(t == '(')
		pt = 0;
	
	return (pc > pt);
  
}

set <char> has;

bool check(char s){
	return !isalpha(s) && !isdigit(s);
}

int main()
{
	
	has.insert('^');
	has.insert('*'); has.insert('/');
	has.insert('+'); has.insert('-');
	has.insert('>'); has.insert('<'); has.insert('='); has.insert('#');
	has.insert('.');
	has.insert('|');
	
	string s;
	
	while(cin >> s){
		
		stack <char> st; int yep=0;
		string ss;
		rep(i, 0, s.size()){
			if(s[i]!='(' && s[i]!=')'){
				ss.pb(s[i]);
			}
		}
		
		int qa=0, qb=0;
		rep(i, 0, ss.size()){
			if(check(ss[i]) && !has.count(ss[i])){
				yep=1;
				puts("Lexical Error!");
				break;
			}
			if(check(ss[i])) qa++;
			else qb++;
		}
		
		if(yep) continue;
		
		if(qb-1!=qa){
			puts("Syntax Error!");
			continue;
		}
		
		rep(i, 0, ss.size()-1){
			if(check(ss[i]) && check(ss[i+1])){
				yep=1;
				puts("Syntax Error!");
				break;
			}
			if(!check(ss[i]) && !check(ss[i+1])){
				yep=1;
				puts("Syntax Error!");
				break;
			}
		}
		
		
		if(yep) continue;
		
		rep(i, 0, s.size()){
			
			if(s[i]=='('){
				st.push(s[i]);
			}
			
			else if(s[i]==')'){
				if(s.empty()){
					yep=1;
					puts("Syntax Error!");
					break;
				}else{
					st.pop();
				}
			}
			
		}
		
		if(st.size()){
			yep=1;
			puts("Syntax Error!");
		}
		
		if(yep) continue; st.push('(');
		
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
