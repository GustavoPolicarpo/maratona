# Author: Gustavo Policarpo
# Name: Desafio do Maior Número
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2414

v = [0]*150
v = map( int, raw_input().split() )

ans = 0
i = 0
while v[i] != 0 :
    ans = max(ans, v[i])
    i = i+1

print ans
