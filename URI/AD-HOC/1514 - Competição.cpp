// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Competição
// Nível: 3
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1514

# include <bits/stdc++.h>

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define repi(i,a,b) for(int i = int(a); i > int(b) ; i--)
#define pb push_back
#define mp make_pair
#define INF 0x3F3F3F3F
#define F first
#define S second

typedef long long ll;
typedef pair < int, int>  ii;

// freopen("in.txt", "r", stdin);
//freopen("out.txt", "w", stdout);

int main(){
    
    int m,n;
    while( scanf("%d%d", &n, &m) && m+n ){
        int mat[n][m];
        rep(i,0,n)
            rep(j,0,m)
                scanf("%d", &mat[i][j]);
        
        int aux = 0, a = 0, cont = 0;   
        
        // Ninguém resolveu todos os problemas.
        for( int i = 0 ; i < n ; i++){
            aux = 0;  
            for( int j = 0 ; j < m ; j++){
                aux += mat[i][j];
            }
            if( aux < m ){
                a++;
            }
        }
        if( a == n ){
            cont++;
            a = 0;
            //printf("Entrei 1\n");
        }
           
        // Todo problema foi resolvido por pelo menos uma pessoa (não necessariamente a mesma).
        aux=0,a=0;
        for( int j = 0 ; j < m ; j++){
            aux = 0;  
            for( int i = 0 ; i < n ; i++){
                aux += mat[i][j];
            }
            if( aux > 0 ){
                a++;
            }
        }
        if( a == m ){
            cont++;
            a = 0;
            //printf("Entrei 2\n");
        }     
        // Não há nenhum problema resolvido por todos.
        aux=0,a=0; 
        for( int j = 0 ; j < m ; j++){
            aux = 0;  
            for( int i = 0 ; i < n ; i++){
                aux += mat[i][j];
            }
            if( aux < n ){
                a++;
            }
        }
        if( a == m ){
            cont++;
            a = 0;
            //printf("Entrei 3\n");
        }
        
        // Todos resolveram ao menos um problema (não necessariamente o mesmo).
        aux=0,a=0;
        for( int i = 0 ; i < n ; i++){
            aux = 0;  
            for( int j = 0 ; j < m ; j++){
                aux += mat[i][j];
            }
            if( aux > 0 ){
                a++;
            }
        }
        if( a == n ){
            cont++;
            a = 0;
            //printf("Entrei 4\n");
        }       
                   
        printf("%d\n", cont);
            
    }   
    
    return 0;
}
