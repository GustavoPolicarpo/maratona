# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Área do Círculo
# Nível: 1
# Categoria: INICIANTE
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1002

import math

area = None
pi = None
r = None

def read_numeric():
  try:
    # read for Python 2.x
    return float(raw_input())
  except NameError:
    # read for Python 3.x
    return float(input())


r = read_numeric()
pi = 3.14159
area = pi * (math.pow(r, 2))
print(str("A=") + str("{:0.4f}".format(area)))

