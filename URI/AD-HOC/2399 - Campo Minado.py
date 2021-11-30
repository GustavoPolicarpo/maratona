# Author: Gustavo Policarpo
# Name: Campo Minado
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2399

n = input()
v = []
for i in range(n+2):
    v.append(0)
for i in range(1,n+1):
    v[i] = input()
for i in range(1,n+1):
    print v[i] + v[i-1] + v[i+1]
