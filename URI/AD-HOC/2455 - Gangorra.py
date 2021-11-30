# Author: Gustavo Policarpo
# Name: Gangorra
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2455

v = [0]*(4)
v = map( int, raw_input().split() )

a = v[0]*v[1]
b = v[2]*v[3]

if a==b:
    print 0
if a<b:
    print 1
if a>b:
    print -1
