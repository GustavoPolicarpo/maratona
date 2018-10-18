// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Amigos do Habay
// Nível: 2
// Categoria: ESTRUTURAS E BIBLIOTECAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2136

#include <bits/stdc++.h>

using namespace std;

struct pessoas
{
    string nome;
    int tam;
};

bool cmp(pessoas a, pessoas b){
    return a.tam > b.tam;
}

int main(int argc, char** argv)
{
    struct pessoas aux; string s,t;
    map <string, int> m, n;
    map <string, int> :: iterator it;
    vector <pessoas> v; 
    while( cin >> s )
    {
        if(s=="FIM") break;
        cin >> t; 
        if(t=="YES"){
            aux.tam=s.size();
            aux.nome=s;
            v.push_back(aux);
            m[s]++;
        } 
        else n[s]++;
    }
    for(it=m.begin(); it!=m.end(); it++)
        cout<<it->first<<endl;  
    for(it=n.begin(); it!=n.end(); it++)
        cout<<it->first<<endl;
    cout<<'\n';
    
    stable_sort(v.begin(),v.end(),cmp);
    cout<<"Amigo do Habay:\n";
    cout<<v[0].nome<<endl;
    
    return 0;
}
