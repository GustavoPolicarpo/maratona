# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: O Tabuleiro Esburacado
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2411

dx = []
dy = []
dx.append(-2)
dx.append(-1)
dx.append(1)
dx.append(2)
dx.append(2)
dx.append(1)
dx.append(-1)
dx.append(-2)
dy.append(1)
dy.append(2)
dy.append(2)
dy.append(1)
dy.append(-1)
dy.append(-2)
dy.append(-2)
dy.append(-1)

mat = []
for i in range(10) :
    mat.append([0]*10)
mat[4][1] = 1
mat[4][2] = 1
mat[2][2] = 1
mat[3][5] = 1

xp = 4
yp = 4
move = 0

n = input()
v = [0]*n
v = map( int, raw_input().split() )

for i in range(n) :
    move = move+1
    xp = xp+dx[v[i]-1]
    yp = yp+dy[v[i]-1]

    if mat[xp][yp] == 1 :
        break

print move
