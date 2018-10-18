# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Carnaval
# Nível: 1
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2418

v = [0]*(5)
v = map (float, raw_input().split() )
v.sort()

sum = v[1] + v[2] + v[3]
sum = round(sum, 1)

print sum

