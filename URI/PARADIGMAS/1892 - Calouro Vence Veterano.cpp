// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Calouro Vence Veterano?
// Nível: 3
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1892

#include <bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair
#define F first
#define S second


typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < int, ii > iii;


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

int vet[100010], n, cnt; string s;
map<string, int> mapa;
vector <string> ord, in;

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	
	while(cin >> n){
		
		cnt=0, mapa.clear(), ord.clear(), in.clear();
		
		rep(i, 0, n){
			cin >> s; 
			in.pb(s), ord.pb(s);
		}
		
		sort(ord.begin(), ord.end());
		
		rep(i, 0, n){
			if(!mapa.count(ord[i])){
				mapa[ord[i]]=cnt++;
			}
		}
		
		rep(i, 0, n){
			vet[i]=mapa[in[i]];
		}
		
		ll ans=0; mergeSort(vet, n, ans);
		
		cout << ans << '\n';
		
	}

	return 0;
	
}
