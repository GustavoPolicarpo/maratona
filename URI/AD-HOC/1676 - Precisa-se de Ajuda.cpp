// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Precisa-se de Ajuda
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1676

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

#define MAX 40000  //MAXIMO VALOR

vector <int> primos;


int allprimos()
{
	
	int bp[MAX];
	for (int i=2; i<MAX; i++) bp[i]=1;
	int max=sqrt(MAX);
	for(int i=2; i<MAX; i++)
	{
		if(bp[i]==1)
		{
			int cont=0;
			for(int j=i+1; j<MAX; j++){
				if(bp[j]==1){
					cont++;
					if(cont==i)
						bp[j]=0, cont=0;
				}
			}		
		}
	}
	for(int i=2; i<MAX; i++)
		if(bp[i]==1)
			primos.push_back(i);
			
	/*for(int i=0; i<primos.size(); i++)
		cout << primos[i] << endl;*/
	
}
int main()
{
	//freopen("out.txt", "w", stdout);
	allprimos();
	int N;
	while(scanf("%d", &N) and N!=0){
		printf("%d\n", primos[N-1]);
	}

return (0);	
}
