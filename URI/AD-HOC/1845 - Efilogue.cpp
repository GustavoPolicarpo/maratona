// Author: Gustavo Policarpo
// Name: Efilogue
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1845

#include <bits/stdc++.h>
using namespace std;

#define rep(i,a,b) for(int i=a; i<b; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second
#define INF 0x3F3F3F3F3F
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	char aux, last='[';

    while(scanf("%c", &aux)!=EOF){
    	
		if(aux=='b'||aux=='f'||aux=='j'||aux=='p'||aux=='s'||aux=='v'||aux=='x'||aux=='z'){
			if((last!='f' && last!='F')) printf("%c", 'f'), last='f';
		}
			
		else if(aux=='B'||aux=='F'||aux=='J'||aux=='P'||aux=='S'||aux=='V'||aux=='X'||aux=='Z'){
			if((last!='f' && last!='F')) printf("%c", 'F'), last='F';	
		}
    		
    	else{
    		cout << aux;
			last=aux;
		}
	
	}
            
return 0;
}
