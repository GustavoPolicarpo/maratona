// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: High Five
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2539

#pragma comment(linker, "/stack:200000000")                                     
#pragma GCC optimize("Ofast")                                                   
#pragma GCC target("sse,sse2,sse3,ssse3,sse4,popcnt,abm,mmx,avx,tune=native")   
#define _CRT_SECURE_NO_WARNINGS          
#define gc getchar
#define pc(x) putchar(x);

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

#define rep(i,a,b) for( int i = (int) a; i < (int) b; i++ )
#define F first
#define S second
#define pb push_back
#define mp make_pair
#define debug(a) cout << #a << " = " << a << endl;
#define debug2(a,b) cout << #a << " = " << a << " --- " << #b << " = " << b << endl;
#define debugP(a) cout << a.F << " " << a.S << endl;
#define debugM(mat,n,m) rep( i, 0, n ){ rep( j, 0, m ) cout << mat[i][j] << " "; cout << endl; }

using namespace std;

typedef long long int ll;
typedef pair <int, int> ii;
typedef pair <int, ii> iii;

void scanint(register int &x){
    register int ccc = gc(); x = 0;
    for(;((ccc<48 || ccc>57));ccc = gc());
    for(;ccc>47 && ccc<58;ccc = gc()) {x = (x<<1) + (x<<3) + ccc - 48;}
}


void merge(int* arr, int size1, int size2, ll &inversions) {
    int temp[size1+size2+2];
    int ptr1=0, ptr2=0;

    while (ptr1+ptr2 < size1+size2) {
        if (ptr1 < size1 && arr[ptr1] <= arr[size1+ptr2] || ptr1 < size1 && ptr2 >= size2)
            temp[ptr1+ptr2] = arr[ptr1++];

        if (ptr2 < size2 && arr[size1+ptr2] < arr[ptr1] || ptr2 < size2 && ptr1 >= size1) {
            temp[ptr1+ptr2] = arr[size1+ptr2++];
            inversions += size1-ptr1;
        }
    }

    for (int i=0; i < size1+size2; i++)
        arr[i] = temp[i];
}

void mergeSort(int* arr, int size, ll &inversions) {
    if (size == 1) return;
    
    int size1 = size/2, size2 = size-size1;
    mergeSort(arr, size1, inversions);
    mergeSort(arr+size1, size2, inversions);
    merge(arr, size1, size2, inversions);
}

int main(){

	int N;
	while(scanf("%d", &N)!=EOF){
		int a[N]; rep(i, 0, N) scanf("%d", &a[i]), a[i]*=-1;
		ll inv = 0;
		mergeSort(a, N, inv);
		cout << inv << '\n';
		
	}
	
	
	return 0;
}
