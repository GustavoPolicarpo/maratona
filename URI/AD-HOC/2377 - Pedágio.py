# Author: Gustavo Policarpo
# Name: Pedágio
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2377

n, m = raw_input().split()
n = int(n)
m = int(m)
k, p = raw_input().split()
k = int(k)
p = int(p)
ans = n*k + n/m*p
print ans
    

