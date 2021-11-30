# Author: Gustavo Policarpo
# Name: Frequencia na Aula
# Level: 4
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2410

v = [0]*1000010
n = input()
for i in range(n):
    aux = input()
    v[aux] = 1
ans = 0
for i in range(1000010):
    if v[i] == 1:
        ans = ans+1

print ans
