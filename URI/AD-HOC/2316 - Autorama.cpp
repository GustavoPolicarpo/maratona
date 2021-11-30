// Author: Gustavo Policarpo
// Name: Autorama
// Level: 6
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2316

#include <bits/stdc++.h>
#define rep(i,a,b) for(int i = int(a); i < int(b) ; i++)

struct use{
	int car, nv, pst, time;
};

bool my_sort(use a, use b){
	return 
	a.nv != b.nv ?  a.nv > b.nv :
	a.pst != b.pst ?  a.pst > b.pst :
	a.time != b.time ?  a.time < b.time :
	a.car < b.car;
}
int main()
{
	
	int k, n, m;
	scanf("%d %d %d", &k, &n, &m);
	
	use c[n];
	rep(i, 0, n){
		c[i].car=i+1,
		c[i].nv=0,
		c[i].pst=0,
		c[i].time=0;
	}
	
	int x, y;
	rep(i, 0, m){
		scanf("%d %d", &x, &y);
		x--;
		if(c[x].pst==y-1){
			c[x].pst=y;
			c[x].time=i;
			if(y==k){
				c[x].pst=0;
				c[x].nv++;
			}
		}
	}
	
	std::sort(c, c+n, my_sort);
	
	rep(i, 0, n){
		if(i) printf(" ");
		printf("%d", c[i].car);
	}	printf("\n");
	
	return 0;
		
}
