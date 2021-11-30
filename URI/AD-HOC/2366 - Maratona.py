# Author: Gustavo Policarpo
# Name: Maratona
# Level: 5
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2366

n, m = map (int, raw_input().split() )
v = [0]*(n)
v = map (int, raw_input().split() )
yep = 1
for i in range(n-1):
    if v[i+1]-v[i] > m:
        yep=0
        break
if 42195-v[n-1] > m:
    yep=0
if yep:
    print "S"
else:
    print "N"


