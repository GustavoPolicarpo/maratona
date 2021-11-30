// Author: Gustavo Policarpo
// Name: Genetic Algorithm
// Level: 4
// Category: MATHEMATICS
// URL: https://www.beecrowd.com.br/judge/en/problems/view/1756

#include <stdio.h>

int main()
{
	
	int T; scanf("%d", &T);
	while(T--){
		int n; scanf("%d", &n);
		int y; double p; scanf("%d %lf ", &y, &p);
		
		int i;
		char a[n], b[n], c[n], ind[n];
		double pa=1.0, pb=1.0, ans=0.0;
		scanf("%s", a);
		scanf("%s", b);
		scanf("%s", ind);
		
		for( i=0; i<y; i++ ) c[i]=a[i];
		for( i=y; i<n; i++ ) c[i]=b[i];
		for( i=0; i<y; i++ ) {
			if(c[i]==ind[i]) pa*=(1.0-p);
			else pa*=(p);
		}
		for( i=y; i<n; i++ ) {
			if(c[i]==ind[i]) pa*=(1.0-p);
			else pa*=(p);
		}
		
		for( i=0; i<y; i++ ) c[i]=b[i];
		for( i=y; i<n; i++ ) c[i]=a[i];
		for( i=0; i<y; i++ ) {
			if(c[i]==ind[i]) pb*=(1.0-p);
			else pb*=(p);
		}
		for( i=y; i<n; i++ ) {
			if(c[i]==ind[i]) pb*=(1.0-p);
			else pb*=(p);
		}
		
		ans=pa+pb;
		
		pa=pb=1.0;
		for( i=0; i<n; i++ ) {
			if(a[i]==ind[i]) pa*=(1.0-p);
			else pa*=(p);
			if(b[i]==ind[i]) pb*=(1.0-p);
			else pb*=(p);
		}
		
		ans-=(pa*pb);
		
		printf("%.7lf\n", ans);
		
	}
	
	return 0;
		
}
