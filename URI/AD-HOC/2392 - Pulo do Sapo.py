# Author: Gustavo Policarpo
# Name: Pulo do Sapo
# Level: 3
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2392

n, m = map( int, raw_input().split() )
v = [0]*(n+1)
for i in range(m):
    p, s = map( int, raw_input().split() )
    v[p] = 1
    pp = p
    while 42:
        pp = pp - s
        if pp < 1:
            break
        v[pp] = 1
    while 42:
        pp = pp + s
        if pp > n:
            break
        v[pp] = 1
for i in range(1, n+1):
    print v[i]

