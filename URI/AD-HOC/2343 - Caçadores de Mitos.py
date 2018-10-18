# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Caçadores de Mitos
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2343

n = input()
mat = []
for i in range (501):
	mat.append([0]*501)
yep = 0
for i in range (n):
	x, y = map( int, raw_input().split() )
	if mat[x][y] == 1:
		yep=1
	mat[x][y]=1
if yep == 1:
	print 1
else:
	print 0
