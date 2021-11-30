# Author: Gustavo Policarpo
# Name: Distância de Manhattan
# Level: 4
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2437

a, b, c, d = map( int, raw_input().split() )
out = 0
if c > a:
    out = out+c-a
else:
    out = out+a-c
if d > b:
    out = out+d-b
else:
    out = out+b-d
print out
