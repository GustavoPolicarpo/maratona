# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Fatorial Simples
# Nível: 1
# Categoria: INICIANTE
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/1153

n=int(input())
ans=1
for i in range(n):
    ans = ans*(i+1)

print ans

