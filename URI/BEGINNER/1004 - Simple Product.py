# Author: Gustavo Policarpo
# Name: Simple Product
# Level: 1
# Category: BEGINNER
# URL: https://www.beecrowd.com.br/judge/en/problems/view/1004

A = None
B = None

def read_integer():
  try:
    # read for Python 2.x
    return int(raw_input())
  except NameError:
    # read for Python 3.x
    return int(input())


A = read_integer()
B = read_integer()
print(str("PROD = ") + str(A * B))

