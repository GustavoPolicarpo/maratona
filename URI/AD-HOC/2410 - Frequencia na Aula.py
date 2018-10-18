# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Frequencia na Aula
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2410

v = [0]*1000010
n = input()
for i in range(n):
    aux = input()
    v[aux] = 1
ans = 0
for i in range(1000010):
    if v[i] == 1:
        ans = ans+1

print ans
