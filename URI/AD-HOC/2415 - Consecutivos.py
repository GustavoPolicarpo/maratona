# Author: Gustavo Policarpo
# Name: Consecutivos
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2415

n = input()
v = [0]*n
v = map( int, raw_input().split() )

ans = 1
aux = 1
atual = v[0]

for i in range(1, n):
    if v[i] == atual :
        aux = aux+1
    else :
        atual = v[i]
        ans = max(ans, aux)
        aux = 1

ans = max(ans, aux)

print ans
