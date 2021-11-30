// Author: Gustavo Policarpo
// Name: Bino's Challenge
// Level: 1
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2060

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair

#define INF 0x3F3F3F3F
#define MAXV 100001

typedef long long int ll;
typedef pair < int, int > ii;


int main()
{
	int N;
	cin >> N;
	int m2=0, m3=0, m4=0, m5=0;
	rep(i, 0, N){
		int L; cin >> L;
		if(L%2==0) m2++;
		if(L%3==0) m3++;
		if(L%4==0) m4++;
		if(L%5==0) m5++;
	}
	cout << m2 << " Multiplo(s) de 2" << endl;
	cout << m3 << " Multiplo(s) de 3" << endl;
	cout << m4 << " Multiplo(s) de 4" << endl;
	cout << m5 << " Multiplo(s) de 5" << endl;	

return (0);
}
