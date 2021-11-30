# Author: Gustavo Policarpo
# Name: Corredor
# Level: 4
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2463

n = input()
v = [0]*(n)
v = map( int, raw_input().split() )

ans = 0
atual = 0

for i in range(n):
    atual = atual + v[i]
    if atual < 0:
        atual = 0
        continue
    if ans < atual:
        ans = atual

print ans
