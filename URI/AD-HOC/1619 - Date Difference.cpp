// Author: Gustavo Policarpo
// Name: Date Difference
// Level: 4
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1619

#define gc getchar
#define pc(x) putchar(x);
#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
#define pb push_back
#define mp make_pair
#define F first
#define S second

#define INF 0x3F3F3F3F3F3F3F
#define MAXV 100001
#define mod 1000000007
#define error 1e-9

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < ll, ll > ii;
typedef pair < int, ii > iii;

void scanint(int &x)
{
    register int ccc = gc();
    x = 0;
    int neg = 0;
    for(;((ccc<48 || ccc>57) && ccc != '-');ccc = gc());
    if(ccc=='-') {neg=1;ccc=gc();}
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
    if(neg) x=-x;
}

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);



int day[]={0, 31, 28, 31, 30, 31, 30, 31, 31, 30, 31, 30, 31};

struct data{
	int ano, mes, dia;
	data() {}
	data(int a, int b, int c) : ano(a), mes(b), dia(c) {}
};	

bool comp(data a, data b){
	if(a.ano>b.ano) return true;
	else if(a.ano<b.ano) return false;
	if(a.mes>b.mes) return true;
	else if(a.mes<b.mes) return false;
	if(a.dia>b.dia) return true;
	else if(a.dia<b.dia) return false;
}
int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	int N; cin >> N;
	while(N--){
		data a, b;
		scanf("%d-%d-%d %d-%d-%d", &a.ano, &a.mes, &a.dia, &b.ano, &b.mes, &b.dia);
		if(comp(a, b)) swap(a, b);
		//cout << a.ano << " " << a.mes << " " << a.dia << endl;
		int cnt=0;
		while(1){
			if(a.ano==b.ano && a.mes==b.mes && a.dia==b.dia){
				printf("%d\n", cnt);
				break;
			}
			a.dia++, cnt++;
			if(a.ano%4==0 && (a.ano%400==0 || a.ano%100)){
				if(a.mes==2){
					if(a.dia==day[a.mes]+2){
						a.dia=1, a.mes++;
					}
				}
				else if(a.dia==day[a.mes]+1){
					a.dia=1, a.mes++;
					if(a.mes==13){
						a.ano++, a.mes=1;
					}
				}
			}
			else{
				if(a.dia==day[a.mes]+1){
					a.dia=1, a.mes++;
					if(a.mes==13){
						a.ano++, a.mes=1;
					}
				}
			}
		}	
	}
		
return 0;

}
