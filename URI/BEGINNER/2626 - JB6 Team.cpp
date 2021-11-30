// Author: Gustavo Policarpo
// Name: JB6 Team
// Level: 4
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2626

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define repi(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define pi 3.1415926535897932384626433832795028841971
#define F first
#define S second
#define MAX 50010
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;

typedef long long ll;
typedef pair < int, int>  ii;
typedef pair < int, pair<int,int> >  iii;

// freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main(){
	
	string a, b, c;
	
	while(cin >> a >> b >> c){ 
	
		if(b==c){
			if(a=="papel" && b=="pedra" || a=="tesoura" && b=="papel" || a=="pedra" && b=="tesoura")
				puts("Os atributos dos monstros vao ser inteligencia, sabedoria...");
			else puts("Putz vei, o Leo ta demorando muito pra jogar...");
		}
		
		else if(a==c){
			if(b=="papel" && c=="pedra" || b=="tesoura" && c=="papel" || b=="pedra" && c=="tesoura")
				puts("Iron Maiden's gonna get you, no matter how far!");
			else puts("Putz vei, o Leo ta demorando muito pra jogar...");
		}
		
		else if(a==b){
			if(c=="papel" && b=="pedra" || c=="tesoura" && b=="papel" || c=="pedra" && b=="tesoura")
				puts("Urano perdeu algo muito precioso...");
			else puts("Putz vei, o Leo ta demorando muito pra jogar...");
		}
		
		else puts("Putz vei, o Leo ta demorando muito pra jogar...");
	}

	return 0;
}
