# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Corredor
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2463

n = input()
v = [0]*(n)
v = map( int, raw_input().split() )

ans = 0
atual = 0

for i in range(n):
    atual = atual + v[i]
    if atual < 0:
        atual = 0
        continue
    if ans < atual:
        ans = atual

print ans
