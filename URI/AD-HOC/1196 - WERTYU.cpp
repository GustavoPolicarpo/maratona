// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: WERTYU
// Nível: 2
// Categoria: AD-HOC
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1196

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

string F, C;
stack <char> f;




int main()
{
	while(getline(cin,F))
	{	
		for(int i=0; i<F.size(); i++)
		{
			f.push(F[i]);
			if(f.top()=='=') cout << '-';
			else if(f.top()=='-') cout << '0';
			else if(f.top()=='0') cout << '9';
			else if(f.top()=='9') cout << '8';
			else if(f.top()=='8') cout << '7';
			else if(f.top()=='7') cout << '6';
			else if(f.top()=='6') cout << '5';
			else if(f.top()=='5') cout << '4';
			else if(f.top()=='4') cout << '3';
			else if(f.top()=='3') cout << '2';
			else if(f.top()=='2') cout << '1';
			else if(f.top()=='1') cout << '`';
			else if(f.top()=='\\') cout << ']';
			else if(f.top()==']') cout << '[';
			else if(f.top()=='[') cout << 'P';
			else if(f.top()=='P') cout << 'O';
			else if(f.top()=='O') cout << 'I';
			else if(f.top()=='I') cout << 'U';
			else if(f.top()=='U') cout << 'Y';
			else if(f.top()=='Y') cout << 'T';
			else if(f.top()=='T') cout << 'R';
			else if(f.top()=='R') cout << 'E';
			else if(f.top()=='E') cout << 'W';
			else if(f.top()=='W') cout << 'Q';
			else if(f.top()=='\'') cout << ';';
			else if(f.top()==';') cout << 'L';
			else if(f.top()=='L') cout << 'K';
			else if(f.top()=='K') cout << 'J';
			else if(f.top()=='J') cout << 'H';
			else if(f.top()=='H') cout << 'G';
			else if(f.top()=='G') cout << 'F';
			else if(f.top()=='F') cout << 'D';
			else if(f.top()=='D') cout << 'S';
			else if(f.top()=='S') cout << 'A';
			else if(f.top()=='/') cout << '.';
			else if(f.top()=='.') cout << ',';
			else if(f.top()==',') cout << 'M';
			else if(f.top()=='M') cout << 'N';
			else if(f.top()=='N') cout << 'B';
			else if(f.top()=='B') cout << 'V';
			else if(f.top()=='V') cout << 'C';
			else if(f.top()=='C') cout << 'X';
			else if(f.top()=='X') cout << 'Z';
			else cout << f.top();
		}
		cout << endl;
		
	}
	
	
return(0);	
}
	



