# Author: Gustavo Policarpo
# Name: Escada Rolante
# Level: 3
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2390

n = input()
ans = n*10
last = -100
for i in range(n):
    atual = input()
    if last + 10 > atual:
        ans = ans - (last + 10 - atual)
    last = atual
print ans

