# Autor: Gustavo Policarpo<gustavo_votagus@hotmail.com>
# Nome: Vende-se
# Nível: 5
# Categoria: AD-HOC
# URL: https://www.urionlinejudge.com.br/judge/pt/problems/view/2433

n, m = map (int, raw_input().split() )
v = [0]*(n)
v = map (int, raw_input().split() )
v.sort()
ans = 1000010
for i in range(n-(n-m)+1):
    aux = v[i+(n-m)-1]-v[i]
    if aux < 0:
        aux = aux*-1
    if ans > aux:
        ans = aux
print ans
