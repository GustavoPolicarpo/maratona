# Author: Gustavo Policarpo
# Name: Corrida
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2435

a, b, c = map (int, raw_input().split() )
d, e, f = map (int, raw_input().split() )
g = float(b)/c
h = float(e)/f
if g<h:
    print a
else:
    print d
