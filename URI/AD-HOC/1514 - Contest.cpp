// Author: Gustavo Policarpo
// Name: Contest
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1514

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;



int main()
{
	int N, M;
	while(cin >> N >> M)
	{
		int s[4];
		s[0]=1; s[1]=1; s[2]=1; s[3]=1;
		if(N==0&&M==0) break;
		int R[N][M];
		for(int i=0; i<N; i++)
		{
			int P14=0;
			for(int j=0; j<M; j++)
			{
				int temp;
				cin >> temp;
				R[i][j]=temp;
				if(temp==1) P14++;
			}
			if(P14==0) s[3]=0;
			if(P14==M) s[0]=0;
		}
		for(int j=0; j<M; j++)
		{
			int P23=0;
			for(int i=0; i<N; i++)
			{
				int temp;
				temp=R[i][j];
				if(temp==1) P23++;
			}
			if(P23==0) s[1]=0;
			if(P23==N) s[2]=0;
		}		
		int result=0;
		for(int i=0; i<4; i++) result+=s[i];
		
		cout << result << endl;
		
			
	}
return(0); 
}


