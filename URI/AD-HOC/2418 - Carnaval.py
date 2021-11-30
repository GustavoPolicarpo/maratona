# Author: Gustavo Policarpo
# Name: Carnaval
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2418

v = [0]*(5)
v = map (float, raw_input().split() )
v.sort()

sum = v[1] + v[2] + v[3]
sum = round(sum, 1)

print sum

