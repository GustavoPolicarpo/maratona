# Author: Gustavo Policarpo
# Name: Supermercado
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/3058

N = int(input())
ans = 1e30
for i in range (N):
    p, g = input().split(' ')
    p = float(p)
    g = int(g)
    ans = min(ans, (1000.0/g)*p)

print("{0:.2f}".format(ans))
