// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Troca de Mensagens
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2852

#include <bits/stdc++.h>
 
//LIFE IS NOT A PROBLEM TO BE SOLVED
 
#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;


int main(){
    
    string k; cin >> k; int pointer = 0;
    int t; cin >> t;
    string s; getline(cin, s);
    while(t--){
    	getline(cin, s); string t; pointer = 0;
    	rep(i, 0, s.size()){
    		if(s[i]>='a' && s[i]<='z'){
    			t.pb(s[i]);
			}else{
				if(t.size()){
					if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o' || t[0]=='u'){
						//pointer = (pointer+t.size())%k.size();
						cout << t;
					}else{
						rep(j, 0, t.size()){
							char c = (t[j]-'a'+(k[pointer]-'a')+26)%26 + 'a';
							cout << c;
							pointer = (pointer+1)%k.size();
						}
					}
				}
				t.clear();
				cout << s[i];
			}
		}
		if(t.size()){
			if(t[0]=='a' || t[0]=='e' || t[0]=='i' || t[0]=='o' || t[0]=='u'){
				//pointer = (pointer+t.size())%k.size();
				cout << t;
			}else{
				rep(j, 0, t.size()){
					char c = (t[j]-'a'+(k[pointer])-'a'+26)%26 + 'a';
					cout << c;
					pointer = (pointer+1)%k.size();
				}
			}
		}
		t.clear();
		puts("");
	}
    
	
    return 0;
}  
