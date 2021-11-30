// Author: Gustavo Policarpo
// Name: Santa's Translator
// Level: and
// Category: DATA
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1763

# include <bits/stdc++.h>

using namespace std;

int main()
{
	map <string, string> l;
	
	l["brasil"] = "Feliz Natal!";
	l["alemanha"] = "Frohliche Weihnachten!";
	l["austria"] = "Frohe Weihnacht!";
	l["coreia"] = "Chuk Sung Tan!";
	l["espanha"] = "Feliz Navidad!";
	l["grecia"] = "Kala Christougena!";
	l["estados-unidos"] = "Merry Christmas!";
	l["inglaterra"] = "Merry Christmas!";
	l["australia"] = "Merry Christmas!";
	l["portugal"] = "Feliz Natal!";
	l["suecia"] = "God Jul!";
	l["turquia"] = "Mutlu Noeller";
	l["argentina"] = "Feliz Navidad!";
	l["chile"] = "Feliz Navidad!";
	l["mexico"] = "Feliz Navidad!";
	l["antardida"] = "Merry Christmas!";
	l["canada"] = "Merry Christmas!";
	l["irlanda"] = "Nollaig Shona Dhuit!";
	l["belgica"] = "Zalig Kerstfeest!";
	l["italia"] = "Buon Natale!";
	l["libia"] = "Buon Natale!";
	l["siria"] = "Milad Mubarak!";
	l["marrocos"] = "Milad Mubarak!";
	l["japao"] = "Merii Kurisumasu!";
	
	string T;
	while(cin >> T)
	{
		if(l.count(T))
		{
			cout << l[T];
		}
			
		else
			cout << "--- NOT FOUND ---";
			
		cout << endl;		
	}

return 0;
}
