# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Produto Simples
# Nível: 1
# Categoria: INICIANTE
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1004

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

