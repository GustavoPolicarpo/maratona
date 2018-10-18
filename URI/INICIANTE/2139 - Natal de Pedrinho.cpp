// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Natal de Pedrinho
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2139

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
 
typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, string > ii;
typedef pair < double, int > iii;
 
//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);


int main()
{
	int n[12];
	n[0]=0, n[1]=31, n[2]=60, n[3]=91,
	n[4]=121, n[5]=152, n[6]=182, n[7]=213,
	n[8]=244, n[9]=274, n[10]=305, n[11]=335;
	
	int m, d, dd, natal;
	natal=n[11]+25;
	while(scanf("%d %d", &m, &d) !=EOF){
		dd=n[m-1]+d;
		if(natal-dd<0) printf("Ja passou!");
		else if(natal-dd==0) printf("E natal!");
		else if(natal-dd==1) printf("E vespera de natal!");
		else printf("Faltam %d dias para o natal!", natal-dd);
		printf("\n");
	}
	
	
			
return 0;
}
