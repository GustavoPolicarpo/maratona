// Author: Gustavo Policarpo
// Name: System of a Download
// Level: 2
// Category: BEGINNER
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2582

#include <stdio.h>
#include <stdlib.h>
#include <math.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED


int main()
{
	
	int T, a, b, s; scanf("%d", &T);
	
	while(T--){
		scanf("%d %d", &a, &b); s=a+b;
		
		if(s==0) puts("PROXYCITY");
		else if(s==1) puts("P.Y.N.G.");
		else if(s==2) puts("DNSUEY!");
		else if(s==3) puts("SERVERS");
		else if(s==4) puts("HOST!");
		else if(s==5) puts("CRIPTONIZE");
		else if(s==6) puts("OFFLINE DAY");
		else if(s==7) puts("SALT");
		else if(s==8) puts("ANSWER!");
		else if(s==9) puts("RAR?");
		else if(s==10) puts("WIFI ANTENNAS");
		
	}
	
	return 0;
	
}


