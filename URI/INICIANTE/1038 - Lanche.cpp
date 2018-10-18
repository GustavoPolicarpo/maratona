// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Lanche
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1038

#include <iostream>
#include <iomanip>

using namespace std;

double custo[]={0.0, 4.0, 4.5, 5.0, 2.0, 1.5};
int main(){
    
    int C, Q; cin >> C >> Q;
    printf("Total: R$ %.2lf\n", Q*custo[C]);
    
}
