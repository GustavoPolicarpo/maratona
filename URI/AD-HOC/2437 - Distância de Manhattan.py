# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Distância de Manhattan
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2437

a, b, c, d = map( int, raw_input().split() )
out = 0
if c > a:
    out = out+c-a
else:
    out = out+a-c
if d > b:
    out = out+d-b
else:
    out = out+b-d
print out
