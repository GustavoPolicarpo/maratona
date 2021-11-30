# Author: Gustavo Policarpo
# Name: Colchão
# Level: 5
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2409

v = [0]*3
v = map( int, raw_input().split() )
v.sort()
h, l = map( int, raw_input().split() )

if ( min(h, l) >= v[0] ) and ( max(h, l) >= v[1] ) :
    print "S"
else :
    print "N"
