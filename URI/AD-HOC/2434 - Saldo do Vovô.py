# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Saldo do Vovô
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2434

n, m = map (int, raw_input().split() )
ans = m
for i in range(n):
    aux = input()
    m = m+aux
    if m < ans:
        ans = m
print ans
