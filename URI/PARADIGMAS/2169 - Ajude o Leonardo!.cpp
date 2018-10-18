// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Ajude o Leonardo!
// Nível: 4
// Categoria: PARADIGMAS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2169

#include <bits/stdc++.h>
 
using namespace std;
 
int resistencia = 0, n_arma, pd[10][10010];
 
vector < pair < int, double > > v;  // first = quant de balas    second = potencia  
 
void arma(string a, int b){
 
	if(a == "HANDGUN")  v.push_back({b, 2});
	else if(a == "RED9")  v.push_back({b, 3.5});
	else if(a == "BLACKTAIL")   v.push_back({b, 3.5});
	else if(a == "MATILDA")   v.push_back({b, 2});
	else if(a == "HANDCANNON")   v.push_back({b, 60});
	else if(a == "STRIKER")   v.push_back({b, 12});
	else if(a == "TMP")   v.push_back({b, 1.2});
	else if(a == "RIFLE")   v.push_back({b, 12});						
}
 
void monstro(string a, int b){
 
	if(a == "GANADOS")   resistencia += b*50;
	else if(a == "COBRAS")   resistencia += b*40;
	else if(a == "ZEALOT")   resistencia += b*75;
	else if(a == "COLMILLOS")   resistencia += b*60;
	else if(a == "GARRADOR")   resistencia += b*125;
	else if(a == "LASPLAGAS")   resistencia += b*100;
	else if(a == "GATLINGMAN")   resistencia += b*150;
	else if(a == "REGENERATOR")   resistencia += b*250;
	else if(a == "ELGIGANTE")   resistencia += b*500;
	else if(a == "DR.SALVADOR")   resistencia += b*350;
 
}
 
double solve(int i, int u){  // u = numero max de balas
 
	if(i == n_arma) return 0;
	if(pd[i][u] != -1) return pd[i][u];
 
	double a = 0, b = 0;
 
	a = solve(i+1, u);
 
	if(u >= v[i].first)
		b = solve(i+1, u - v[i].first) + ((double)v[i].first*v[i].second);
 
	return pd[i][u] = max(a, b);
}
 
int main(){
 
	while(cin >> n_arma){
 
		v.clear();
		resistencia = 0;
 
		for(int i = 0; i < n_arma; i++){
			string a;
			int bala;
			cin >> a >> bala;
			arma(a, bala);
		}
		int n_monstro;
		cin >> n_monstro;
		for(int i = 0; i < n_monstro; i++){
 
			string a;
			int res;
			cin >> a >> res;
			monstro(a, res);
 
		}
		int balas;
		cin >> balas;
 
		for(int i = 0; i < n_arma+1; i++)
			for(int j = 0; j < balas+1; j++)
				pd[i][j] = -1;
 
		double x = solve(0, balas);
		//cout << x << "  " << resistencia << endl;
		if(x >= resistencia)
			cout << "Missao completada com sucesso" << endl;
		else
			cout << "You Are Dead" << endl;	
		cout << endl;	
 
	}
 
	return 0;
}
