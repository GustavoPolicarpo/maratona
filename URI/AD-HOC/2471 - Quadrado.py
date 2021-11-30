# Author: Gustavo Policarpo
# Name: Quadrado
# Level: 3
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2471

n = input()
mat = []
for i in range (n):
    mat.append([]*n)
for i in range(n):
    mat[i] = map ( int, raw_input().split() )

l = [0]*n
c = [0]*n

for i in range (n):
    for j in range(n):
        l[i] = l[i] + mat[i][j]
for j in range (n):
    for i in range(n):
        c[j] = c[j] + mat[i][j]

lc=0
ll=0
cc=0

if l[0] == l[1] : lc = l[0]
if l[0] == l[2] : lc = l[0]
if l[1] == l[2] : lc = l[1]

for i in range (n):
    if l[i] != lc:
        ll = i
        break
for j in range (n):
    if c[j] != lc:
        cc = j
        break

pos = mat[ll][cc]
ori = lc-l[ll]+pos

print ori, pos

