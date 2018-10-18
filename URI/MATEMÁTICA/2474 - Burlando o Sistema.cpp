// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Burlando o Sistema
// Nível: 5
// Categoria: MATEMÁTICA
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2474

#include <stdio.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

int primo[100010], eh[100010];
int p=0, i, j;

int isPrime(long long int n){
	
	if(n==2) return 1;
	if(n%2==0) return 0;
	
	i=0;
	while(primo[i]<=sqrt(n)){
		if(n%primo[i]==0) return 0;
		i++;
	}
		
	return 1;
	
}

const long long int MAXV = 100010;
void primos(){
	
	primo[p++]=2;
	for(i=3; i<MAXV; i+=2) eh[i]=1;
	
	for(i=3; i<MAXV; i+=2){
		if(eh[i]){
			primo[p++]=i;
			for(j=i+i; j<MAXV; j+=i)
				eh[j]=0;
		}
	}
}

int main()
{
	
	primos();
	long long int n;
	while(scanf("%lld", &n)!=EOF){
		
		
		if(n%2==0 && n!=2){
			printf("%lld\n", n-2);
			continue;
		}
		
		if(isPrime(n)){
			printf("%lld\n", n-1);
			continue;
		}
		
		if(isPrime(n-2)){
			printf("%lld\n", n-2);
			continue;
		}
		
		printf("%lld\n", n-3);
		
	}
	
	return 0;
	
}
