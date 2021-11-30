// Author: Gustavo Policarpo
// Name: How Many Zeros and How Ma...
// Level: 9
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1501

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
typedef pair<ii, int> iii;

const ll mod = 1e9+7;

int NumOfDigitsInFactorial(int N, int B){
	double logFatN = 0;
	for (int i = 1; i <= N; i++)
		logFatN += log((double)i);
	int nd = floor(logFatN / log((double)B)) + 1;
	return nd;
}


int fator[1010], expoente[1010];

int fatora(int N){
	int cnt = 0, prime = 2;
	while(N>1){
		if(N%prime==0){
			fator[cnt]=prime;
			while(N%prime==0) N/=prime, expoente[cnt]++;
			cnt++;
		}
		prime++;
	}
	return cnt;
}

int NumOfTrailingZeros(int N, int B){
	int nfact = fatora(B);
	int zeros = 0x3f3f3f3f;

    // para cada fator de B, aux representa qtas vezes
    // fator[i]^expoente[i] aparece na representacao de N!
	for (int i=0; i < nfact; i++){
		int soma = 0;
		int NN = N;
		while (NN){
			soma += NN/fator[i];
			NN /= fator[i];
		}
		int aux = soma / expoente[i];
		zeros = min(zeros, aux); expoente[i] = 0;
	}
	return zeros;
}

int main(){
	
	int N, B;
	while(cin >> N >> B){
		cout << NumOfTrailingZeros(N, B) << " " << NumOfDigitsInFactorial(N, B) << '\n';
	}
	
	return 0;
}
