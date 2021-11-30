# Author: Gustavo Policarpo
# Name: Sedex
# Level: 1
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2375

n = input()
a, b, c = map( int, raw_input().split() )
if (n <= a) & (n <= b) & (n <= c):
    print "S"
else:
    print "N"

