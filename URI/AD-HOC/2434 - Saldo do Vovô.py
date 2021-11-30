# Author: Gustavo Policarpo
# Name: Saldo do Vovô
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2434

n, m = map (int, raw_input().split() )
ans = m
for i in range(n):
    aux = input()
    m = m+aux
    if m < ans:
        ans = m
print ans
