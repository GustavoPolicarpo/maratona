# Author: Gustavo Policarpo
# Name: Álbum de Fotos
# Level: 7
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2421

x, y = map ( int, raw_input().split() )
a, b = map ( int, raw_input().split() )
c, d = map ( int, raw_input().split() )

if a + c <= x and max(b, d) <= y :
    print "S"
elif a + c <= y and max(b, d) <= x :
    print "S"
elif a + d <= x and max(b, c) <= y :
    print "S"
elif a + d <= y and max(b, c) <= x :
    print "S"
elif b + d <= x and max(a, c) <= y :
    print "S"
elif b + d <= y and max(a, c) <= x :
    print "S"
elif b + c <= x and max(a, d) <= y :
    print "S"
elif b + c <= y and max(a, d) <= x :
    print "S"
else :
    print "N"
