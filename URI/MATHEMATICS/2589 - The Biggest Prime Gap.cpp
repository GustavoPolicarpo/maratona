// Author: Gustavo Policarpo
// Name: The Biggest Prime Gap
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2589

#include<bits/stdc++.h>
 
#define rep(i,a,b) for( int i = a; i < b; i++ )
#define F first
#define S second
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define mp make_pair
#define pb push_back
#define debugM(M, l, c ) rep( i, 0, l ){ rep( j, 0, c ){ cout << M[i][j] << " "; } cout << endl; }
#define debugP(p) cout << #p << " = " << p.x << " --- " << #p << " = " << p.y << endl;
 
using namespace std;
 
typedef long long int ll;
typedef pair<int, int> ii;

#define INF 0x3f3f3f3f
const int mod=1e9+7;

/*const int limite=1e9+2;
bitset <limite+2> eh;
vector <int> primes;


void build(){
	
	primes.pb(2);
	
	for(int i=3; i<limite; i+=2){
		
		if(!eh[i]){
			primes.pb(i);
			for(int j=i+i; j<limite; j+=i)
				eh[j]=1;
		}
		
	}
	
	int ans=0;
	cout << "if(N<=2) cout << 0 << endl;\n";
	rep(i, 1, primes.size()){
		int aux=primes[i]-primes[i-1];
		if(aux>ans){
			ans=aux;
			cout << "else if(N<=" << primes[i] << ") cout << " << ans <<" endl;\n";
		}
	}
}
*/

void print(int n){
	printf("%d\n", n);
}

int main(){

	//freopen("out.txt", "w", stdout);
	
	//build()	;
	
	int N;
	
	while(scanf("%d", &N)!=EOF){
		
			if(N>=436273291) print(282); 
			else if(N>=387096383) print(250); 
			else if(N>=191913031) print(248); 
			else if(N>=189695893) print(234); 
			else if(N>=122164969) print(222); 
			else if(N>=47326913) print(220); 
				else if(N>=20831533) print(210);
				else if(N>=17051887) print(180);
					else if(N>=4652507) print(154);
						else if(N>=2010881) print(148);
						else if(N>=1357333) print(132);
							else if(N>=1349651) print(118);
							else if(N>=492227) print(114); 
							else if(N>=370373) print(112); 
								else if(N>=360749) print(96);
								else if(N>=156007) print(86);
								else if(N>=31469) print(72); 
								else if(N>=19661) print(52); 
								else if(N>=15727) print(44); 
								else if(N>=9587) print(36);
								else if(N>=1361) print(34);
								else if(N>=1151) print(22);
								else if(N>=907) print(20);
								else if(N>=541) print(18);
								else if(N>=127) print(14);
								else if(N>=97) print(8); 
								else if(N>=29) print(6); 
								else if(N>=11) print(4); 
								else if(N>=5) print(2);
									else if(N>=3) print(1);
									else print(0); 

	}
	
	return 0;
	
}
