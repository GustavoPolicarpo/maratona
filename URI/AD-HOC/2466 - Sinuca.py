# Author: Gustavo Policarpo
# Name: Sinuca
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2466

n = input()
mat = []
for i in range (n):
    mat.append([0]*n)
mat[0] = map ( int, raw_input().split() )

i=1
while(42):
    for j in range (n-i):
        if mat[i-1][j] == mat[i-1][j+1]:
            mat[i][j]=1
        else:
            mat[i][j]=-1
    i=i+1
    if i == n:
        break
    
if mat[n-1][0] == -1:
    print "branca"
else:
    print "preta"
