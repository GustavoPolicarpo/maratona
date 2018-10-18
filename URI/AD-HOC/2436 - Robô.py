# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Robô
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2436

mat = []
vis = []
dx = []
dy = []

n, m = map (int, raw_input().split() )
for i in range(n):
    mat.append([0]*m)
    vis.append([0]*m)
    
def dentro(x, y):
    if ( x>=0 and y>=0 and x<n and y<m and mat[x][y]==1 and vis[x][y]==0 ):
        return 1
    else:
        return 0
    
dx.append(-1)
dx.append(0)
dx.append(0)
dx.append(1)
dy.append(0)
dy.append(-1)
dy.append(1)
dy.append(0)

x, y = map (int, raw_input().split() )
x = x-1
y = y-1
for i in range(n):
    mat[i] = map ( int, raw_input().split() )

while(42):
    yep=0
    vis[x][y]=1
    for i in range(4):
        ax=x+dx[i]
        ay=y+dy[i]
        if( dentro(ax, ay) ):
            x=ax
            y=ay
            yep=1
            break
    if yep == 0:
        print x+1, y+1
        break
