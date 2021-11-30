// Author: Gustavo Policarpo
// Name: Help Seu Madruga
// Level: 8
// Category: PARADIGMS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1912

	//#define gc getchar_unlocked
	#include<bits/stdc++.h>
	
	//LIFE IS NOT A PROBLEM TO BE SOLVED
	
	using namespace std;
	
	#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)
	#define reo(i,a,b) for(int i = int(a); i > int(b) ; i--)
	#define rei(i,a,b) for(int i = int(a); i < int(b) ; i=i)
	#define pb push_back
	#define mp make_pair
	#define F first
	#define S second
	
	#define INF 0x3F3F3F3F
	#define MAXV 100001
	#define mod 1000000007
	#define error 0.0001
	
	typedef long long int ll;
	typedef unsigned long long int ull;
	typedef pair < int, int > ii;
	typedef pair < int, ii > iii;
	
	
	int N, A, n[1000001];
	int main(){
	    while(scanf("%d %d", &N, &A) and N+A){
	        int aux, st=0; 
	        rep(i, 0, N){
	            scanf("%d", &n[i]);
	            st+=n[i];
	        }
	        if(st<A){
	            printf("-.-\n");
	            continue;
	        }
	        else if(st==A){
	            printf(":D\n");
	            continue;
	        }
	        bool yep=false;
	        double ini=0.0, fim=100001.0, atual=(ini+fim)/2.0;
	        while(fim-ini>0.000001){
	            double at=0.0;
	            rep(i, 0, N){
	                if(n[i]>atual){
	                	at+=(n[i]-atual);
	                }
	            }
	            if(fabs(at-A)<error){
	                printf("%.4lf\n", atual);
	                yep=true;
	                break;
	            }
	            if(at<A){
	                fim=atual;
	                atual=(fim+ini)/2.0;
	            }
	            if(at>A){
	                ini=atual;
	                atual=(fim+ini)/2.0;
	            }
	        }
	        if(yep) continue;
	        printf("%.4lf\n", atual);
	    }
	    return 0;
	}

