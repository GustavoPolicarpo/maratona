// Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
// Nome: Frase Completa
// Nível: 3
// Categoria: STRINGS
// URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1551

#include<bits/stdc++.h>
//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;


int N, S;
int C[26];
string F;
char f;

int main()
{
	cin >> N;
	cin.ignore();
	while(N--)
	{
		S=0;
		for(int i=0; i<26; i++) C[i]=0;
		getline(cin, F);
		for(int i=0; i<F.size(); i++)
		{
			f=F[i];
			switch(f)
			{
				case 'a': C[0]=1; break;
				case 'b': C[1]=1; break;
				case 'c': C[2]=1; break;
				case 'd': C[3]=1; break;
				case 'e': C[4]=1; break;
				case 'f': C[5]=1; break;
				case 'g': C[6]=1; break;
				case 'h': C[7]=1; break;
				case 'i': C[8]=1; break;
				case 'j': C[9]=1; break;
				case 'k': C[10]=1; break;
				case 'l': C[11]=1; break;
				case 'm': C[12]=1; break;
				case 'n': C[13]=1; break;
				case 'o': C[14]=1; break;
				case 'p': C[15]=1; break;
				case 'q': C[16]=1; break;
				case 'r': C[17]=1; break;
				case 's': C[18]=1; break;
				case 't': C[19]=1; break;
				case 'u': C[20]=1; break;
				case 'v': C[21]=1; break;
				case 'x': C[22]=1; break;
				case 'w': C[23]=1; break;
				case 'y': C[24]=1; break;
				case 'z': C[25]=1; break;
			}
		}
		for(int i=0; i<26; i++) S=S+C[i];
		if(S>=26) cout << "frase completa" << endl;
		else if(S>=13) cout << "frase quase completa" << endl;
		else cout << "frase mal elaborada" << endl;
		
	}
}
