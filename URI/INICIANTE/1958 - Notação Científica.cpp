// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Notação Científica
// Nível: 1
// Categoria: INICIANTE
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1958

#include<iostream>
#include<iomanip>
#include<string>
#include<sstream>
#include<cctype>


//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

long double num;
stringstream ss;
string S;

int main()
{
	
    cin>>num;
    ss<<setprecision(4)<<scientific<<showpos<<uppercase<<num;
    S = ss.str();
    if(S[S.size()-3]=='0') S.erase(S.size()-3,1);
    cout<<S<<endl;
    return 0;
}

