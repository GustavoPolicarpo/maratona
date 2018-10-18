// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Soma de Propina
// Nível: 2
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1898

#define gc getchar_unlocked
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
#define mod 1000000007 

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;

/*void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}*/



int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	string a, b, cpf;
	getline(cin, a); bool fim=false;
	int cnt=0, frac=0; ull d1=0, d2=0, f1=0, f2=0;
	rep(i, 0, a.size()){
		if(isdigit(a[i])){
			if(cnt<11){
				cpf+=a[i];
				cnt++;
			}
			else if(!fim){
				d1*=10;
				d1+=(a[i]-'0');
			}
			else{
				frac++;
				f1+=(a[i]-'0');	
				if(frac==1) f1*=10;
				if(frac==2) break;
			}
		}
		else if(a[i]=='.'){
			if(fim) break;
			fim=true;	
		}
	}
	getline(cin, b); frac=0; fim=false;
	rep(i, 0, b.size()){
		if(isdigit(b[i])){
			if(!fim){
				d2*=10;
				d2+=(b[i]-'0');
			}
			else{
				frac++;
				f2+=(b[i]-'0');
				if(frac==1) f2*=10;
				if(frac==2) break;
			}
		}
		else if(b[i]=='.'){
			if(fim) break;
			fim=true;
		}
	}
	//cout << f1 << " " << f2 << endl;
	ull od=d1+d2, of=f1+f2;
	if(of>=100){
		od++;
		of=of-100;
	}
	cout << "cpf " << cpf << '\n';
	cout << od << ".";
	if(of<10) printf("0");
	cout << of << '\n';
						
return 0;
}
