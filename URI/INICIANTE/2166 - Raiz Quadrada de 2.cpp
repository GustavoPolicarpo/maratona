// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Raiz Quadrada de 2
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2166

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
typedef pair < int, int > ii;
typedef pair < double, int > iii;

//freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

double num[101], dem[101];
int main()
{
	double p=1.0, q=1.0;
	num[0]=p, dem[0]=q;
	rep(i, 1, 101){
		num[i]=num[i-1]+2*dem[i-1];
		dem[i]=dem[i-1]+num[i-1];
		//cout << num[i] << " / " << dem[i] << endl; 
	}
	int N; scanf("%d", &N);
	double out=num[N]/dem[N];
	printf("%.10lf\n",out);

return 0;
}


