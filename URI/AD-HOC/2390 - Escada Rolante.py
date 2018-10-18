# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Escada Rolante
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2390

n = input()
ans = n*10
last = -100
for i in range(n):
    atual = input()
    if last + 10 > atual:
        ans = ans - (last + 10 - atual)
    last = atual
print ans

