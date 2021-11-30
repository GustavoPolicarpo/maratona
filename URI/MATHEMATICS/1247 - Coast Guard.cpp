// Author: Gustavo Policarpo
// Name: Coast Guard
// Level: 2
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1247

#include<bits/stdc++.h>

using namespace std;

int D, VF, VG;
double TF, TG;

int main()
{
	while(cin >> D >> VF >> VG)
	{
		TF=(double)(12.0/VF);
		TG=(double)((sqrt(D*D+144.0))/VG);
		if(TG<=TF) cout << "S" << endl;
		else cout << "N" << endl;
	}
	
}

