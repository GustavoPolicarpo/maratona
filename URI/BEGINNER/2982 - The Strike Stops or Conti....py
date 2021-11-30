# Author: Gustavo Policarpo
# Name: The Strike Stops or Conti...
# Level: 3
# Category: BEGINNER
# URL: https://www.beecrowd.com.br/judge/en/problems/view/2982

N = int(input())
tt = 0
for i in range(N):
    a, b = input().split()
    if a == 'G':
        tt = tt - int(b)
    else:
        tt = tt + int(b)

if tt < 0:
    print("NAO VAI TER CORTE, VAI TER LUTA!")
else:
    print("A greve vai parar.")
