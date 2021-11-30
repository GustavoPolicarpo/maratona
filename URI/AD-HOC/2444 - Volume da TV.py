# Author: Gustavo Policarpo
# Name: Volume da TV
# Level: 2
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2444

v, t = map( int, raw_input().split() )
n = [0]*t
n = map( int, raw_input().split() )
for i in range(t):
    v = v+n[i]
    if(v>100):
        v=100
    if(v<0):
        v=0
print v
