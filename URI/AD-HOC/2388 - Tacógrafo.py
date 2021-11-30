# Author: Gustavo Policarpo
# Name: Tacógrafo
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2388

n = input()
ans = 0
for i in range(n):
    t, v = map (int, raw_input().split() )
    ans = ans + t * v
print ans


