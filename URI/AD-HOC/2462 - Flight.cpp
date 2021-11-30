// Author: Gustavo Policarpo
// Name: Flight
// Level: 8
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2462

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

#define INF 0x3F3F3F3F
#define MAXV 100001
#define mod 1000000007

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;






int readTime(){
	int h, m;
	scanf("%d:%d", &h, &m);
	return h*60+m;
}

int main()
{
	int n[4];
	rep(i, 0, 4) n[i]=readTime();
	
	int sub=-11*60;
	vector <ii> out;
	
	for(int i=-11*60; i<=12*60; i+=60){
		int aux[4];
		rep(j, 0, 4) aux[j]=n[j];
		
		aux[1]-=i, aux[2]-=i;
		if(aux[1]<=0) aux[1]=24*60+aux[1];
		if(aux[1]>24*60) aux[1]=aux[1]-24*60;
		if(aux[2]<=0) aux[2]=24*60+aux[2];
		if(aux[2]>24*60) aux[2]=aux[2]-24*60;
		
		int da, db;
		if(aux[1]<=aux[0]) da=24*60-aux[0]+aux[1];
		else da=aux[1]-aux[0];
		
		if(aux[3]<=aux[2]) db=24*60-aux[2]+aux[3];
		else db=aux[3]-aux[2];
		
		if(da==db){
			out.pb(mp(da, i/60));
			//break;
		}
		
	}
	
	sort(out.begin(), out.end());
	
		cout << out[0].F << " " << out[0].S << "\n";
	
	return 0;
	
}
