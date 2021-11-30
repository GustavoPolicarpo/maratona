# Author: Gustavo Policarpo
# Name: Cards
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2456

v = [0]*(5)
v = map( int, raw_input().split() )

c = 1
d = 1
for i in range(1, 5):
    if(v[i] < v[i-1]):
        c=0
        break
for i in range(3, 0, -1):
    if(v[i] < v[i+1]):
        d=0
        break
if c==1:
    print "C"
if d==1:
    print "D"
if (c==0 and d==0):
    print "N"
