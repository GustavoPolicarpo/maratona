# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Colorindo
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2405

dx = [0]*8
dy = [0]*8
dx = [-1, -1, -1, 0, 0, 1, 1, 1]
dy = [-1, 0, 1, -1, 1, -1, 0, 1]
mat = []

import sys
sys.setrecursionlimit(40000)

def dentro(x, y):
    if ((x>=0) and (y>=0) and (x<n) and (y<m) and (mat[x][y]==0)) :
        return 1
    return 0

def dfs(x, y):
    mat[x][y] = 1
    for i in range(8):
        ax = x+dx[i]
        ay = y+dy[i]
        if dentro(ax, ay) == 0 : continue
        dfs(ax, ay)
    return

n, m, x, y, k = map( int, raw_input().split() )
for i in range(n+1) :
    mat.append([0]*(m+1))

for i in range(k):
    xx, yy = map( int, raw_input().split() )
    xx = xx-1
    yy = yy-1
    mat[xx][yy] = 2

dfs(x-1, y-1)

cnt = 0

for i in range(n):
    for j in range(m):
        if mat[i][j] == 1:
            cnt = cnt+1

print cnt


