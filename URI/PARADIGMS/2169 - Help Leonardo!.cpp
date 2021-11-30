// Author: Gustavo Policarpo
// Name: Help Leonardo!
// Level: 9
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2169

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000
#define EPS 1e-6

typedef long long int ll;
typedef pair < double, double > ii;
typedef pair < int, ii > iii;

map <string, double> gun, monster;
struct arma{
	int pot, mun;
};
vector <arma> n;
int A, M, B;
int TR, TP;

int pd[10][10005];
int solve(int i, int c)
{
	if(i==A) return 0;
	if(pd[i][c]!=-1) return pd[i][c];
	int ret=solve(i+1, c);
	if(c-n[i].mun>=0){
		ret=max(ret, solve(i+1, c-n[i].mun)+n[i].mun*n[i].pot);
	}
	return pd[i][c]=ret;	
}

bool comp(arma a, arma b)
{
	if(a.pot>b.pot) return true;
	return false;
}

int main()
{
	gun["HANDGUN"]=20;
	gun["RED9"]=35;
	gun["BLACKTAIL"]=35;
	gun["MATILDA"]=20;
	gun["HANDCANNON"]=600;
	gun["HANDCANON"]=600;
	gun["STRIKER"]=120;
	gun["TMP"]=12;
	gun["RIFLE"]=120;
	monster["GANADOS"]=500;	
	monster["COBRAS"]=400;
	monster["ZEALOT"]=750;
	monster["COLMILLOS"]=600;
	monster["GARRADOR"]=1250;
	monster["LASPLAGAS"]=1000;
	monster["GATLINGMAN"]=1500;
	monster["REGENERATOR"]=2500;
	monster["ELGIGANTE"]=5000;
	monster["DR.SALVADOR"]=3500;
	while(scanf("%d", &A)!=EOF){
		n.clear(); arma aux; string in; int qt;
		rep(i, 0, A){
			cin >> in >> qt;
			aux.mun=qt; aux.pot=gun[in];
			n.pb(aux);	
		}
		TR=0;
		scanf("%d", &M);
		while(M--){
			cin >> in >> qt;
			TR+=monster[in]*qt;
		}
		scanf("%d", &B);
	//	sort(n.begin(), n.end(), comp);
		memset(pd, -1, sizeof pd);
		TP=solve(0, B);
		if(TP>=TR) printf("Missao completada com sucesso\n\n");
		else printf("You Are Dead\n\n");
	}
			
return (0);
}
