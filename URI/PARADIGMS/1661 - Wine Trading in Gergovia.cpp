// Author: Gustavo Policarpo
// Name: Wine Trading in Gergovia
// Level: 5
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1661

#include<bits/stdc++.h>

//LIFE IS NOT A PROBLEM TO BE SOLVED

using namespace std;

#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
#define pb push_back
#define mp make_pair


int main ()
{
   long long int N, c, v, d[100001], t;
   while (cin >> N && N){
      for (int i=0; i<N; i++){
            cin >> d[i];
      }
      t=0;
      for (int i=1; i<N; i++){
         if (d[i-1]<0){
               t=t+(-1)*d[i-1];
         }
         else {
               t+=d[i-1];
         }
         d[i]+=d[i-1];
      }
      cout << t << endl;
      }
}
   
