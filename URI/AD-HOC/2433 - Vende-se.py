# Author: Gustavo Policarpo
# Name: Vende-se
# Level: 6
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2433

n, m = map (int, raw_input().split() )
v = [0]*(n)
v = map (int, raw_input().split() )
v.sort()
ans = 1000010
for i in range(n-(n-m)+1):
    aux = v[i+(n-m)-1]-v[i]
    if aux < 0:
        aux = aux*-1
    if ans > aux:
        ans = aux
print ans
