# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Tacógrafo
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2388

n = input()
ans = 0
for i in range(n):
    t, v = map (int, raw_input().split() )
    ans = ans + t * v
print ans


