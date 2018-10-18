# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Desafio do Maior Número
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2414

v = [0]*150
v = map( int, raw_input().split() )

ans = 0
i = 0
while v[i] != 0 :
    ans = max(ans, v[i])
    i = i+1

print ans
