// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Balé
// Nível: 5
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2400

#include <bits/stdc++.h>
 
using namespace std;
#define MAX 100001
typedef long long int ll;
 
ll bit[MAX];
ll A[MAX];
int rep;
 
void update(int i, int x){
	for(; i <= rep; i += i&-i)
		bit[i] += x;
}
 
ll query(int i){
	ll sum = 0;
	for(; i > 0; i -= i&-i){
		sum += bit[i];	
	}
	return sum;	
}
 
void range_update(int i, int j, ll valor){
	update(i, valor);
	//update(j+1, -valor);
}
 
int main(){
 
	cin >> rep;
	for(int i = 1; i <= rep; i++){
		int aux;
		cin >> aux;
		A[aux] = i;
	}
	
	int total = 0;
	for(int i = 1; i <= rep; i++){
		total += (query(rep) - query(A[i]));
		range_update(A[i], A[i], 1);
		//for(int j = 1; j <= rep; j++)
		//	cout << query(j) << ' ';
		//cout << endl;	
	}
	
 
	cout << total << endl;
 
	return 0;
}
