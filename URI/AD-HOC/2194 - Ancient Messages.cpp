// Author: Gustavo Policarpo
// Name: Ancient Messages
// Level: 5
// Category: AD-HOC
// URL: https://www.beecrowd.com.br/judge/en/problems/view/2194

#define gc getchar_unlocked
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

typedef long long int ll;
typedef unsigned long long int ull;
typedef pair < int, int > ii;
typedef pair < double, int > iii;


char hexa[55], convert[5];
int W, H, z=1, mat[210][210], dx[]={-1, 0, 0, 1}, dy[]={0, -1, 1, 0};

void dfs(int x, int y){
	if(x<0 || y<0 || x>W+1 || y>H+1 || mat[x][y]!=0) return;
	//cout << x << " " << y << endl;
	mat[x][y]=-1;
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		dfs(ax, ay);
	}
	return;	
}

void bfs(int x, int y){
	queue <ii> q;
	q.push(mp(x, y)); mat[x][y]=-1;
	while(!q.empty()){
		//cout << q.size() << endl;
		x=q.front().F, y=q.front().S; q.pop();
		rep(i, 0, 4){
			int ax=x+dx[i], ay=y+dy[i];
			if(ax<0 || ay<0 || ax>W+1 || ay>H+1 || mat[ax][ay]!=0) continue;
			mat[ax][ay]=-1;
			q.push(mp(ax, ay));
		}
	}
	return;
}

void DFS(int x, int y, int &cnt){
	if(x<1 || y<1 || x>W || y>H || mat[x][y]==-1) return;
	if(mat[x][y]==0){
		cnt++;
		bfs(x, y);
	}
	mat[x][y]=-1;
	rep(i, 0, 4){
		int ax=x+dx[i], ay=y+dy[i];
		DFS(ax, ay, cnt);
	}
	return;	

}

vector <char> out;
void gofind(){
	
	rep(i, 1, W+1)
	rep(j, 1, H+1)
	if(mat[i][j]==1){
	//	cout << i << " " << j << endl;
		int cnt=0;
		DFS(i, j, cnt);
		if(cnt==0) out.pb('W');
        else if(cnt==1) out.pb('A');
        else if(cnt==2) out.pb('K');
        else if(cnt==3) out.pb('J');
        else if(cnt==4) out.pb('S');
        else if(cnt==5) out.pb('D');
	}
	return;	
}

int main()
{
	//freopen("in.txt", "r", stdin);
	//freopen("out.txt", "w", stdout);
	while(scanf("%d %d", &W, &H) and W+H){
		rep(i, 0, W){
			scanf("%s", hexa);
			rep(j, 0, H){
				     if(hexa[j]=='0') strcpy(convert,"0000");
				else if(hexa[j]=='1') strcpy(convert,"0001");
				else if(hexa[j]=='2') strcpy(convert,"0010");
				else if(hexa[j]=='3') strcpy(convert,"0011");
				else if(hexa[j]=='4') strcpy(convert,"0100");
				else if(hexa[j]=='5') strcpy(convert,"0101");
				else if(hexa[j]=='6') strcpy(convert,"0110");
				else if(hexa[j]=='7') strcpy(convert,"0111");
				else if(hexa[j]=='8') strcpy(convert,"1000");
				else if(hexa[j]=='9') strcpy(convert,"1001");
				else if(hexa[j]=='a') strcpy(convert,"1010");
				else if(hexa[j]=='b') strcpy(convert,"1011");
				else if(hexa[j]=='c') strcpy(convert,"1100");
				else if(hexa[j]=='d') strcpy(convert,"1101");
				else if(hexa[j]=='e') strcpy(convert,"1110");
				else if(hexa[j]=='f') strcpy(convert,"1111");
				rep(k, 0, 4) mat[i+1][j*4+k+1]=convert[k]-'0';
			}
		}
		H*=4; out.clear();
		rep(i, 0, W+2) mat[i][0]=mat[i][H+1]=0;
		rep(j, 0, H+2) mat[0][j]=mat[W+1][j]=0;
		
		/*rep(i, 0, W+2){
			rep(j, 0, H+2)
				cout << mat[i][j];
			cout << endl;
		}*/
		
		rep(i, 0, W+2)
		rep(j, 0, H+2)
			if(mat[i][j]==0){
				bfs(i, j);
				gofind();				
			}
		
		sort(out.begin(), out.end());
		printf("Case %d: ", z++);
		rep(i, 0, out.size()) printf("%c", out[i]);
		printf("\n");	
	}	

return 0;
}


