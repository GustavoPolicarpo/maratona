# Author: Gustavo Policarpo
# Name: Passa Bolinha
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2465

vis = []
mat = []
dx = []
dy = []
n = 0

def dentro(x, y, val):
    if ( x>=0 and y>=0 and x<n and y<n and mat[x][y]>=val ):
        return 1
    else:
        return 0
    
def dfs(x, y):
    if vis[x][y] == 1:
        return;
    vis[x][y] = 1
    for i in range(4):
        ax = x+dx[i]
        ay = y+dy[i]
        if ( dentro(ax, ay, mat[x][y]) == 1 ):
            dfs(ax, ay)

dx.append(-1)
dx.append(0)
dx.append(0)
dx.append(1)
dy.append(0)
dy.append(-1)
dy.append(1)
dy.append(0)

n = input()
for i in range(n):
    vis.append([0]*n)
    mat.append([0]*n)

x, y = map (int, raw_input().split() )
for i in range(n):
    mat[i] = map ( int, raw_input().split() )

dfs(x-1, y-1)

ans = 0
for i in range(n):
    for j in range(n):
        if vis[i][j] == 1:
            ans = ans+1
            
print ans
