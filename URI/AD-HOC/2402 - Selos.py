# Author: Gustavo Policarpo
# Name: Selos
# Level: 6
# Category: AD-HOC
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2402

from math import sqrt, ceil
def isPrime(n):
    if n <= 2:
        return 1
    if n%2 == 0:
        return 0
    for i in range(3, int(sqrt(n))+1, 2):
        if n%i == 0:
            return 0
    return 1  

n =  input()
if isPrime(n):
    print "N"
else:
    print "S"

