# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Corrida
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2435

a, b, c = map (int, raw_input().split() )
d, e, f = map (int, raw_input().split() )
g = float(b)/c
h = float(e)/f
if g<h:
    print a
else:
    print d
