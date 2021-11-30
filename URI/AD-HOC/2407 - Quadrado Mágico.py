# Author: Gustavo Policarpo
# Name: Quadrado Mágico
# Level: 8
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2407

vis = [0]*1000010
mat = []
n = input()
for i in range(n) :
    mat.append([0]*n)

yep = 1
for i in range(n) :
    mat[i] = map( int, raw_input().split() )
    for j in range(n) :
        if( (mat[i][j] > n*n) or (vis[mat[i][j]] == 1) ):
            yep = 0
            break
        vis[mat[i][j]] = 1
    if yep == 0 :
        break

if yep == 0 :
    print 0

else :
    soma = 0
    for i in range(n) :
        soma = soma+mat[i][0]
        
    for i in range(n) :
        if yep == 0 :
            break
        aux = 0
        for j in range(n) :
            aux = aux+mat[i][j]
        if aux!=soma :
            yep = 0
            break

    for i in range(n) :
        if yep == 0 :
            break
        aux = 0
        for j in range(n) :
            aux = aux+mat[j][i]
        if aux!=soma :
            yep = 0
            break

    aux = 0
    for i in range(n) :
        if yep == 0 :
            break
        aux = aux + mat[i][i]

    if aux !=soma :
        yep = 0

    aux = 0
    for i in range(n) :
        if yep == 0 :
            break
        aux = aux + mat[i][n-i-1]

    if aux !=soma :
        yep = 0

    if yep == 0 :
        print 0
    else :
        print soma
